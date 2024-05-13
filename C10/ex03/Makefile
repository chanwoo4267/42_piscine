# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 20:38:45 by chanwopa          #+#    #+#              #
#    Updated: 2022/09/12 22:36:24 by chanwopa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
TARGET = ft_hexdump
SRCS = ./main.c ./srcs/ft_print_memory.c ./srcs/hexdump.c ./srcs/hexdump_stdin.c ./srcs/ft_print_memory_c.c ./srcs/ft_func.c
OBJS = ./main.o ./srcs/ft_print_memory.o ./srcs/hexdump.o ./srcs/hexdump_stdin.o ./srcs/ft_print_memory_c.o ./srcs/ft_func.o
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
