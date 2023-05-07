# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slazar <slazar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 07:41:13 by slazar            #+#    #+#              #
#    Updated: 2023/04/17 07:44:10 by slazar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = utiles.c \
		pb.c \
		sa.c \
		sb.c \
		ra.c \
		rb.c \
		ss.c \
		rrr.c \
		rra.c \
		push_swap.c \
		pa.c \
		split.c \

OBJS    =    ${SRCS:.c=.o}
OBJSB    =    ${SRCSB:.c=.o}
NAME    =    push_swap
NAMEBONUS	=
RM    =    rm -rf

%.o : %.c
		${CC} $^ -c -o $@

all: ${NAME}

${NAME}:    ${OBJS}
			@echo "\033[0;32m"
			${CC} push_swap.h ${CFLAGS} ${OBJS} -o ${NAME}

${NAMEBONUS}:	${OBJSB}
			@echo "\033[0;32m"
			${CC} push_swap.h ${CFLAGS} ${OBJSB} -o ${NAMEBONUS}

bonus:     ${NAMEBONUS}

clean:
		@echo "\033[1;31m"
		${RM} ${OBJS} ${OBJSB}

fclean:    clean
			@echo "\033[1;31m"
			${RM} ${NAME} ${NAMEBONUS}

re:        fclean all

.PHONY :clean fclean re bonus 