# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 16:28:04 by chanwopa          #+#    #+#              #
#    Updated: 2022/09/12 19:42:56 by chanwopa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
TARGET = ft_tail
SRCS = ./main.c ./srcs/tail.c ./srcs/ft_func.c ./srcs/tail_stdin.c
OBJS = ./main.o ./srcs/tail.o ./srcs/ft_func.o ./srcs/tail_stdin.o
RM = rm -f
HEAD = ./includes/

${TARGET}: ${SRCS}
	${CC} ${FLAGS} -I ${HEAD} ${SRCS} -o ${TARGET}

all: ${TARGET}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${TARGET}

re: fclean all

.PHONY: all clean fclean re
