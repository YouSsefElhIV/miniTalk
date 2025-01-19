/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:53:26 by yel-haya          #+#    #+#             */
/*   Updated: 2025/01/19 15:54:44 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sending_confirmation(pid_t pid)
{
	write(1, "\n", 1);
	if (kill(pid, SIGUSR2) < 0)
	{
		ft_printf("Issue with sending a signal!!\n");
		exit(1);
	}
}

void	handler(int sign, siginfo_t *info, void *context)
{
	static int		bits;
	static char		i;
	static pid_t	pid;
	static pid_t	new_pid;

	if (info->si_pid != 0)
		pid = info->si_pid;
	if (new_pid != 0 && new_pid != pid)
		bits = 0;
	(void)context;
	(void)info;
	if (sign == SIGUSR1)
		i |= (0b10000000 >> bits);
	else if (sign == SIGUSR2)
		i &= ~(0b10000000 >> bits);
	bits++;
	if (bits == 8)
	{
		if (i == '\0')
			sending_confirmation(pid);
		write(1, &i, 1);
		bits = 0;
		i = 0;
	}
	new_pid = pid;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("PID = %i\n", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) < 0)
	{
		ft_printf("Error with sigaction!\n");
		exit (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) < 0)
	{
		ft_printf("Error with sigaction!\n");
		exit (1);
	}
	while (69)
	{
		pause ();
	}
	return (0);
}
