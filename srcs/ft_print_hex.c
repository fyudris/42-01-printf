/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:32:26 by fyudris           #+#    #+#             */
/*   Updated: 2025/02/19 16:55:34 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_hex(unsigned long long n, const char *base)
{
	unsigned long long	base_len;
	int					count;

	base_len = ft_strlen(base);
	count = 0;
	if (n >= base_len)
		count += ft_print_hex(n / base_len, base);
	count += write(1, &base[n % base_len], 1);
	return (count);
}
