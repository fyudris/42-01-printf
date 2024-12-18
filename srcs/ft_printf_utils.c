/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 02:41:49 by fyudris           #+#    #+#             */
/*   Updated: 2024/12/18 22:46:12 by fyudris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	return ((int)write(fd, &c, 1));
}

int	ft_putstr_fd(char *s, int fd)
{
	int	count;
	if (!s)
		return (0);
	count = 0;
	while (s[count])
		count++;
	write(fd, s, count);
	return (count);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char) c;
	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == cc)
			return ((char *) &str[i]);
		i++;
	}
	if (str[i] == cc)
		return ((char *) &str[i]);
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	dup = (char *) malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;

	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

t_format	ft_new_track_format()
{
	t_format	tracker;

	tracker.counter = 0;
	tracker.specifier = 0;
	tracker.minus = 0;
	tracker.plus = 0;
	tracker.width = 0;
	tracker.precision = -1;
	tracker.zero = 0;
	tracker.dot = 0;
	tracker.space = 0;
	tracker.hashtag = 0;
	return (tracker);
}

void	ft_reset_format_tracker(t_format *tracker)
{
	tracker->specifier = 0;
	tracker->minus = 0;
	tracker->plus = 0;
	tracker->width = 0;
	tracker->precision = -1;
	tracker->zero = 0;
	tracker->dot = 0;
	tracker->space = 0;
	tracker->hashtag = 0;
}



/* Handles generic padding. */
int	ft_print_padding (int width, char pad_char)
{
	int	counter;

	counter = 0;
	while (counter < width)
		counter += ft_putchar_fd(pad_char, 1);
	return (counter);
}