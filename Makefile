NAME			= minishell.a

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

LIBFT 			= ./libraries/Libft

LIBFT_NAME		= libft.a

CC 				= cc

AR				= ar rc

STANDARD_FLAGS 	= -Wall -Werror -Wextra -lreadline -fsanitize=address

RM 				= rm -rf

SRCS_DIR		= ./sources/

BUILT_IN		=	$(addprefix ./sources/built_in/,\
					s_cd.c\
					s_echo.c\
					s_env.c\
					s_exit.c\
					s_export.c\
					s_pwd.c\
					s_unset.c)

SRCS 			=	$(addprefix $(SRCS_DIR),\
					builtin_change.c \
					s_minishell.c \
					s_token.c)

OBJS		= ${SRCS:.c=.o} ${BUILT_IN:.c=.o}

all:		${NAME} run
			
makelibft:
			make -C ${LIBFT}
			cp ${LIBFT}/${LIBFT_NAME} .
			mv ${LIBFT_NAME} ${NAME}

${NAME}:	makelibft ${OBJS}
			${AR} ${NAME} ${OBJS}
clean:		
			${RM} ${OBJS}
			@cd $(LIBFT) && make clean

fclean:		clean
			${RM} ${NAME}
			${RM} minishell
			${RM} a.out
			@cd $(LIBFT) && make fclean

re:			fclean all

run:		${NAME}
			${CC} ${NAME} ${LIBFT}/${LIBFT_NAME} ${STANDARD_FLAGS} -o minishell

.PHONY:			all clean fclean re  run