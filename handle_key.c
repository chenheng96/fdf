/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:51:18 by cchong            #+#    #+#             */
/*   Updated: 2022/07/11 11:15:31 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_midpoint(t_vars *vars)
{
	size_t	k;

	k = -1;
	while (++k < vars->map->row * vars->map->col)
	{
		if (vars->x0 < vars->min_x)
			vars->min_x = vars->x0;
		if (vars->y0 < vars->min_y)
			vars->min_y = vars->y0;
		if (vars->x1 > vars->max_x)
			vars->max_x = vars->x1;
		if (vars->y1 > vars->max_y)
			vars->max_y = vars->y1;
	}
}

void	reset_xy(t_vars *vars)
{
	vars->min_x = 0;
	vars->min_y = 0;
	vars->max_x = 0;
	vars->max_y = 0;
}

void	handle_xyz(int keycode, t_vars *vars)
{
	t_mat	*mat;
	t_mat	*temp;

	ft_mat_del(vars->map->transform);
	vars->map->transform = ft_translate((vars->min_x - vars->max_x) / 2,
		(vars->min_y - vars->max_y) / 2, 0);
	new_frame(vars);
	if (keycode == X)
		mat = ft_rotate_x(1); // 35.264 / 90 - 35.264 / -35.264 / 35.264 - 90
	else if (keycode == Y)
		mat = ft_rotate_y(1);
	else
		mat = ft_rotate_z(1);
	temp = ft_mat_mul(vars->map->transform, mat);
	ft_mat_del(vars->map->transform);
	ft_mat_del(mat);
	vars->map->transform = temp;
	new_frame(vars);
	ft_mat_del(vars->map->transform);
	vars->map->transform = ft_translate((vars->max_x - vars->min_x) / 2,
		(vars->max_y - vars->min_y) / 2, 0);
	new_frame(vars);
	reset_xy(vars);
}

void	handle_translate(int keycode, t_vars *vars)
{
	double	x;
	double	y;
	double	z;

	x = 0;
	y = 0;
	z = 0;
	if (keycode == UP)
		y = -20;
	else if (keycode == DOWN)
		y = 20;
	else if (keycode == LEFT)
		x = -20;
	else
		x = 20;
	ft_mat_del(vars->map->transform);
	vars->map->transform = ft_translate(x, y, z);
	new_frame(vars);
}

void	handle_scale(int keycode, t_vars *vars)
{
	double	x;
	double	y;
	double	z;

	if (keycode == PLUS)
	{
		x = 2;
		y = 2;
		z = 2;
	}
	else
	{
		x = 0.5;
		y = 0.5;
		z = 0.5;
	}
	ft_mat_del(vars->map->transform);
	vars->map->transform = ft_scale(x, y, z);
	new_frame(vars);
}

void	handle_shear(int keycode, t_vars *vars)
{
	double	x;
	double	y;
	double	z;

	if (keycode == Q)
	{
		x = -40;
		y = -40;
		z = -40;
	}
	else
	{
		x = 40;
		y = 40;
		z = 40;
	}
	ft_mat_del(vars->map->transform);
	vars->map->transform = ft_scale(x, y, z);
	new_frame(vars);
}

/*
To handle events when certain keys are pressed. Lack closing window.
*/
int	handle_key(int keycode, t_vars *vars)
{
	printf("keycode:%i\n", keycode);
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		ft_vars_del(vars);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == X || keycode == Y || keycode == Z)
	{
		handle_xyz(keycode, vars);
		check_midpoint(vars);
	}
	else if (keycode == UP || keycode == DOWN || keycode == LEFT
		|| keycode == RIGHT)
		handle_translate(keycode, vars);
	else if (keycode == PLUS || keycode == MINUS)
		handle_scale(keycode, vars);
	else if (keycode == Q || keycode == W)
		handle_shear(keycode, vars);
	return (0);
}
