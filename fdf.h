/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:25:50 by cchong            #+#    #+#             */
/*   Updated: 2022/06/19 04:00:36 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// # include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include "libft/libft.h"

typedef	struct s_mat {
	size_t	row;
	size_t	col;
	double	*data;
}				t_mat;

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

// mlx functions
void	my_mlxpixelput(t_vars *data, int x, int y, int color);
int		handle_key(int keycode, t_vars *vars);

// line drawing algorithm
int		abs(int n);
void	draw_line1(t_data *data, t_vars *vars, int color);
void	draw_line2(t_data *data, t_vars *vars, int color);

// map parsing
int 	**parse_map(char *str, char ***map, t_data *data, int **map_coor);

// matrix functions
t_mat	*ft_mat_new(size_t row, size_t col);
void	ft_mat_del(t_mat *mat);
void	ft_mat_cpy(t_mat *A, t_mat *B);
t_mat	*ft_mat_identity(size_t n);
t_mat	*ft_mat_mul(t_mat *A, t_mat *B);
double	ft_get_val(t_mat *mat, size_t row, size_t col);
void	ft_set_val(t_mat *mat, size_t row, size_t col, double value);
int		compare_mat(t_mat *A, t_mat *B);

// general functions
void	ft_perror(const char *s);

#endif