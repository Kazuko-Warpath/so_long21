NAME = libftprintf.a

HEADER = ft_printf.h


SRC = ft_printf.c ft_printf_abc.c ft_printf_dec.c ft_printf_hex.c ft_printf_ptr.c ft_printf_uns_dec.c ft_printf_utils.c

OBJ = ${SRC:.c=.o}

.phony: all clean re fclean bonus

all: ${LIBFT} ${NAME} 

${NAME}: ${OBJ} ${HEADER}
	ar rc ${NAME} $? ${OBJ} 
	

${OBJ}: ${HEADER}
	gcc -Wall -Werror -Wextra -c ${SRC}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

