/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 02:05:26 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/19 20:48:13 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	// int counter = printf("char|%-5c|string|%-10s|pointer|%20p|integer|%+08d|integer|% i|hex|%#06x|hex|%#06X|unsigned|%.5u|percent|%%|\n", c, s, p, d, i, x, X, u);
	// char c = 'A';
	// char *s = "Hello";
	// void *p1 = (void *) ULONG_MAX;
	// void *p2 = (void *) -ULONG_MAX;
	// int d = -42;
	// int i = 42;
	// unsigned int u = 12345;
	// int x = 255;
	// int X = 255;

	printf("Expected: \n");
	int counter = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42",
-42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("\nExpected counter = %d\n", counter);

	printf("Result: \n");
	counter = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42",
-42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("\nExpected counter = %d\n", counter);




}

// %p:
// 	TEST(1, print(" %p ", -1));
// 	TEST(2, print(" %p ", 1));
// 	TEST(3, print(" %p ", 15));
// 	TEST(4, print(" %p ", 16));
// 	TEST(5, print(" %p ", 17));
// 	TEST(6, print(" %p %p ", LONG_MIN, LONG_MAX));
// 	TEST(7, print(" %p %p ", INT_MIN, INT_MAX));
// 	TEST(8, print(" %p %p ", ULONG_MAX, -ULONG_MAX));
// 	TEST(9, print(" %p %p ", 0, 0));



