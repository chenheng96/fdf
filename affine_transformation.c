/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 03:01:34 by cchong            #+#    #+#             */
/*   Updated: 2022/06/19 08:59:59 by cchong           ###   ########.fr       */
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
    ft_set_val(mat, 0, 3, x);
    ft_set_val(mat, 1, 3, y);
    ft_set_val(mat, 2, 3, z);
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
    ft_set_val(mat, 0, 0, x);
    ft_set_val(mat, 1, 1, y);
    ft_set_val(mat, 2, 2, z);
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
    ft_set_val(mat, 0, 1, x * y);
    ft_set_val(mat, 0, 2, x * z);
    ft_set_val(mat, 1, 0, y * x);
    ft_set_val(mat, 1, 2, y * z);
    ft_set_val(mat, 2, 0, z * x);
    ft_set_val(mat, 2, 1, z * y);
    ret = ft_mat_mul(A, mat);
    ft_mat_del(mat);
    return (ret);
}
