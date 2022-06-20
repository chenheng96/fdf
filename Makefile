FDF		= fdf
SRCS	= ft_mat_mul.c #fdf.c draw_line.c parse_map.c

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -fsanitize=address -g

INCLUDE = -Iinclude -Ilibft #/usr/local/include
LDFLAGS = -Llibft #/usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
LDLIBS	= -lft -lm

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

norm:
		norminette *.c *.h

.PHONY: all clean fclean re matrix affine libft norm
