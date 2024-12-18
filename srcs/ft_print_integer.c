/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:53:10 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/18 23:46:59 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Print %d and %i. Handle `0`, `-`, `+`, and ` ` flag, width, and precision. */
int	ft_print_integer(t_format *tracker, int num)
{
	int		counter;
	char	*num_str;

	if (num == 0 && tracker->dot && tracker->precision == 0) // Edge casee: zero with precision 0
		return (ft_print_padding(tracker->width, ' '));
	num_str = ft_itoa(num);
	if (!num)
		return (-1);
	counter = 0;
	if (tracker->plus && num >= 0)
		counter += ft_putchar_fd('+', 1);
	else if (tracker->space && num >= 0)
		counter += ft_putchar_fd(' ', 1);
	while (counter < tracker->width - (int) ft_strlen(num_str)) //Padding
	{
		if(tracker->zero && !tracker->dot)
			counter += ft_putchar_fd('0', 1);
		else
			counter += ft_putchar_fd(' ', 1);
	}
	counter += ft_putstr_fd(num_str, 1);
	free (num_str);
	return (counter);
}
