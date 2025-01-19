/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 22:14:34 by yel-haya          #+#    #+#             */
/*   Updated: 2024/11/13 20:33:32 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr(unsigned long n)
{
	int		count;
	char	*sym;

	sym = "0123456789abcdef";
	if (n < 0)
	{
		put_char('-');
		return (ft_putptr(-n) + 1);
	}
	else if (n < 16)
		return (put_char(sym[n]));
	else
	{
		count = ft_putptr(n / 16);
		return (count + ft_putptr((n % 16)));
	}
}

int	put_ptr(void *ptr)
{
	int				count;
	unsigned long	n;

	n = (unsigned long) ptr;
	count = 0;
	count += put_str("0x");
	if (ptr == 0)
		count += put_char('0');
	else
		count += ft_putptr(n);
	return (count);
}
