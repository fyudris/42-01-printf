/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:03:34 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/11 23:13:11 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/********************************************
* Pseudo-Code
* 1. ft_printf function will write each character of the initial string, one by
* one, until it finds a `%`.
* 2. When it finds a `%`, it will look at the elemen in the next index 
* position. It will find the character that will define the type of the first
* argument.
* 3. Depending on what it finds, it will call a method that will display the
* argument of the particular type at output.
*		-> If there's a `s`, then call a funtion to display strings.
*		-> If there's a `d`, then call a funtion to display numbers.
*		etc.
* 4. Once the first variable argument has been written, you go back to step 1,
* until the string is finished (a.k.a until you find a null terminator \0).
* 5. Count the number of characters printer each time, in order to return the
* final number of characters at the end of the funtion.
*********************************************/

int	ft_printf(const char *, ...)
{
	// TODO: Read about variadic functions
}

