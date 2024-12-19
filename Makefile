# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fyudris <fyudris@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 22:26:44 by fyudris           #+#    #+#              #
#    Updated: 2024/12/19 20:41:33 by fyudris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME		=	libftprintf.a
CC			=	cc
# TODO: REMOVE -g flag
CFLAGS		=	-Wall -Wextra -Werror -g
SRC_DIR		=	srcs
SRCS_FILES	=	ft_printf.c\
				ft_itoa.c\
				ft_parse_format.c\
				ft_print_args.c\
				ft_print_char.c\
				ft_print_hex.c\
				ft_print_integer.c\
				ft_print_percent.c\
				ft_print_pointer.c\
				ft_print_str.c\
				ft_print_unsigned.c\
				ft_printf_utils.c\
				ft_utoa_base.c

SRCS		=	$(addprefix $(SRC_DIR)/, $(SRCS_FILES))

#TEST_SRC = srcs/main.c
#TEST_EXEC = test_main

# Header file
HEADER		=	$(SRC_DIR)/ft_printf.h


OBJS = $(SRCS:.c=.o)

# Rules
all: $(NAME)

# Compile the library from the mandatory sources
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compile each .c file into .o object files
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Test target (compile main.c with the library into an executable)
#test: $(NAME)
#	$(CC) $(CFLAGS) $(TEST_SRC) -o $(TEST_EXEC) $(NAME)

bonus: $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Clean up object files
clean:
	rm -f $(OBJS)

# Clean up everything, including the library
fclean: clean
	rm -f $(NAME)

# Recompile everything from scratch
re: fclean all

.PHONY: all clean fclean re
