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

leaks: all
	PHILO_INPUT="2 200 200 200"
	echo "Input $(PHILO_INPUT)"
	valgrind ./philo $(PHILO_INPUT)
	PHILO_INPUT="4 200 200 200"
	echo "Input ${PHILO_INPUT}"
	valgrind ./philo ${PHILO_INPUT}
	PHILO_INPUT="1 200 200 200"
	echo "Input ${PHILO_INPUT}"
	valgrind ./philo ${PHILO_INPUT}
	PHILO_INPUT="0 200 200 200"
	echo "Input ${PHILO_INPUT}"
	valgrind ./philo ${PHILO_INPUT}
	PHILO_INPUT="4 -200 200 200"
	echo "Input ${PHILO_INPUT}"
	valgrind ./philo ${PHILO_INPUT}
	PHILO_INPUT="4 200 200 200 20"
	echo "Input ${PHILO_INPUT}"
	valgrind ./philo ${PHILO_INPUT}
	PHILO_INPUT="4 200a 200 200"
	echo "Input ${PHILO_INPUT}"
	valgrind ./philo ${PHILO_INPUT}
