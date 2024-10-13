# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abastian <abastian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/27 15:44:36 by abastian          #+#    #+#              #
#    Updated: 2024/09/30 12:23:08 by abastian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
HEADER = ft_printf.h
SOURCES = error.c init.c push_swap.c push.c rev_rotate.c rotate.c sort_more.c sort_stack.c swap.c utils.c utils2.c \

OBJECTS = $(SOURCES:.c=.o)
ARG ?=

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C ft_printf
	$(CC) $(CFLAGS) -I. $(OBJECTS) ft_printf/libftprintf.a -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@

run: $(NAME)
	@if [ -z "$(ARG)" ]; then \
		./$(NAME); \
	else \
		./$(NAME) $(ARG); \
	fi

clean:
	@make clean -C ft_printf
	rm -f $(OBJECTS)

fclean: clean
	@make fclean -C ft_printf
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re ft_printf libftprintf
