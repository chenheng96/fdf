/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:11:22 by cchong            #+#    #+#             */
/*   Updated: 2022/06/14 16:29:29 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef	struct s_matrix {
	int	row;
	int col;
	int *data;
}	t_matrix;

t_matrix	ft_matrix_new(int row, int col)
{
	t_matrix	matrix;

	if (row < 1 || col < 1)
		return (NULL);
	matrix = malloc(sizeof(t_matrix));
	if (matrix == NULL)
		return (NULL);
	matrix.row = row;
	matrix.col = col;
	matrix.data = ft_calloc(row * col, sizeof(int));
	if (matrix.data == NULL)
		return (NULL);
	return (matrix);
}

void	ft_matrix_del(t_matrix matrix)
{
	if (matrix->data != NULL)
		free(matrix->data);
	free(matrix);
}

t_matrix	ft_mat_identity(int	n)
{
	t_matrix	matrix;
	int			index;

	matrix = ft_matrix_new(n, n);
	index = -1;
	while (++index < n * n)
	{
		if (index % n == 0)
			matrix.data[index] = 1;
		else
			matrix.data[index] = 0;
	}
	return (matrix);
}

t_matrix	matrix_multiplication(t_matrix arr, t_matrix trans)
{
	int			i;
	int			j;
	t_matrix	matrix;

	if (arr.col != trans.row)
		return (NULL);
	matrix = ft_matrix_new(arr.row, trans.col);
	i = -1;
	while (++i < arr.col)
	{
		j = -1;
		while (++j < trans.row)
			matrix.data[i] += arr.data[j] * trans.data[j][i];
	}
	return (matrix);
}

int	main(void)
{
	t_matrix	arr;
	t_matrix	trans;
	t_matrix	res;

	arr = ft_matrix_new(1, 4);
	trans = ft_matrix_new(4, 4);
	arr.data = {17, 18, 19, 20};
	trans.data = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	res = matrix_multiplication(arr, trans);
	// int	i;
	// int arr[4] = {17, 18, 19, 20};
	// int trans[4][4] = {
	// 	{1, 2, 3, 4},
	// 	{5, 6, 7, 8},
	// 	{9, 10, 11, 12},
	// 	{13, 14, 15, 16}
	// };

	// matrix_multiplication(arr, trans);
	// i = -1;
	// while (++i < 4)
	// 	printf("res[%i] = %i\n", i, res[i]);

	// printf("size of arr = %lu\n", sizeof(arr)/sizeof(int));
	// printf("size of trans = %lu\n", sizeof(trans)/sizeof(int));
	// printf("size of trans[0] = %lu\n", sizeof(trans[0])/sizeof(trans[0][0]));
	// printf("row of trans = %lu\n", sizeof(trans)/sizeof(trans[0]));
	// i = -1;
	// while (++i < 4)
	// 	printf("arr[%i] = %i\n", i, arr[i]);
	// i = -1;
	// while (++i < 4)
	// {
	// 	int j = -1;
	// 	while (++j < 4)
	// 		printf("trans[%i][%i] = %i\n", i, j, trans[i][j]);
	// }
}
