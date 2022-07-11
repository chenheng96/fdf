/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:25:50 by cchong            #+#    #+#             */
/*   Updated: 2022/07/11 15:58:33 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1920
# define HEIGHT 1080
# define ESC 53
# define Q 12
# define W 13
# define X 7
# define Y 16
# define Z 6
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define MINUS 27
# define PLUS 24

# include <mlx.h>
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
	t_mat	**coor;
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
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		max_x;
	int		min_x;
	int		max_y;
	int		min_y;
	int		dx;
	int		dy;
	t_map	*map;
}	t_vars;

// mlx related functions
t_vars	*ft_vars_new(void);
void	ft_vars_del(t_vars *vars);
int		handle_key(int keycode, t_vars *vars);
void	new_frame(t_vars *vars);
void	handle_xyz(int keycode, t_vars *vars);
void	reset_xy(t_vars *vars);
void	check_xyminmax(t_vars *vars);
void	centre_object(t_vars *vars);

// line drawing algorithm
int		abs(int n);
void	my_mlxpixelput(t_vars *vars, int x, int y, int color);
void	draw_line(t_vars *vars);
void	draw_line_low(t_vars *vars);
void	draw_line_high(t_vars *vars);
void	set_coordinates(t_vars *vars, t_map *map, size_t k, size_t n);
void	connect_dot(t_vars *vars);
void	swap_xy(t_vars *vars);

// map parsing
void	parse_map1(char *str, t_map *map);
void	parse_map2(int fd, t_map *map);
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
void	print_mat(t_mat *mat);

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