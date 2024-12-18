/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:51:36 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/17 22:04:29 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Print %s. Handl precision (`.`) and width. */
int	ft_print_str(t_format *f, char *str)
{
	int	counter;
	int	len;

	if (!str) // Handle null strings
		str = "(null)";
	len = ft_strlen(str);
	if (f->dot && f->precision < len) // Precision truncates string
		len = f->precision;
	counter = len;
	if (!f->minus) // Right-align
		while (counter < f->width)
			counter += ft_putchar_fd(' ', 1);
	write (1, str, len);
	if (f->minus) // Left-align
		while (counter < f->width)
			counter += ft_putchar_fd(' ', 1);
	return (counter);
}