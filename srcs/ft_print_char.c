/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:50:21 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/18 20:27:47 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(t_format *p, int c)
{
    int count;

    count = 0;
    c = (char)c; // Cast back to char for clarity
    if (p->minus) // Left-align
        count += ft_putchar_fd(c, 1);
    while (count < p->width) // Add padding spaces
        count += ft_putchar_fd(' ', 1);
    if (!p->minus) // Right-align
        count += ft_putchar_fd(c, 1);
    return (count);
}
