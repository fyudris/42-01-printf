/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:51:20 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/19 21:01:14 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <stdio.h> // TODO: REMOVE

/* Constants */
# define SPECIFIERS "cspdiuxX%"
# define FLAGS		"0# +-"
# define HEX_LOWER	"0123456789abcdef"
# define HEX_UPPER	"0123456789ABCDEF"

/* Struct for Tracking Format Paremeters, Flags, Width, and Precision*/
typedef struct s_format {
	int		counter;
	char	specifier;
	int		minus;
	int		plus;
	int		width;
	int		precision;
	int		zero;
	int		dot;
	int		space;
	int		hashtag;
}	t_format;

/* Fuction Prototypes */
int			ft_printf(const char *format, ...);

/* Format Parser */
int			ft_parse_format(const char *format, va_list *args,
				t_format *track_format);

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
t_format	ft_new_track_format(void);
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
