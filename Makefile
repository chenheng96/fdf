FDF		= fdf
SRCS	= fdf.c affine_rotation.c affine_transformation.c draw_line.c fdf_helper.c matrix_helper.c matrix_multiplication.c parse_map.c parse_map_helper.c

CC		= gcc
CFLAGS	= -fsanitize=address -g3 #-Wall -Werror -Wextra

INCLUDE = -Iinclude -Ilibft -I/usr/local/include
LDFLAGS = -Llibft -L/usr/local/lib/
LDLIBS	= -lft -lm -lmlx -framework OpenGL -framework AppKit

LIBFT	= libft/libft.a

OBJS	= ${SRCS:.c=.o}

all: 	${FDF}

${FDF}: ${LIBFT} ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${FDF} ${INCLUDE} ${LDFLAGS} ${LDLIBS}

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
		${CC} matrix_multiplication.c test_matrix_multiplication.c matrix_helper.c fdf_helper.c -o matrix ${CFLAGS} ${INCLUDE} ${LDFLAGS} ${LDLIBS}
		./matrix
		${RM} matrix

parse:	${LIBFT}
		${CC} parse_map.c test_parse_map.c matrix_multiplication.c affine_rotation.c matrix_helper.c parse_map_helper.c fdf_helper.c -o parse ${CFLAGS} ${INCLUDE} ${LDFLAGS} ${LDLIBS}
		./parse
		${RM} parse

norm:
		norminette *.c *.h

.PHONY: all clean fclean re libft norm matrix parse
