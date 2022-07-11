/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 03:01:34 by cchong            #+#    #+#             */
/*   Updated: 2022/07/11 15:32:58 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	centre_object(t_vars *vars)
{
	reset_xy(vars);
	check_xyminmax(vars);
	ft_mat_del(vars->map->transform);
	vars->map->transform = ft_translate(WIDTH / 2 - vars->max_x + vars->min_x,
			HEIGHT / 2 - vars->max_y + vars->min_y, 0);
	new_frame(vars);
}

/*
To return trans mat to translate 3D models around x, y, z coordinates.
*/
t_mat	*ft_translate(double x, double y, double z)
{
	t_mat	*mat;

	mat = ft_mat_identity(4);
	ft_set_val(mat, 0, 3, x);
	ft_set_val(mat, 1, 3, y);
	ft_set_val(mat, 2, 3, z);
	return (mat);
}

/*
To return trans mat to scale 3D models around x, y, z coordinates.
*/
t_mat	*ft_scale(double x, double y, double z)
{
	t_mat	*mat;

	mat = ft_mat_identity(4);
	ft_set_val(mat, 0, 0, x);
	ft_set_val(mat, 1, 1, y);
	ft_set_val(mat, 2, 2, z);
	return (mat);
}

/*
To return trans mat to shear 3D models around x, y, z coordinates.
*/
t_mat	*ft_shear(double x, double y, double z)
{
	t_mat	*mat;

	mat = ft_mat_identity(4);
	ft_set_val(mat, 0, 1, x * y);
	ft_set_val(mat, 0, 2, x * z);
	ft_set_val(mat, 1, 0, y * x);
	ft_set_val(mat, 1, 2, y * z);
	ft_set_val(mat, 2, 0, z * x);
	ft_set_val(mat, 2, 1, z * y);
	return (mat);
}
