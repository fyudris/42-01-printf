# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fyudris <fyudris@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 22:26:44 by fyudris           #+#    #+#              #
#    Updated: 2024/12/11 22:54:22 by fyudris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =	ft_printf.c

OBJS = $(SRCS:.c=.o)

# Rules
all: $(NAME)

# Compile the library from the mandatory sources
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compile each .c file into .o object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJS)

# Clean up everything, including the library
fclean: clean
	rm -f $(NAME)

# Recompile everything from scratch
re: fclean all

.PHONY: all clean fclean re
