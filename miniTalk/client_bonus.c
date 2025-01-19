/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:53:29 by yel-haya          #+#    #+#             */
/*   Updated: 2025/01/19 15:51:07 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	checking(int sign, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (sign == SIGUSR2)
		ft_printf("✅ 	🎉🎉 \033[0;32mSUCCESSFULLY SENT.\033[0m 🎉🎉 	✅\n");
}

static int	spaces_check(const char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '+')
		(*i)++;
	else if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	if (sign == -1 || !ft_isdigit(str[*i]))
	{
		write(1, "NOT A VALID PID!!\n", 18);
		exit(1);
	}
	return (sign);
}

int	my_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;
	long	res2;

	1 && (res = 0, res2 = 0, i = 0, sign = spaces_check(str, &i));
	while (ft_isdigit(str[i]))
	{
		if (res2 > (LONG_MAX - (str[i] - 48)) / 10)
		{
			write(1, "NOT A VALID PID!!\n", 18);
			exit(1);
		}
		res2 = res * 10 + (str[i] - 48);
		i++;
		res = res2;
	}
	if ((str[i] != '\0' && !ft_isdigit(str[i])) || res == 0 || res > 99999)
	{
		write(1, "NOT A VALID PID!!\n", 18);
		exit(1);
	}
	return (((int)res * sign));
}

void	sending_char_by_char(char message_char, int id)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if (message_char & (0b10000000 >> bits))
		{
			if (kill(id, SIGUSR1) < 0)
			{
				ft_printf("Issue with sending a signal!!\n");
				exit(1);
			}
		}
		else
		{
			if (kill(id, SIGUSR2) < 0)
			{
				ft_printf("Issue with sending a signal!!\n");
				exit(1);
			}
		}
		bits++;
		usleep(300);
	}
}

int	main(int ac, char **av)
{
	static pid_t		id;
	char				*message;
	int					i;
	struct sigaction	sa;

	sa.sa_sigaction = checking;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (ac != 3)
		return (ft_printf("Usage: %s <PID> <message>\n", av[0]), 1);
	if (sigaction(SIGUSR2, &sa, NULL) < 0)
	{
		ft_printf("Error with sigaction!\n");
		exit (1);
	}
	id = my_atoi(av[1]);
	message = av[2];
	i = 0;
	while (message[i])
	{
		sending_char_by_char(message[i], id);
		i++;
	}
	sending_char_by_char('\0', id);
	return (0);
}
