/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:51:36 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/18 23:47:56 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Print %s. Handl precision (`.`) and width. */
int	ft_print_str(t_format *tracker, const char *str)
{
	int	counter;
	int	len;
	int	padding;

	if (!str) // Handle null strings
		str = "(null)";
	len = ft_strlen(str);
	if (tracker->dot && tracker->precision < len) // Precision truncates string
		len = tracker->precision;
	padding = 0;
	if (tracker->width > len)
		padding = tracker->width - len;
	counter = 0;
	if (!tracker->minus) // Right-align, print padding first
	{
		while (padding-- > 0)
			counter += ft_putchar_fd(' ', 1);
	}
	counter += write(1, str, len); // Print the string (truncated if needed)
	if (tracker->minus) // Left-align: Print padding after the string
	{
		while (padding-- > 0)
			counter += ft_putchar_fd(' ', 1);
	}
	return (counter);
}