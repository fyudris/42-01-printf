/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 02:05:26 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/17 02:01:27 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void){
	char c = 'A';
	char *s = "Hello";
	void *p = (void *)s;
	int d = -42;
	int i = 42;
	unsigned int u = 12345;
	int x = 255;
	int X = 255;

	printf("Expected: \n");
	int counter = printf("|%-5c|%-10s|%20p|%+08d|% i|%#06x|%#06X|%.5u|%%|\n",
		c, s, p, d, i, x, X, u);

	printf("\nResult: \n");
	int mycounter = ft_printf("|%-5c|%-10s|%20p|%+08d|% i|%#06x|%#06X|%.5u|%%|\n",
		c, s, p, d, i, x, X, u);

	printf("\nExpected counter = %d\n", counter);
	printf("\nMy counter = %d\n", mycounter);

	// printf("\nTEST: |%d", 42);

	// Expected output:
	// |A    |Hello     |         0x102507f70|-0000042| 42|0x00ff|0X00FF|12345|%|
}