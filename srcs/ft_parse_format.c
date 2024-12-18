/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 00:14:12 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/17 21:54:55 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse_flag(const char *format, t_format *tracker, int idx);
static	int	ft_parse_specifier(const char *format, t_format *tracker, int i, va_list args);
static int	ft_isflag(char c);
static void	ft_set_flag(char c, t_format *tracker);
static int	ft_parse_width(const char *format, t_format *tracker, int i, va_list args);
static int	ft_isdigit(char c);
static int	ft_parse_precision(const char *format, t_format *tracker, int i, va_list args);
static int	ft_is_specifier(char c);

int	ft_parse_format(const char *format, va_list args, t_format *tracker)
{
	int	i; // Index for transversing the format string

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_reset_format_tracker(tracker);
			i = ft_parse_specifier(format, tracker, i, args); // Parse specifier starting at `%`
			if (tracker->specifier)
				tracker->counter += ft_print_args(tracker, tracker->specifier, args);
		}
		else
			tracker->counter += ft_putchar_fd(format[i],1);
		i++;
	}
	return (tracker->counter);
}

/* Parse a single format specifier */
static	int	ft_parse_specifier(const char *format, t_format *tracker, int i, va_list args)
{
	while (format[i]) // Start parsing after `%`
	{
		if(ft_isflag(format[i])){
			ft_set_flag(format[i], tracker); // Handle flags
			i++;
		}
		else if (ft_isdigit(format[i]) || format[i] == '*')
			i = ft_parse_width(format, tracker, i, args);
		else if (format[i] == '.')
			i = ft_parse_precision(format, tracker, i + 1, args);
		else if (ft_is_specifier(format[i]))
		{
			tracker->specifier = format[i];
			return (i + 1); // Move past the specifier and return
		}
		else
			break;
	}
	return (i);
}
static int	ft_isflag(char c)
{
	int	i;

	i = 0;
	while (FLAGS[i])
	{
		if (FLAGS[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/* Sets the flag and resolve conflicts */
static void	ft_set_flag(char c, t_format *tracker)
{
	if (c == '-')
	{
		tracker->minus = 1;
		tracker->zero = 0; // Minus overrides `0`
	}
	else if (c == '0' && !tracker->minus)
		tracker->zero = 1;
	else if (c == '+')
	{
		tracker->plus = 1;
		tracker->space = 0; // Plus overrides space
	}
	else if (c == ' '&& !tracker->plus)
		tracker->space = 1;
	else if (c == '#')
		tracker->hashtag = 1;
}

/* Parse the width (also handles dynamic width with `*`) */
static int	ft_parse_width(const char *format, t_format *tracker, int i, va_list args)
{
	if (format[i] == '*')
	{
		tracker->width = va_arg(args, int);
		if (tracker->width < 0)
		{
			tracker->minus = 1; // Negative width implies left alignment
			tracker->zero = 0;
			tracker->width = -tracker->width;
		}
		return (i + 1);
	}
	while (ft_isdigit(format[i]))
	{
		tracker->width = tracker->width * 10 + (format[i] - '0');
		i++;
	}
	return (i);
}

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_parse_precision(const char *format, t_format *tracker, int i, va_list args)
{
	tracker->dot = 1;
	tracker->precision = 0;
	i++;
	if (format[i] == '*')
	{
		tracker->precision = va_arg(args, int);
		if (tracker->precision < 0)
			tracker->dot = 0; // Negative precision disables precision
		return (i + 1);
	}
	while (ft_isdigit(format[i]))
	{
		tracker->precision = tracker->precision * 10 + (format[i] - '0');
		i++;
	}
	return (i);
}

static int	ft_is_specifier(char c)
{
	int	i;

	i = 0;
	while (SPECIFIERS[i])
	{
		if (SPECIFIERS[i] == c)
			return (1);
		i++;
	}
	return (0);
}