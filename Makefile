NAME			= push_swap
CHECKER			= checker

SRCS			= srcs/check_arguments.c srcs/count_rotations.c srcs/init_structures.c \
				srcs/main.c srcs/push_operations.c srcs/quick_sort.c srcs/rotate_operations.c \
				srcs/reverse_rotate_operations.c srcs/rotate_stacks.c srcs/sort_many.c \
				srcs/sort_up_to_three.c srcs/sort_up_to_six.c srcs/swap_operations.c srcs/utils.c

SRCS_BONUS		= srcs/check_arguments.c srcs/init_structures.c srcs/main_checker.c srcs/push_operations.c \
				srcs/rotate_operations.c srcs/reverse_rotate_operations.c srcs/swap_operations.c \
				srcs/utils.c srcs/handle_commands.c srcs/quick_sort.c

OBJS			= $(patsubst %.c,%.o,$(SRCS))
OBJS_BONUS		= $(patsubst %.c,%.o,$(SRCS_BONUS))

D_FILES			= $(patsubst %.c,%.d,$(SRCS) $(SRCS_BONUS))

LIB_DIR			= ./libft

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -MMD

all				: ${NAME}

%.o				: %.c
				${CC} ${CFLAGS} -c $< -o $@

${NAME}			: ${OBJS}
				${MAKE} -C ${LIB_DIR}
				${CC} ${CFLAGS} -L${LIB_DIR} -lft ${OBJS} -o ${NAME}

${CHECKER}		: ${OBJS_BONUS}
				${MAKE} -C ${LIB_DIR}
				${CC} ${CFLAGS} -L${LIB_DIR} -lft ${OBJS_BONUS} -o ${CHECKER}

clean			:
				make clean -C ${LIB_DIR}
				@rm -rf ${OBJS} ${OBJS_BONUS} ${D_FILES}

fclean			: clean
				make fclean -C ${LIB_DIR}
				rm -rf ${NAME} ${CHECKER}

re				: fclean all

.PHONY			: all clean fclean re

-include		${D_FILES}