/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:47:34 by yel-haya          #+#    #+#             */
/*   Updated: 2024/11/09 17:11:08 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cases_printing(char form, va_list ap)
{
	int	count;

	count = 0;
	if (form == '%')
		count += put_char('%');
	else if (form == 'c')
		count += put_char(va_arg(ap, int));
	else if (form == 's')
		count += put_str(va_arg(ap, char *));
	else if (form == 'd' || form == 'i')
		count += ft_putnbr((long)va_arg(ap, int), 10, 0);
	else if (form == 'x')
		count += ft_putnbr((long)va_arg(ap, unsigned int), 16, 0);
	else if (form == 'X')
		count += ft_putnbr((long)va_arg(ap, unsigned int), 16, 1);
	else if (form == 'u')
		count += ft_putnbr((long)va_arg(ap, unsigned int), 10, 0);
	else if (form == 'p')
		count += put_ptr(va_arg(ap, void *));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	va_start(args, format);
	count = 0;
	if (write(1, 0, 0) == -1)
		return (-1);
	while (*format)
	{
		if (*format == '%')
			count += cases_printing(*(++format), args);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
