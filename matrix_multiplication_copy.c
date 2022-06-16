/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiplication_copy.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:11:22 by cchong            #+#    #+#             */
/*   Updated: 2022/06/16 12:00:14 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef	struct s_matrix {
	size_t	row;
	size_t	col;
	double	*data;
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
	i = 0;
	k = 0;
	int num = 1;

	while (num <= arr->row)
	{
		while (i < trans->col * num)
		{
			j = (num - 1) * arr->col;
			while(j < trans->row * num)
			{
				matrix->data[i] += arr->data[j] * trans->data[k];
				k += trans->col;
				j++;
			}
			k -= trans->row * trans->col - 1;
			i++;
		}
		k = 0;
		num++;
	}
	return (matrix);
}

	// working for 2x4 n 4x3
	// 	while (num <= arr->row)
	// {
	// 	while (i < trans->col * num)
	// 	{
	// 		j = (num - 1) * arr->col;
	// 		while(j < trans->row * num)
	// 		{
	// 			matrix->data[i] += arr->data[j] * trans->data[k];
	// 			printf("(arr->data[%i] = %i ) * ", (int)j, (int)arr->data[j]);
	// 			printf("(trans->data[%i] = %i)", (int)k, (int)trans->data[k]);
	// 			printf(" = matrix->data[%i] = %i\n", (int)i, (int)matrix->data[i]);
	// 			k += trans->col;
	// 			j++;
	// 		}
	// 		k -= trans->row * trans->col - 1;
	// 		i++;
	// 	}
	// 	k = 0;
	// 	num++;
	// }

	// while (num <= arr->row)
	// {
	// 	while (i < trans->col * num)
	// 	{
	// 		j = (num - 1) * trans->col;
	// 		while(j < trans->col * num)
	// 		{
	// 			matrix->data[i] += arr->data[j] * trans->data[k];
	// 			printf("(arr->data[%i] = %i ) *", (int)j, (int)arr->data[j]);
	// 			printf("(trans->data[%i] = %i)", (int)k, (int)trans->data[k]);
	// 			printf(" = matrix->data[%i] = %i\n", (int)i, (int)matrix->data[i]);
	// 			k += trans->col;
	// 			j++;
	// 		}
	// 		k -= trans->row * trans->col - 1;
	// 		i++;
	// 	}
	// 	k = 0;
	// 	num++;
	// }

	// while (i < trans->col * 1)
	// {
	// 	j = (num - 1) * trans->col;
	// 	while(j < trans->col * 1)
	// 	{
	// 		matrix->data[i] += arr->data[j] * trans->data[k];
	// 		printf("(arr->data[%i] = %i ) *", (int)j, (int)arr->data[j]);
	// 		printf("(trans->data[%i] = %i)", (int)k, (int)trans->data[k]);
	// 		printf(" = matrix->data[%i] = %i\n", (int)i, (int)matrix->data[i]);
			
	// 		k += trans->col;
	// 		j++;
	// 	}
	// 	k -= trans->row * trans->col - 1;
	// 	i++;
	// }
	// k = 0;
	// num++;
	// while (i < trans->col * num)
	// {
	// 	j = (num - 1) * trans->col;
	// 	while(j < trans->col * num)
	// 	{
	// 		matrix->data[i] += arr->data[j] * trans->data[k];
	// 		printf("(arr->data[%i] = %i ) *", (int)j, (int)arr->data[j]);
	// 		printf("(trans->data[%i] = %i)", (int)k, (int)trans->data[k]);
	// 		printf(" = matrix->data[%i] = %i\n", (int)i, (int)matrix->data[i]);
			
	// 		k += trans->col;
	// 		j++;
	// 	}
	// 	k -= trans->row * trans->col - 1;
	// 	i++;
	// }
	// k = 0;
	// num++;
	// while (i < trans->col * num)
	// {
	// 	j = (num - 1) * trans->col;
	// 	while(j < trans->col * num)
	// 	{
	// 		matrix->data[i] += arr->data[j] * trans->data[k];
	// 		printf("(arr->data[%i] = %i ) *", (int)j, (int)arr->data[j]);
	// 		printf("(trans->data[%i] = %i)", (int)k, (int)trans->data[k]);
	// 		printf(" = matrix->data[%i] = %i\n", (int)i, (int)matrix->data[i]);
	// 		k += trans->col;
	// 		j++;
			
	// 	}
	// 	k -= trans->row * trans->col - 1;
	// 	i++;
	// }

void	print_matrix(t_matrix *matrix)
{
	int	i = -1;

	while (++i < matrix->row * matrix->col)
		printf("%i ", (int)matrix->data[i]);
}

int	main(void)
{
	// t_matrix	*arr;
	// t_matrix	*trans;
	// t_matrix	*res;
	t_matrix	*arr2;
	t_matrix	*trans2;
	t_matrix	*res2;
	t_matrix	*identity_mat;
	int			i = -1;
	int			j = -1;

	// arr = ft_matrix_new(1, 4);
	// trans = ft_matrix_new(4, 4);
	arr2 = ft_matrix_new(2, 3);
	trans2 = ft_matrix_new(3, 4);
	// identity_mat = ft_mat_identity(4);
	while (++i < 6)
		arr2->data[i] = i;
	while (++j < 12)
		trans2->data[j] = j + 1;
	printf("arr2 ");
	print_matrix(arr2);
	printf("\n");
	printf("trans2 ");
	print_matrix(trans2);
	printf("\n");
	res2 = matrix_multiplication(arr2, trans2);
	printf("res2 ");
	print_matrix(res2);
	printf("\n");
	ft_matrix_del(arr2);
	ft_matrix_del(trans2);
	ft_matrix_del(res2);
	// printf("identitymat ");
	// print_matrix(identity_mat);
	// printf("\n");
	// res = matrix_multiplication(arr, trans);
	// ft_matrix_del(arr);
	// ft_matrix_del(trans);
	// ft_matrix_del(res);
	// ft_matrix_del(identity_mat);
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
