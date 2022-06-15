/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiplication_struct.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:11:22 by cchong            #+#    #+#             */
/*   Updated: 2022/06/15 07:06:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef	struct s_matrix {
	int	row;
	int col;
	int *data;
}	t_matrix;

void	*ft_memset(void *b, int c, size_t n)
{
	size_t	i;
	char	*s;

	i = 0;
	s = b;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	mul;

	mul = nmemb * size;
	if (mul / nmemb != size)
		return (NULL);
	mem = malloc(nmemb * size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, nmemb * size);
	return (mem);
}

t_matrix	*ft_matrix_new(int row, int col)
{
	t_matrix	*matrix;

	if (row < 1 || col < 1)
		return (NULL);
	matrix = malloc(sizeof(t_matrix));
	if (matrix == NULL)
		return (NULL);
	matrix->row = row;
	matrix->col = col;
	matrix->data = ft_calloc(row * col, sizeof(int *));
	if (matrix->data == NULL)
		return (NULL);
	return (matrix);
}

void	ft_matrix_del(t_matrix *matrix)
{
	if (matrix->data != NULL)
		free(matrix->data);
	free(matrix);
}

t_matrix	*ft_mat_identity(int n)
{
	t_matrix	*matrix;
	int			index;

	matrix = ft_matrix_new(n, n);
	index = -1;
	while (++index < n * n)
	{
		if (index % (n + 1) == 0)
			matrix->data[index] = 1;
		else
			matrix->data[index] = 0;
	}
	return (matrix);
}

t_matrix	*matrix_multiplication(t_matrix *arr, t_matrix *trans)
{
	int			i;
	int			j;
	int			k;
	t_matrix	*matrix;

	if (arr->col != trans->row)
		return (NULL);
	matrix = ft_matrix_new(arr->row, trans->col);
	matrix->row = arr->row;
	matrix->col = trans->col;
	i = -1;
	k = 0;

	while (++i < arr->col * arr->row)
	{
		j = -1;
		while (++j < trans->row)
		{
			matrix->data[i] += arr->data[j] * trans->data[k];
			// printf("%i * %i\ndata[%i] = %i\n", arr->data[j], trans->data[k], i, matrix->data[i]);
			k += trans->col;
			// printf("k = %i\n", k);
		}
		k -= trans->row * trans->col - 1;
		// printf("%i\n", k);
	}
	return (matrix);
}

void	print_matrix(t_matrix *matrix)
{
	int	i = -1;

	while (++i < matrix->row * matrix->col)
		printf("%i ", matrix->data[i]);
}

int	main(void)
{
	t_matrix	*arr;
	t_matrix	*trans;
	t_matrix	*res;
	t_matrix	*identity_mat;
	int			i = -1;
	int			j = -1;

	arr = ft_matrix_new(1, 4);
	trans = ft_matrix_new(4, 4);
	identity_mat = ft_mat_identity(4);
	while (++i < 4)
		arr->data[i] = i;
	while (++j < 16)
		trans->data[j] = j;
	printf("arr ");
	print_matrix(arr);
	printf("\n");
	printf("trans ");
	print_matrix(trans);
	printf("\n");
	// printf("identitymat ");
	// print_matrix(identity_mat);
	// printf("\n");
	res = matrix_multiplication(arr, trans);
	printf("res ");
	print_matrix(res);
	printf("\n");
	ft_matrix_del(arr);
	ft_matrix_del(trans);
	ft_matrix_del(res);
	ft_matrix_del(identity_mat);
}

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
