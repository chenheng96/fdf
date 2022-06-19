/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 03:01:34 by cchong            #+#    #+#             */
/*   Updated: 2022/06/19 04:33:00 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
To translate 3D models around x, y, z coordinates.
*/
t_mat   *ft_translate(t_mat *A, double x, double y, double z)
{
    t_mat   *mat;
    t_mat   *ret;

    mat = ft_mat_identity(4);
    mat->data[0][3] = x;
    mat->data[1][3] = y;
    mat->data[2][3] = z;
    ret = ft_mat_mul(A, mat);
    ft_mat_del(mat);
    return (ret);
}

/*
To scale 3D models around x, y, z coordinates.
*/
t_mat   *ft_scale(t_mat *A, double x, double y, double z)
{
    t_mat   *mat;
    t_mat   *ret;

    mat = ft_mat_identity(4);
    mat->data[0][0] = x;
    mat->data[1][1] = y;
    mat->data[2][2] = z;
    ret = ft_mat_mul(A, mat);
    ft_mat_del(mat);
    return (ret);
}

/*
To shear 3D models around x, y, z coordinates.
*/
t_mat   *ft_shear(t_mat *A, double x, double y, double z)
{
    t_mat   *mat;
    t_mat   *ret;

    mat = ft_mat_identity(4);
    mat->data[0][1] = x * y;
    mat->data[0][2] = x * z;
    mat->data[1][0] = y * x;
    mat->data[1][2] = y * z;
    mat->data[2][0] = z * x;
    mat->data[2][1] = z * y;
    ret = ft_mat_mul(A, mat);
    ft_mat_del(mat);
    return (ret);
}
