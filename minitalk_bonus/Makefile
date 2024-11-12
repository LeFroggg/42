# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abastian <abastian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/27 15:44:36 by abastian          #+#    #+#              #
#    Updated: 2024/11/04 16:52:19 by abastian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
SERV_SRC = server.c utils.c
CLIE_SRC = client.c

SERV_OBJ = $(SERV_SRC:.c=.o)
CLIE_OBJ = $(CLIE_SRC:.c=.o)

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(SERV_OBJ)
	@make -C ft_printf
	$(CC) $(CFLAGS) -I. $(SERV_OBJ) ft_printf/libftprintf.a -o $(SERVER)

$(CLIENT): $(CLIE_OBJ)
	@make -C ft_printf
	$(CC) $(CFLAGS) -I. $(CLIE_OBJ) ft_printf/libftprintf.a -o $(CLIENT)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	@make clean -C ft_printf
	rm -f $(SERV_OBJ) $(CLIE_OBJ)

fclean: clean
	@make fclean -C ft_printf
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re ft_printf libftprintf
