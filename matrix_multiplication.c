/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 05:30:20 by cchong            #+#    #+#             */
/*   Updated: 2022/06/20 13:03:48 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
To allocate memory for mat struct and fill in row and col info of mat
as well as allocate memory for the array and change all of the values to 0.
*/
t_mat	*ft_mat_new(size_t row, size_t col)
{
	t_mat	*mat;

	if (row < 1 || col < 1)
		ft_perror("ft_mat_new error");
	mat = malloc(sizeof(t_mat));
	if (mat == NULL)
		ft_perror("ft_mat_new error");
	mat->row = row;
	mat->col = col;
	mat->data = ft_calloc(row * col, sizeof(double *));
	if (mat->data == NULL)
		ft_perror("ft_mat_new error");
	return (mat);
}

/*
To free the memory in mat's data and free memory of mat.
*/
void	ft_mat_del(t_mat *mat)
{
	free(mat->data);
	free(mat);
}

/*
To allocate memory for a new mat and change its value to identity mat.
*/
t_mat	*ft_mat_identity(size_t n)
{
	t_mat	*mat;
	size_t	index;

	mat = ft_mat_new(n, n);
	index = -1;
	while (++index < n)
		mat->data[index * n + index] = 1;
	return (mat);
}

/*
To copy matrix A into matrix B.
*/
void	ft_mat_cpy(t_mat *A, t_mat *B)
{
	size_t	i;

	i = -1;
	if (A->row == B->row || A->col == B->col)
	{
		while (++i < A->row *A->col)
			B->data[i] = A->data[i];
	}
	else
		ft_perror("ft_mat_cpy error\n");
}

/*
To multiply two matrices and return new matrix with the result.
*/
t_mat	*ft_mat_mul(t_mat *A, t_mat *B)
{
	size_t	i;
	size_t	j;
	double	val;
	t_mat	*mat;

	if (A->col != B->row)
		ft_perror("ft_mat_mul error");
	mat = ft_mat_new(A->row, B->col);
	i = -1;
	while (++i < A->row * B->col)
	{
		val = 0;
		j = -1;
		while (++j < B->row)
		{
			val += ft_get_val(A, i / B->col, j) * ft_get_val(B, j, i % B->col);
			ft_set_val(mat, i / B->col, i % B->col, val);
		}
	}
	return (mat);
}
