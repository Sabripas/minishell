NAME			= minishell

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
					cd.c\
					echo.c\
					env.c\
					exit.c\
					export.c\
					pwd.c\
					unset.c)

SRCS 			=	$(addprefix $(SRCS_DIR),\
					atom.c \
					level.c\
					minishell.c \
					pars.c \
					token.c \
					utilises.c)

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
			${RM} a.out
			@cd $(LIBFT) && make fclean

re:			fclean all

run:		${NAME}
			${CC} ${NAME} ${LIBFT}/${LIBFT_NAME} ${STANDARD_FLAGS} -o ${NAME}

.PHONY:			all clean fclean re  run