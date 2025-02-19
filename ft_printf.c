/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:03:34 by fyudris           #+#    #+#             */
/*   Updated: 2025/02/19 18:22:11 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief
 *
 * @param
 * @return
 */
int	ft_handle_format(char specifier, va_list args)
{
	// write(1, "OMGWUT", 6);
	printf("Specifier %c\n", specifier);

	if (specifier == 's')
		printf("TRUE");
	else
		printf("FALSE");

	if (specifier == '%')
		return (ft_print_char('%'));
	else if (specifier == 'c')
		return (ft_print_char((char)va_arg(args, int)));
	else if (specifier == 's')
	{
		printf("PRINTING S");
		return (ft_print_str(va_arg(args, char *)));
	}
	else if (specifier == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_int(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_print_unsigned_int(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), HEX_LOWER));
	else if (specifier == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), HEX_UPPER));
	else
		return (ft_print_char(specifier));
}

/**
 * @brief
 * %[parameter][flags][width][.precision][length]type
 * @param
 * @return
 */
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
		return (0);
	va_start(args, format);
	i = 0;
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count += ft_handle_format(*(format), args);
			printf("Count: %i\n",count);
			format++;
		}
		else
		{
			count += ft_print_char(*(format));
			format++;
		}
	}
	va_end(args);
	return (count);
}
