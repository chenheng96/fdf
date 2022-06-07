FDF := fdf

LIBFT := libft/libft.a

CC := gcc
CFLAGS := -Wall -Werror -Wextra -fsanitize=address
RM := rm -f

all: ${FDF}

${FDF}: ${LIBFT}
	${CC} ${CFLAGS} -I /usr/local/include ${FDF}.c draw_line.c parse_map.c -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit ${LIBFT} -o ${FDF}

${LIBFT}:
	make -C libft

clean:
	${RM} *.o
	make clean -C libft

fclean:	clean
	${RM} ${FDF}
	make fclean -C libft

re:	fclean all

.PHONY: all bonus clean fclean re
