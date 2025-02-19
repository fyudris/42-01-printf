/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:24:54 by fyudris           #+#    #+#             */
/*   Updated: 2025/02/19 16:53:50 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_int(int n)
{
	int		count;
	char	c;

	if (n == INT_MIN)
		return (write(1, "-2147483648", 11));
	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		count += ft_print_int(n / 10);
	c = (n % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}
