/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:51:18 by cchong            #+#    #+#             */
/*   Updated: 2022/06/29 16:06:26 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    handle_xyz(int keycode, t_vars *vars)
{
    t_mat   *mat;
    t_mat   *temp;

    if (keycode == 7)
        mat = ft_rotate_x(45);
    else if (keycode == 16)
        mat = ft_rotate_y(35.264);
    else
        mat = ft_rotate_z(45);
    temp = ft_mat_mul(vars->map->transform, mat);
    ft_mat_del(vars->map->transform);
    ft_mat_del(mat);
    vars->map->transform = temp;
    new_frame(vars);
}

void    handle_translate(int keycode, t_vars *vars)
{
    double  x;
    double  y;
    double  z;

    x = 0;
    y = 0;
    z = 0;
    if (keycode == 126)
        y = -20;
    else if (keycode == 125)
        y = 20;
    else if (keycode == 123)
        x = -20;
    else
        x = 20;
	ft_mat_del(vars->map->transform);
    vars->map->transform = ft_translate(x, y, z);
    new_frame(vars);
}

void    handle_scale(int keycode, t_vars *vars)
{
    double  x;
    double  y;
    double  z;

    x = 20;
    y = 20;
    z = 0;
    if (keycode == 27)
    {
        x = -x;
        y = -y;
    }
	ft_mat_del(vars->map->transform);
    vars->map->transform = ft_scale(x, y, z);
    new_frame(vars);
}

void    handle_shear(int keycode, t_vars *vars)
{
    double  x;
    double  y;
    double  z;

    x = 20;
    y = 20;
    z = 0;
    if (keycode == 12)
    {
        x = -x;
        y = -y;
    }
    ft_mat_del(vars->map->transform);
    vars->map->transform = ft_scale(x, y, z);
    new_frame(vars);
}

/*
To handle events when certain keys are pressed.
*/
int	handle_key(int keycode, t_vars *vars)
{
	printf("keycode:%i\n", keycode);
	if (keycode == 53) //lack close window
	{
		mlx_destroy_window(vars->mlx, vars->win);
		// ft_map_del(map);
		ft_vars_del(vars);
		// free(data);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 7 || keycode == 16 || keycode == 6)
        handle_xyz(keycode, vars);
    else if (keycode == 126 || keycode == 125 || keycode == 123 || keycode == 124)
        handle_translate(keycode, vars);
    else if (keycode == 24 || keycode == 27)
        handle_scale(keycode, vars);
    else if (keycode == 12 || keycode == 13)
        handle_shear(keycode, vars);
	return (0);
}
