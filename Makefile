NAME = philo

CC = gcc -pthread
C_FLAGS = -Wall -Wextra -Werror 

UTILS = $(wildcard utils/*.c)

C_ROOT = philo routine_philo
C_UTILS = check_all free_table ft_current_time ft_sleep init_table \
		  kill_philo philo_functions print utils1

C_FILES = $(addsuffix .c, $(C_ROOT)) $(addsuffix .c, $(addprefix utils/, $(C_UTILS)))
O_FILES = $(C_FILES:.c=.o)

INCLUDES = -I .

%.o: %.c
	@printf "\033[0;33mGenerating philo objects... %-33.33s\r\033[0m" $@
	@${CC} ${C_FLAGS} ${INCLUDES} -c $< -o $@

all: ${NAME}

${NAME}: ${O_FILES}
	@echo "\n\033[0;34m\nCompiling philo...\033[0m"
	@${CC} ${O_FILES} -o ${NAME}

clean:
	@echo "\n\033[0;31mRemoving binaries...\n\033[0m"
	@rm -f $(O_FILES)

fclean:
	@echo "\n\033[0;31mRemoving binaries...\033[0m"
	@rm -f $(O_FILES)
	@echo "\n\033[0;31mCleaning philo executable...\n\033[0m"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
