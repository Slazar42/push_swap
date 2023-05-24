

CFLAGS = -Wall -Wextra -Werror
SRCS = utiles.c \
		sa.c \
		push_swap.c \
		
SRCSB = utiles.c \
		ra.c\
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