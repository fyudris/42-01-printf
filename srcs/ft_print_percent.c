/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:49:28 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/17 19:49:40 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(t_format *p)
{
	int count;

	count = 0;
	if (p->minus)
		count += ft_putchar_fd('%', 1);
	while (count < p->width - 1)
		count += ft_putchar_fd(' ', 1);
	if (!p->minus)
		count += ft_putchar_fd('%', 1);
	return (count);
}