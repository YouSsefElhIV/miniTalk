/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 22:23:52 by yel-haya          #+#    #+#             */
/*   Updated: 2024/11/08 15:55:00 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n, int base, int low_or_up)
{
	int		count;
	char	*sym;
	char	*sym_up;

	sym = "0123456789abcdef";
	sym_up = "0123456789ABCDEF";
	if (n < 0)
	{
		put_char('-');
		return (ft_putnbr(-n, base, low_or_up) + 1);
	}
	else if (n < base)
	{
		if (low_or_up == 0)
			return (put_char(sym[n]));
		else
			return (put_char(sym_up[n]));
	}
	else
	{
		count = ft_putnbr(n / base, base, low_or_up);
		return (count + ft_putnbr((n % base), base, low_or_up));
	}
}
