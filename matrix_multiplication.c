/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:11:22 by cchong            #+#    #+#             */
/*   Updated: 2022/06/17 05:57:45 by marvin           ###   ########.fr       */
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
	size_t		i;
	size_t		j;
	size_t		k;
	size_t		num;
	t_matrix	*matrix;

	matrix = ft_matrix_new(arr->row, trans->col);
	i = 0;
	num = 0;
	while (++num <= arr->row)
	{
		k = 0;
		while (i < trans->col * num)
		{
			j = (num - 1) * arr->col - 1;
			while (++j < trans->row * num)
			{
				matrix->data[i] += arr->data[j] * trans->data[k];
				k += trans->col;
			}
			k -= trans->row * trans->col - 1;
			i++;
		}
	}
	return (matrix);
}
