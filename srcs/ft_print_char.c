/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:50:21 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/18 23:45:20 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(t_format *tracker, int c)
{
    int count;

    count = 0;
    c = (char)c; // Cast back to char for clarity
    if (tracker->minus) // Left-align
        count += ft_putchar_fd(c, 1);
    while (count < tracker->width) // Add padding spaces
        count += ft_putchar_fd(' ', 1);
    if (!tracker->minus) // Right-align
        count += ft_putchar_fd(c, 1);
    return (count);
}
