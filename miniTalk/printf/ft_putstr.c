/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:55:56 by yel-haya          #+#    #+#             */
/*   Updated: 2024/11/08 14:56:56 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_str(char *st)
{
	int	count;

	count = 0;
	if (!st)
		return (write(1, "(null)", 6));
	else
	{
		while (*st)
		{
			put_char((int)*st);
			count++;
			st++;
		}
	}
	return (count);
}
