/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 00:14:12 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/16 02:17:30 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_format(const char *format, va_list args, t_format *track_format)
{
	int	i;
	int	spec_end; // Tracks where the current specifier ends in the format string.

	i = 0;
	while (format[i])
	{

		if (format[i] != '%')
			track_format->counter += ft_putchar_fd(format[i],1);
		i++;
	}
	return (track_format->counter);
}