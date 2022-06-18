/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 05:32:45 by cchong            #+#    #+#             */
/*   Updated: 2022/06/18 05:32:46 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
To get the element in row and column from the mat.
*/
double	ft_get_val(t_mat *mat, size_t row, size_t col)
{
	if (row >= mat->row || col >= mat->col)
		ft_perror("get val error");
	return (mat->data[row * mat->col + col]);
}

/*
To set the value to the element in row and column in the mat.
*/
void	ft_set_val(t_mat *mat, size_t row, size_t col, double value)
{
	if (row >= mat->row || col >= mat->col)
		ft_perror("set val error");
	mat->data[row * mat->col + col] = value;
}
