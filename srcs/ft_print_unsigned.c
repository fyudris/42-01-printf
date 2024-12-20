/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:01:29 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/18 23:51:31 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_utoa(unsigned int num);

int	ft_print_unsigned(t_format *tracker, unsigned int num)
{
	int		counter;
	char	*num_str;
	int		len;

	counter = 0;
	if (num == 0 && tracker->dot && tracker->precision == 0)
		return (ft_print_padding(tracker->width, ' '));
	num_str = ft_utoa(num);
	if (!num_str)
		return (-1);
	len = ft_strlen(num_str);
	if (tracker->dot && tracker->precision > len)
		counter += ft_print_padding(tracker->precision - len, '0');
	if (!tracker->minus && tracker->width > len + counter)
	{
		if (tracker->zero && !tracker->dot)
			counter += ft_print_padding(tracker->width - len - counter, '0');
		else
			counter += ft_print_padding(tracker->width - len - counter, ' ');
	}
	counter += ft_putstr_fd(num_str, 1);
	if (tracker->minus && tracker->width > len + counter)
		counter += ft_print_padding(tracker->width - len - counter, ' ');
	free (num_str);
	return (counter);
}

static char	*ft_utoa(unsigned int num)
{
	char			*str;
	unsigned int	temp;
	int				len;

	temp = num;
	len = 1;
	while (temp >= 10)
	{
		temp /= 10;
		len++;
	}
	str = (char *) malloc ((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
