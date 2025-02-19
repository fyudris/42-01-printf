/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:37:59 by fyudris           #+#    #+#             */
/*   Updated: 2025/02/19 16:54:36 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_pointer(void *ptr)
{
	unsigned long long	address;
	int					count;

	address = (unsigned long long)ptr;
	if (address == 0)
		return (write(1, "0x0", 3));
	count = write(1, "0x", 2);
	count += ft_print_hex(address, HEX_LOWER);
	return (count);
}
