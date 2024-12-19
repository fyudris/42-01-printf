/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:49:28 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/18 23:47:11 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(t_format *tracker)
{
	int	count;

	count = 0;
	if (tracker->minus)
		count += ft_putchar_fd('%', 1);
	while (count < tracker->width - 1)
		count += ft_putchar_fd(' ', 1);
	if (!tracker->minus)
		count += ft_putchar_fd('%', 1);
	return (count);
}
