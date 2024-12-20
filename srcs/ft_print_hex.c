/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:54:21 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/19 20:57:52 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_hex_str(char specifier, unsigned int n);
static int	ft_get_prefix_len(t_format *tracker, unsigned int num);
static int	ft_print_hex_prefix(t_format *tracker, unsigned int num,
				char specifier);
static int	ft_print_hex_right_padding(t_format *tracker, int len,
				int prefix_len);
static int	ft_print_hex_precision_padding(int precision, int len);

int	ft_print_hex(t_format *tracker, unsigned int n, char specifier)
{
	int		len;
	int		count;
	int		prefix_len;
	char	*num_str;

	count = 0;
	if (n == 0 && tracker->dot && tracker->precision == 0)
		return (ft_print_padding(tracker->width, ' '));
	num_str = get_hex_str(specifier, n);
	if (!num_str)
		return (-1);
	len = ft_strlen(num_str);
	prefix_len = ft_get_prefix_len(tracker, n);
	if (!tracker->minus && tracker->width > (len + prefix_len))
		count += ft_print_hex_right_padding(tracker, len, prefix_len);
	count += ft_print_hex_prefix(tracker, n, specifier);
	count += ft_print_hex_precision_padding(tracker->precision, len);
	count += ft_putstr_fd(num_str, 1);
	if (tracker->minus && tracker->width > (len + prefix_len))
		count += ft_print_padding(tracker->width - len - prefix_len, ' ');
	free(num_str);
	return (count);
}

static char	*get_hex_str(char specifier, unsigned int n)
{
	if (specifier == 'x')
		return (ft_utoa_base(n, HEX_LOWER));
	else
		return (ft_utoa_base(n, HEX_UPPER));
}

static int	ft_get_prefix_len(t_format *tracker, unsigned int num)
{
	if (tracker->hashtag && num != 0)
		return (2);
	return (0);
}

static int	ft_print_hex_prefix(t_format *f, unsigned int num, char specifier)
{
	if (f->hashtag && num != 0)
	{
		if (specifier == 'x')
			return (ft_putstr_fd("0x", 1));
		else
			return (ft_putstr_fd("0X", 1));
	}
	return (0);
}

static int	ft_print_hex_right_padding(t_format *tracker, int len,
	int prefix_len)
{
	int	counter;

	counter = 0;
	if (!tracker->minus && tracker->width > len + prefix_len)
	{
		if (tracker->zero && !tracker->dot)
			counter += ft_print_padding(tracker->width - len - prefix_len, '0');
		else
			counter += ft_print_padding(tracker->width - len - prefix_len, ' ');
	}
	return (counter);
}

static int	ft_print_hex_precision_padding(int precision, int len)
{
	int	counter;

	counter = 0;
	while (precision > len)
	{
		counter += ft_putchar_fd('0', 1);
		precision--;
	}
	return (counter);
}
