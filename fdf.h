/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:25:50 by cchong            #+#    #+#             */
/*   Updated: 2022/06/17 02:44:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// # include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef	struct s_matrix {
	size_t	row;
	size_t	col;
	double	*data;
}				t_matrix;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_vars;

typedef struct s_data {
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	error;
	int	e2;
	int	x;
	int	y;
}				t_data;

void		my_mlxpixelput(t_vars *data, int x, int y, int color);
int			handle_key(int keycode, t_vars *vars);
int			abs(int n);
void		draw_line1(t_data *data, t_vars *vars, int color);
void		draw_line2(t_data *data, t_vars *vars, int color);
int 		**parse_map(char *str, char ***map, t_data *data, int **map_coor);
t_matrix	*ft_matrix_new(size_t row, size_t col);
void		ft_matrix_del(t_matrix *matrix);
t_matrix	*ft_mat_identity(size_t n);
t_matrix	*matrix_multiplication(t_matrix *arr, t_matrix *trans);
double		get_element(t_matrix *matrix, size_t row, size_t col);
void		update_element(t_matrix *matrix, size_t row, size_t col, double value);

#endif