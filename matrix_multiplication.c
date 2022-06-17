/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:11:22 by cchong            #+#    #+#             */
/*   Updated: 2022/06/17 07:10:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

/*
To allocate memory for matrix struct and fill in row and col info of matrix
as well as allocate memory for the array and change all of the values to 0.
*/
t_matrix	*ft_matrix_new(size_t row, size_t col)
{
	t_matrix	*matrix;

	if (row < 1 || col < 1)
		return (NULL);
	matrix = malloc(sizeof(t_matrix));
	if (matrix == NULL)
		return (NULL);
	matrix->row = row;
	matrix->col = col;
	matrix->data = ft_calloc(row * col, sizeof(double *));
	if (matrix->data == NULL)
		return (NULL);
	return (matrix);
}

/*
To free the memory in matrix's data and free memory of matrix.
*/
void	ft_matrix_del(t_matrix *matrix)
{
	if (matrix->data != NULL)
		free(matrix->data);
	free(matrix);
}

/*
To allocate memory for a new matrix and change its value to identity matrix.
*/
t_matrix	*ft_mat_identity(size_t n)
{
	t_matrix	*matrix;
	size_t		index;

	matrix = ft_matrix_new(n, n);
	index = -1;
	while (++index < n)
		matrix->data[index * n + index] = 1;
	return (matrix);
}

/*
To get the element in row and column from the matrix.
*/
double	get_element(t_matrix *matrix, size_t row, size_t col)
{
	printf("%i\n", (int)matrix->data[row * matrix->col + col]);
	return (matrix->data[row * matrix->col + col]);
}

/*
To add the value to the element in row and column in the matrix.
*/
void	update_element(t_matrix *matrix, size_t row, size_t col, double value)
{
	if (matrix == NULL)
		return ;
	if ((row + 1) > matrix->row || (col + 1) > matrix->col)
		return ;
	matrix->data[row * matrix->col + col] += value;
}

/*
To multiply two matrices and return a new matrix with the result.
*/
t_matrix	*matrix_multiplication(t_matrix *arr, t_matrix *trans)
{
	size_t		mat_i;
	size_t		arr_i;
	size_t		trans_i;
	size_t		trans_row_offset;
	t_matrix	*matrix;

	if (arr->col != trans->row)
		return (NULL);
	matrix = ft_matrix_new(arr->row, trans->col);
	trans_row_offset = -1;
	while (++trans_row_offset < trans->row)
	{
		mat_i = -1;
		arr_i = trans_row_offset;
		trans_i = trans_row_offset * trans->col - 1;
		while (++mat_i < (arr->row * trans->col))
		{
			matrix->data[mat_i] += arr->data[arr_i] * trans->data[++trans_i];
			if ((mat_i % trans->col) == trans->row)
			{
				arr_i += arr->col;
				trans_i -= trans->col;
			}
		}
	}
	return (matrix);
}

// printf("(arr->data[%i] = %i ) * ", (int)j, (int)arr->data[j]);
// printf("(trans->data[%i] = %i)", (int)k, (int)trans->data[k]);
// printf(" = matrix->data[%i] = %i\n", (int)i, (int)matrix->data[i]);