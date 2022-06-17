/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:11:22 by cchong            #+#    #+#             */
/*   Updated: 2022/06/17 08:23:15 by marvin           ###   ########.fr       */
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
To check if matrix is initiated. If not, perror msg and exit program.
*/
void	check_mat(t_matrix *matrix)
{
	if (matrix == NULL)
	{
		perror("Matrix is NULL.");
		exit(EXIT_FAILURE);
	}
}

/*
To check if row/col is within the matrix. If not, perror msg and exit program.
*/
void	check_row_col(t_matrix *matrix, size_t row, size_t col)
{
	if (row >= matrix->row || col >= matrix->col)
	{
		// printf("%li %li %li %li\n", row, matrix->row, col, matrix->col);
		perror("Row/col exceeded row/col of matrix.");
		exit(EXIT_FAILURE);
	}
}

/*
To get the element in row and column from the matrix.
*/
double	get_element(t_matrix *matrix, size_t row, size_t col)
{
	check_mat(matrix);
	check_row_col(matrix, row, col);
	return (printf("%i\n", (int)matrix->data[row * matrix->col + col]));
}

/*
To add the value to the element in row and column in the matrix.
*/
void	update_element(t_matrix *matrix, size_t row, size_t col, double value)
{
	check_mat(matrix);
	check_row_col(matrix, row, col);
	matrix->data[row * matrix->col + col] += value;
}

/*
To multiply two matrices and return a new matrix with the result.
*/
t_matrix	*matrix_multiplication(t_matrix *A, t_matrix *B)
{
	size_t		mat_i;
	size_t		A_i;
	size_t		B_i;
	size_t		B_row_offset;
	t_matrix	*matrix;

	if (A->col != B->row)
	{
		perror("Multiplication of matrices not possible");
		exit(EXIT_FAILURE);
	}
	matrix = ft_matrix_new(A->row, B->col);
	B_row_offset = -1;
	while (++B_row_offset < B->row)
	{
		mat_i = -1;
		A_i = B_row_offset;
		B_i = B_row_offset * B->col - 1;
		while (++mat_i < (A->row * B->col))
		{
			matrix->data[mat_i] += A->data[A_i] * B->data[++B_i];
			if ((mat_i % B->col) == B->row)
			{
				A_i += A->col;
				B_i -= B->col;
			}
		}
	}
	return (matrix);
}

// printf("(arr->data[%i] = %i ) * ", (int)j, (int)arr->data[j]);
// printf("(trans->data[%i] = %i)", (int)k, (int)trans->data[k]);
// printf(" = matrix->data[%i] = %i\n", (int)i, (int)matrix->data[i]);