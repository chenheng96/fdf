/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 04:28:13 by cchong            #+#    #+#             */
/*   Updated: 2022/07/11 15:32:46 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_xyminmax(t_vars *vars)
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

void	reset_xy(t_vars *vars)
{
	vars->min_x = 0;
	vars->min_y = 0;
	vars->max_x = 0;
	vars->max_y = 0;
}

/*
To return a trans mat to rotate 3D models around x coordinates.
*/
t_mat	*ft_rotate_x(double x)
{
	t_mat	*mat;

	mat = ft_mat_identity(4);
	ft_set_val(mat, 1, 1, cos(x));
	ft_set_val(mat, 1, 2, -sin(x));
	ft_set_val(mat, 2, 1, sin(x));
	ft_set_val(mat, 2, 2, cos(x));
	return (mat);
}

/*
To return a trans mat to rotate 3D models around y coordinates.
*/
t_mat	*ft_rotate_y(double y)
{
	t_mat	*mat;

	mat = ft_mat_identity(4);
	ft_set_val(mat, 0, 0, cos(y));
	ft_set_val(mat, 0, 2, sin(y));
	ft_set_val(mat, 2, 0, -sin(y));
	ft_set_val(mat, 2, 2, cos(y));
	return (mat);
}

/*
To return a trans mat to rotate 3D models around z coordinates.
*/
t_mat	*ft_rotate_z(double z)
{
	t_mat	*mat;

	mat = ft_mat_identity(4);
	ft_set_val(mat, 0, 0, cos(z));
	ft_set_val(mat, 0, 1, -sin(z));
	ft_set_val(mat, 1, 0, sin(z));
	ft_set_val(mat, 1, 1, cos(z));
	return (mat);
}
