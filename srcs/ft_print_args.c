/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:21:02 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/18 23:11:17 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Main function to dispatch the argument to the correct subfunction based on the specifier. */

int	ft_print_args(t_format *tracker, char specifier, va_list *args)
{
	int	counter;

	counter = 0;
	if (specifier == 'c')
		counter = ft_print_char(tracker, va_arg(*args, int)); // char is promotetd to int
	else if (specifier == 's')
	{
		// va_arg(*args,char *);
		counter = ft_print_str(tracker, va_arg(*args, const char *));
	}
	else if (specifier == 'd' || specifier == 'i')
		counter = ft_print_integer (tracker, va_arg(*args, int));
	else if (specifier == 'u')
		counter = ft_print_unsigned(tracker, va_arg(*args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		counter = ft_print_hex(tracker, va_arg(*args, unsigned int), specifier);
	else if (specifier == 'p')
		counter = ft_print_pointer(tracker, va_arg(*args, void *));
	else if (specifier == '%')
		counter = ft_print_percent(tracker);
	if (counter == -1)
		return (-1);
	return (counter);
}







