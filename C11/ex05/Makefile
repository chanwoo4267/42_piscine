# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 13:46:50 by chanwopa          #+#    #+#              #
#    Updated: 2022/09/07 18:06:29 by chanwopa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
TARGET = do-op
SRCS = ./srcs/ft_lib.c ./srcs/operator.c ./srcs/m_func.c ./main.c
OBJS = ./srcs/ft_lib.o ./srcs/operator.o ./srcs/m_func.o
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
