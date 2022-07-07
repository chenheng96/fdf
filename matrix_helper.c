/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 05:32:45 by cchong            #+#    #+#             */
/*   Updated: 2022/07/07 17:28:41 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
To get the element in row and column from the mat.
*/
double	ft_get_val(t_mat *mat, size_t row, size_t col)
{
	if (row >= mat->row || col >= mat->col)
		ft_perror("ft_get_val error");
	return (mat->data[row * mat->col + col]);
}

/*
To set the value to the element in row and column in the mat.
*/
void	ft_set_val(t_mat *mat, size_t row, size_t col, double value)
{
	if (row >= mat->row || col >= mat->col)
		ft_perror("ft_set_val error");
	mat->data[row * mat->col + col] = value;
}

/*
To print out the matrix.
*/
void	print_mat(t_mat *mat)
{
	size_t	i;

	i = -1;
	while (++i < mat->row * mat->col)
		printf("%i, ", (int)mat->data[i]);
}
