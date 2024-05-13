# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 11:51:24 by chanwopa          #+#    #+#              #
#    Updated: 2022/09/08 14:43:53 by chanwopa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
TARGET = ft_cat
SRCS = ./main.c ./srcs/cat.c
OBJS = ./main.o ./srcs/cat.o
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
