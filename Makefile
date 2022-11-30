SRCS = ft_printf.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

all: ${NAME}

${NAME}:
	@cd libft/ && $(MAKE) re
	@gcc -Wall -Wextra -Werror -c ${SRCS}
	@ar -rc ${NAME} ${OBJS} libft/libft.a

clean:
	@cd libft/ && $(MAKE) clean
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}
	@cd libft/ && $(MAKE) fclean

re: fclean all
