/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 02:05:26 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/18 23:00:38 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	main(void)
{
	char c = 'A';
	char *s = "Hello";
	void *p = (void *)s;
	// int d = -42;
	// int i = 42;
	// unsigned int u = 12345;
	// int x = 255;
	// int X = 255;

	printf("Expected: \n");
	// int counter = printf("char|%-5c|string|%-10s|pointer|%20p|integer|%+08d|integer|% i|hex|%#06x|hex|%#06X|unsigned|%.5u|percent|%%|\n", c, s, p, d, i, x, X, u);
	int counter = printf("|%-5c|%-10s|%20p|", c,s, p);
	printf("\nExpected counter = %d\n", counter);
	printf("\nResult: \n");
	// int mycounter = ft_printf("char|%-5c|string|%-10s|pointer|%20p|integer|%+08d|integer|% i|hex|%#06x|hex|%#06X|unsigned|%.5u|percent|%%|\n", c, s, p, d, i, x, X, u);
	int mycounter = ft_printf("|%-5c|%-10s|%20d|", c, s, 10);
	printf("\nMy counter = %d\n", mycounter);

}