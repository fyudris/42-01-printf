/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:44:41 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/18 14:08:13 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_pointer(t_format *f, void *ptr)
{
	int			count;
	char		*hex_str;
	uintptr_t	addr;

	count = 0;
	addr = (uintptr_t)ptr;
	if (!ptr)
		return (ft_putstr_fd("0x0", 1));
	hex_str = ft_utoa_base(addr, HEX_LOWER);
	if (!hex_str)
		return (-1);
	// Handle right padding
	if (!f->minus && f->width > ((int)ft_strlen(hex_str) + 2))
		count += ft_print_padding(f->width - ((int)ft_strlen(hex_str) + 2), ' ');
	// Print prefix
	count += ft_putstr_fd("0x", 1);
	// Print the hex string
	count += ft_putstr_fd(hex_str, 1);
	// Handle left padding
	if (f->minus && f->width > ((int)ft_strlen(hex_str) + 2))
		count += ft_print_padding(f->width - ((int)ft_strlen(hex_str) + 2), ' ');
	free(hex_str);
	return (count);
}