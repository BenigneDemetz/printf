SRCS = ft_printf.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

all: ${NAME}

${NAME}:
	@cd libft/ && $(MAKE)
	@gcc -Wall -Wextra -Werror -c ${SRCS}
	@ar -rc ${NAME} *.o

bonus:
	@gcc -Wall -Wextra -Werror -c ${SRCS} ${BNSSRCS}
	@ar -rc libft.a *.o

clean:
	@cd libft/ && $(MAKE) clean
	@rm -f ${OBJS} ${OBJS_B}

fclean: clean
	@rm -f ${NAME}
	@cd libft/ && $(MAKE) fclean

re: fclean all
