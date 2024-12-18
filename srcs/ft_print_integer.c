/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:53:10 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/17 19:53:31 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Print %d and %i. Handle `0`, `-`, `+`, and ` ` flag, width, and precision. */
int	ft_print_integer(t_format *f, int num)
{
	int		counter;
	char	*num_str;

	if (num == 0 && f->dot && f->precision == 0) // Edge casee: zero with precision 0
		return (ft_print_padding(f->width, ' '));
	num_str = ft_itoa(num);
	if (!num)
		return (-1);
	if (f->plus && num >= 0)
		counter += ft_putchar_fd('+', 1);
	else if (f->space && num >= 0)
		counter += ft_putchar_fd(' ', 1);
	while (counter < f ->width - ft_strlen(num_str)) //Padding
	{
		if(f->zero && !f->dot)
			counter += ft_putchar_fd('0', 1);
		else
			counter += ft_putchar_fd(' ', 1);
	}
	counter += ft_putstr_fd(num_str, 1);
	free (num_str);
	return (counter);
}