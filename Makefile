FDF		= fdf
SRCS	= fdf.c affine_rotation.c affine_transformation.c draw_line.c draw_line_helper.c fdf_helper.c handle_key.c matrix_helper.c matrix_multiplication.c parse_map.c parse_map_helper.c
SRCS2	= affine_rotation.c affine_transformation.c draw_line.c draw_line_helper.c fdf_helper.c handle_key.c matrix_helper.c matrix_multiplication.c parse_map.c parse_map_helper.c

CC		= gcc
CFLAGS	= -fsanitize=address -g3 #-Wall -Werror -Wextra

INCLUDE = -Iinclude -Ilibft -I/usr/local/include
LDFLAGS = -Llibft -L/usr/local/lib/
LDLIBS	= -lft -lm -lmlx -framework OpenGL -framework AppKit

LIBFT	= libft/libft.a

OBJS	= ${SRCS:.c=.o}
OBJS2	= ${SRCS2:.c=.o}

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
		${CC} matrix_multiplication.c test_matrix_multiplication.c matrix_helper.c fdf_helper.c draw_line_helper.c draw_line.c -o matrix ${CFLAGS} ${INCLUDE} ${LDFLAGS} ${LDLIBS}
		./matrix
		${RM} matrix

parse:	${LIBFT}
		${CC} test_parse_map.c -o parse ${SRCS2} ${CFLAGS} ${INCLUDE} ${LDFLAGS} ${LDLIBS}
		./parse
		${RM} parse

norm:
		norminette *.c *.h

.PHONY: all clean fclean re libft norm matrix parse
