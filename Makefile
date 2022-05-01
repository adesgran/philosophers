NAME = philo

CC = gcc
C_FLAGS = -Wall -Wextra -Werror -pthread

UTILS = $(wildcard utils/*.c)

C_FILES = $(wildcard *.c) ${UTILS}
O_FILES = $(C_FILES:.c=.o)

INCLUDES = -I .

.c.o:
		${CC} ${C_FLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${O_FILES}
		${CC} ${O_FILES} -o ${NAME}

clean:
		rm -r ${O_FILES}

fclean: clean
		rm -r ${NAME}

re: fclean all
