FDF		= fdf
SRCS	= ft_mat_mul.c #fdf.c draw_line.c parse_map.c

CC		= gcc
CFLAGS	= -fsanitize=address -g3 -Wall -Werror -Wextra

INCLUDE = -Iinclude -Ilibft #/usr/local/include
LDFLAGS = -Llibft #/usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
LDLIBS	= -lft #-lm

LIBFT	= libft/libft.a

OBJS	= ${SRCS:.c=.o}

all: 	${FDF}

${FDF}: ${LIBFT} ${OBJS}
		${CC} ${CFLAGS} -o ${FDF} ${INCLUDE} ${LDFLAGS} ${LDLIBS}

${LIBFT}:
		make -C libft

clean:
		${RM} *.o
		make clean -C libft

fclean:	clean
		${RM} ${FDF}
		make fclean -C libft

re:		fclean all

matrix:	${LIBFT}
		${CC} matrix_multiplication.c test_matrix_multiplication.c matrix_helper.c fdf_helper.c -o matrix ${CFLAGS} ${INCLUDE} -Llibft -lft
		./matrix
		${RM} matrix

parse:	${LIBFT}
		${CC} parse_map.c test_parse_map.c matrix_multiplication.c matrix_helper.c fdf_helper.c -o parse ${CFLAGS} ${INCLUDE} -Llibft -lft
		./parse
		${RM} parse

norm:
		norminette *.c *.h

.PHONY: all clean fclean re libft norm matrix parse
