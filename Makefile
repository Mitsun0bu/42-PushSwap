# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 11:59:53 by llethuil          #+#    #+#              #
#    Updated: 2021/12/14 15:44:41 by llethuil         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_AR =	./libft/libft.a \

INCS = 		./includes/push_swap.h \

SRCS = 		./srcs/algos.c \
			./srcs/double_operations.c \
			./srcs/parsing.c \
			./srcs/push_swap.c \
			./srcs/simple_operations.c \
			./srcs/utils.c \
			./srcs/utils_2.c \

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -I ${INCS}

RM = rm -f

all : libft ${NAME}

libft:
	make -C ./libft

%.o: %.c ${INCS}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS} ${LIBFT_AR}
	${CC} ${OBJS} ${LIBFT_AR} -o ${NAME}

clean:
	${RM} ${OBJS}
	make clean -C ./libft

fclean: clean
	${RM} ${LIBFT_AR}
	${RM} ${NAME}

re: fclean all

.PHONY: all libft clean fclean re