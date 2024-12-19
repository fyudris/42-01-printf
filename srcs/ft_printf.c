/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:03:34 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/19 20:55:23 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Main Function */
int	ft_printf(const char *format, ...)
{
	va_list		args;
	char		*str_format;
	t_format	track_format;

	if (!format || *format == '\0')
		return (0);
	track_format = ft_new_track_format();
	str_format = ft_strdup(format);
	if (!str_format)
		return (0);
	va_start(args, format);
	ft_parse_format(format, &args, &track_format);
	va_end(args);
	free(str_format);
	return (track_format.counter);
}
