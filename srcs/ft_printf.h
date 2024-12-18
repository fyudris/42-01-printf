/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:51:20 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/18 23:49:16 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h> // TODO: REMOVE

/* Constants */
# define SPECIFIERS "cspdiuxX%"
# define FLAGS		"0# +-"
# define HEX_LOWER	"0123456789abcdef"
# define HEX_UPPER	"0123456789ABCDEF"

/* Struct for Tracking Format Paremeters, Flags, Width, and Precision*/
typedef struct s_format {
	int		counter;	// Tracks the total number of characters printed so far.
	char	specifier;	// Stores the type of the current specifier (e.g. `c`, `s`, etc.)
	int		minus;		// [0;1] Stores whether the `-` flag (left alignment) is active
	int		plus;		// [0;1] stores whether the `+` flag (force sign) is active
						// If 1: Always display sign (+ or -) for numeric type
						// Takes precedence/overwritte ` ` flag
	int		width;		// Specifies the minimum width of the output field
						// If output is shorter -> padded (default with space)
						// If output is longer -> ignored
	int		precision;	// Controls the precision of numeric or string specifiers
						// For numeric: Min number of digits (pads with zeros)
						// For string: Max number of characters
						// Ignored for %c and %%
	int		zero;		// [0;1] Stores wheter the `0` flag (zero-padding) is active
						// Ignored if the `-` flag is also active
						// Precision (e.g. %.5d) can disable zero-padding for numeric types.
	int		dot;		// Indicates the `.` (precision) flag is active
	int		space;		// [0;1] stores wheter the ` ` flag is active
						// If 1: Add space before positive numbers of no `+` is specified
	int		hashtag;	// [0;1] stores wheter the `#` (alternate form) flag is active
}	t_format;

/* Fuction Prototypes */
int			ft_printf(const char *format, ...);

/* Format Parser */
int			ft_parse_format(const char *format, va_list *args, t_format *track_format);

/* Printer Functions */
int			ft_print_args(t_format *tracker, char specifier, va_list *args);
int			ft_print_char(t_format *tracker, int c);
int			ft_print_str(t_format *tracker, const char *str);
int			ft_print_integer(t_format *tracker, int num);
int			ft_print_unsigned(t_format *tracker, unsigned int num);
int			ft_print_hex(t_format *tracker, unsigned int n, char specifier);
int			ft_print_pointer(t_format *tracker, void *ptr);
int			ft_print_percent(t_format *tracker);


/* Initialize and Reset t_format struct */
t_format	ft_new_track_format();
void		ft_reset_format_tracker(t_format *tracker);
int			ft_print_padding(int width, char pad_char);

/* Helper Functions */
int			ft_putchar_fd(char c, int fd);
int			ft_putstr_fd(char *s, int fd);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *s);
char		*ft_utoa_base(unsigned int n, char *base);
char		*ft_itoa(int n);

#endif
