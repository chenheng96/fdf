/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 04:28:13 by cchong            #+#    #+#             */
/*   Updated: 2022/06/20 11:45:55 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
To return a trans mat to rotate 3D models around x coordinates.
*/
t_mat   *ft_rotate_x(double x)
{
    t_mat   *mat;

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
t_mat   *ft_rotate_y(double y)
{
    t_mat   *mat;

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
t_mat   *ft_rotate_z(t_mat *A)
{
    t_mat   *mat;

    mat = ft_mat_identity(4);
	ft_set_val(mat, 0, 0, cos(z));
	ft_set_val(mat, 0, 1, sin(z));
	ft_set_val(mat, 1, 0, -sin(z));
	ft_set_val(mat, 1, 1, cos(z));
    return (ret);
}
