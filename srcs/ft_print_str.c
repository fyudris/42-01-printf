/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:51:36 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/19 20:58:59 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Print %s. Handl precision (`.`) and width. */
int	ft_print_str(t_format *tracker, const char *str)
{
	int	counter;
	int	len;
	int	padding;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (tracker->dot && tracker->precision < len)
		len = tracker->precision;
	padding = 0;
	if (tracker->width > len)
		padding = tracker->width - len;
	counter = 0;
	if (!tracker->minus)
	{
		while (padding-- > 0)
			counter += ft_putchar_fd(' ', 1);
	}
	counter += write(1, str, len);
	if (tracker->minus)
	{
		while (padding-- > 0)
			counter += ft_putchar_fd(' ', 1);
	}
	return (counter);
}
