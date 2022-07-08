/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:51:18 by cchong            #+#    #+#             */
/*   Updated: 2022/07/08 11:33:35 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_xyz(int keycode, t_vars *vars)
{
	t_mat	*mat;
	t_mat	*temp;

	if (keycode == X)
		mat = ft_rotate_x(-90+35.264); // 35.264 / 90 - 35.264 / -35.264 / 35.264 - 90
	else if (keycode == Y)
		mat = ft_rotate_y(10);
	else
		mat = ft_rotate_z(45);
	temp = ft_mat_mul(vars->map->transform, mat);
	ft_mat_del(vars->map->transform);
	ft_mat_del(mat);
	vars->map->transform = temp;
	new_frame(vars);
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
		handle_xyz(keycode, vars);
	else if (keycode == UP || keycode == DOWN || keycode == LEFT
		|| keycode == RIGHT)
		handle_translate(keycode, vars);
	else if (keycode == PLUS || keycode == MINUS)
		handle_scale(keycode, vars);
	else if (keycode == Q || keycode == W)
		handle_shear(keycode, vars);
	return (0);
}
