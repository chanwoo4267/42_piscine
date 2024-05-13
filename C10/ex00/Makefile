# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 11:49:02 by chanwopa          #+#    #+#              #
#    Updated: 2022/09/08 12:42:18 by chanwopa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
TARGET = ft_display_file
SRCS = ./main.c
OBJS = ./main.o
RM = rm -f

${TARGET}: ${SRCS}
	${CC} ${FLAGS} ${SRCS} -o ${TARGET}

all: ${TARGET}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${TARGET}

re: fclean all

.PHONY: all clean fclean re
