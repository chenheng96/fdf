/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 04:28:13 by cchong            #+#    #+#             */
/*   Updated: 2022/06/19 04:28:39 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
To rotate 3D models around x coordinates.
*/
t_mat   *ft_rotate_x(t_mat *A, double x)
{
    t_mat   *mat;
    t_mat   *ret;

    mat = ft_mat_identity(4);
    mat->data[1][1] = cos(x);
    mat->data[1][2] = -sin(x);
    mat->data[2][1] = sin(x);
    mat->data[2][2] = cos(x);
    ret = ft_mat_mul(A, mat);
    ft_mat_del(mat);
    return (ret);
}

/*
To rotate 3D models around y coordinates.
*/
t_mat   *ft_rotate_y(t_mat *A, double y)
{
    t_mat   *mat;
    t_mat   *ret;

    mat = ft_mat_identity(4);
    mat->data[0][0] = cos(y);
    mat->data[0][2] = sin(y);
    mat->data[2][0] = -sin(y);
    mat->data[2][2] = cos(y);
    ret = ft_mat_mul(A, mat);
    ft_mat_del(mat);
    return (ret);
}

/*
To rotate 3D models around x coordinates.
*/
t_mat   *ft_rotate_z(t_mat *A, double z)
{
    t_mat   *mat;
    t_mat   *ret;

    mat = ft_mat_identity(4);
    mat->data[0][0] = cos(z);
    mat->data[0][1] = -sin(z);
    mat->data[1][0] = sin(z);
    mat->data[1][1] = cos(z);
    ret = ft_mat_mul(A, mat);
    ft_mat_del(mat);
    return (ret);
}
