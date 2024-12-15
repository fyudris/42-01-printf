/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:51:20 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/15 02:11:33 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

/* Constants */
# define SPECIFIERS "cspdiuxX%"
# define HEX_LOWER	"0123456789abcdef"
# define HEX_UPPER	"0123456789ABCDEF"

/* Struct for Tracking Format Flags, Width, and Precision*/
typedef struct s_format {
	char	specifier;
	int		minus;
	int		plus;
	int		width;
	int		precision;
	int		negative_precision;
	int		zero;
	int		dot;
	int		space;
	int		hashtag;
}	t_format;

/*Fuction Prototypes*/

#endif

