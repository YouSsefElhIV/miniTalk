# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 10:50:14 by yel-haya          #+#    #+#              #
#    Updated: 2025/01/18 13:49:56 by yel-haya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1 = client
NAME_2 = server

NAME_BONUS_1 = client_bonus
NAME_BONUS_2 = server_bonus

CFLAGS = -Wall -Werror -Wextra
SRCC = client.c
SRCS = server.c
SRCCB = client_bonus.c
SRCSB = server_bonus.c
libs = printf/libftprintf.a libft/libft.a
LIB = libft/libft.a
PRI = printf/libftprintf.a

OBJC = $(SRCC:.c=.o)
OBJS = $(SRCS:.c=.o)
OBJBC = $(SRCCB:.c=.o)
OBJBS = $(SRCSB:.c=.o)

mandatory: $(NAME_1) $(NAME_2)

all: $(NAME_1) $(NAME_BONUS_1) $(NAME_2) $(NAME_BONUS_2)

$(NAME_1): $(OBJC) $(libs) ./minitalk.h libft/libft.h printf/ft_printf.h
	$(CC) $(CFLAGS) $(OBJC) -o $(NAME_1) $(LIB) $(PRI)

$(NAME_2): $(OBJS) $(libs)  ./minitalk.h libft/libft.h printf/ft_printf.h
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME_2) $(LIB) $(PRI)

bonus: $(NAME_BONUS_1) $(NAME_BONUS_2)

$(NAME_BONUS_1): $(OBJBC) $(libs) ./minitalk_bonus.h libft/libft.h printf/ft_printf.h
	$(CC) $(CFLAGS) $(OBJBC) -o $(NAME_BONUS_1) $(LIB) $(PRI)

$(NAME_BONUS_2): $(OBJBS) $(libs) ./minitalk_bonus.h libft/libft.h printf/ft_printf.h
	$(CC) $(CFLAGS) $(OBJBS) -o $(NAME_BONUS_2) $(LIB) $(PRI)

$(libs):
	@make -C libft
	@make -C printf

clean:
	@make clean -C libft
	@make clean -C printf
	rm -rf $(OBJC) $(OBJBC) $(OBJBS) $(OBJS)

fclean: clean
	@make fclean -C libft
	@make fclean -C printf
	rm -rf $(NAME_1) $(NAME_2) $(NAME_BONUS_1) $(NAME_BONUS_2)
re: fclean all
.PHONY: clean all fclean re