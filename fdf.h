/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:25:50 by cchong            #+#    #+#             */
/*   Updated: 2022/06/24 15:32:31 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// # include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_mat {
	size_t	row;
	size_t	col;
	double	*data;
}	t_mat;

typedef struct s_map {
	size_t	row;
	size_t	col;
	double	**data;
	t_mat	**map;
	t_mat	*transform;
}	t_map;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_vars;

typedef struct s_data {
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	dx;
	int dy;
	int	xi;
	int	yi;
	int	D;
	int	x;
	int	y;
}	t_data;

// mlx related functions
void	handle_key(int keycode, t_vars *vars, t_map *map, t_data *data);
void    new_frame(t_data *data, t_vars *vars, t_map *map);
void	ft_vars_del(t_vars *vars);

// line drawing algorithm
int		abs(int n);
void	my_mlxpixelput(t_vars *data, int x, int y, int color);
void	draw_line(t_data *data, t_vars *vars);
void	draw_line_low(t_data *data, t_vars *vars);
void	draw_line_high(t_data *data, t_vars *vars);
void	set_coordinates(t_data *data, t_map *map, size_t k, size_t n);
void	connect_dot(t_data *data, t_vars *vars, t_map *map);

// map parsing
void	open_file(char *str, t_map *map);
void	parse_map(int fd, t_map *map);
void	fill_map(t_map *map);
void	ft_map_del(t_map *map);
size_t	countrow_checkcol(char	*str, t_map *map);

// matrix functions
t_mat	*ft_mat_new(size_t row, size_t col);
void	ft_mat_del(t_mat *mat);
void	ft_mat_cpy(t_mat *A, t_mat *B);
t_mat	*ft_mat_identity(size_t n);
t_mat	*ft_mat_mul(t_mat *A, t_mat *B);
double	ft_get_val(t_mat *mat, size_t row, size_t col);
void	ft_set_val(t_mat *mat, size_t row, size_t col, double value);
int		compare_mat(t_mat *A, t_mat *B);

// affine transformation
t_mat	*ft_translate(double x, double y, double z);
t_mat	*ft_scale(double x, double y, double z);
t_mat	*ft_shear(double x, double y, double z);
t_mat	*ft_rotate_x(double x);
t_mat	*ft_rotate_y(double y);
t_mat	*ft_rotate_z(double z);

// general functions
void	ft_perror(const char *s);
void	*ft_malloc(size_t size);
int		ft_open(const char *pathname, int flags);

#endif