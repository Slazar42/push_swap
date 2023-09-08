
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
SRCS = utiles1.c \
		utiles2.c \
		utiles3.c \
		instractions_mandatory1.c\
		instractions_mandatory2.c\
		instractions_mandatory3.c\
		push_swap.c \
		
SRCSB = utiles1.c \
		utiles2.c \
		utiles3.c \
		instractions_bonus1.c\
		instractions_bonus2.c\
		instractions_bonus3.c\
		checker.c \


OBJS    =    ${SRCS:.c=.o}
OBJSB    =    ${SRCSB:.c=.o}
NAME    =    push_swap
NAMEBONUS	= checker
RM    =    rm -rf

%.o : %.c
		${CC} $^ -c -o $@

all: ${NAME}

${NAME}:    ${OBJS}
			@echo "\033[0;32m"
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${NAMEBONUS}:	${OBJSB}
			@echo "\033[0;32m"
			${CC} ${CFLAGS} ${OBJSB} -o ${NAMEBONUS}

bonus:     ${NAMEBONUS}

clean:
		@echo "\033[1;31m"
		${RM} ${OBJS} ${OBJSB}

fclean:    clean
			@echo "\033[1;31m"
			${RM} ${NAME} ${NAMEBONUS}

re:        fclean all

.PHONY :clean fclean re bonus 