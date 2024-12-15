/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:03:34 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/15 02:44:31 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*********************************************
 * NAME
 *	ft_printf -- write output to the standard output stream (stdout).
 * 
 * PROTOTYP
 *	int	ft_printf(const char *format, ...)
 *
 * DESCRIPTION
 *	The function in the printf() family produce output according to a format.
 *
 * RETURN VALUE
 *	Returns the number of characters printed (excluding the null byte used 
 *	to terminate the string.)
 *
 * NOTES
 *	Look at the elipsis ("...") in the functin prototype.
 *	This means that ft_printf() is a variadic function.
 *********************************************/
int	ft_printf(const char *format, ...)
{
	int		counter;
	va_list	args;
	char	*specifier_start;

	counter = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			specifier_start = (char *)format;
			// Check for specifier
			if (*(++format))
				counter += ft_parse_format(format, ap); // TODO: Implement

			// If specifier exist, but not part of valid specifiers, search further
			while (*format && !ft_strchr(SPECIFIERS, format)) // TODO: Implement
				++format;

			// Search other specifiers, fall back to start if non-exist/null terminator
			if (!(*format))
				format = specifier_start;
		}
		else
			counter += ft_putchar_fd(*format, 1); // TODO: Implement
		if (*format) //TEST: Remove, cause segfault?
			++format;
	}
}

int	ft_parse_format(char *format, va_list args)
{

}
