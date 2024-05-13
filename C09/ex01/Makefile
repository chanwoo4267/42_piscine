# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwopa <chanwopa@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 21:09:45 by chanwopa          #+#    #+#              #
#    Updated: 2022/09/06 15:50:37 by chanwopa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
TARGET = libft.a
OBJS = ./srcs/ft_putchar.o ./srcs/ft_swap.o ./srcs/ft_putstr.o ./srcs/ft_strlen.o ./srcs/ft_strcmp.o
LIB = ar rc
LIBR = ranlib
RM = rm -f
HEAD = ./includes/

all: ${TARGET}

.c.o:
	${CC} ${FLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${TARGET}: ${OBJS}
	${LIB} ${TARGET} ${OBJS}
	${LIBR} ${TARGET}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${TARGET}

re: fclean all

.PHONY: all clean fclean re
