#include "fdf.h"
#include <stdio.h>

void	print_matrix(t_matrix *matrix)
{
	int	i = -1;

	while (++i < matrix->row * matrix->col)
		printf("%i ", (int)matrix->data[i]);
	printf("\n");
}

int	main(void)
{
	t_matrix	*arr1;
	t_matrix	*trans1;
	t_matrix	*res1;
	t_matrix	*arr2;
	t_matrix	*trans2;
	t_matrix	*res2;
	t_matrix	*identity_mat;
	t_matrix	*identity_mat2;
	int			i = -1;
	int			j = -1;

	// arr1 = ft_matrix_new(1, 4);
	// trans1 = ft_matrix_new(4, 4);
	// while (++i < 4)
	// 	arr1->data[i] = i;
	// while (++j < 16)
	// 	trans1->data[j] = j + 1;
	// printf("arr1 ");
	// print_matrix(arr1);
	// printf("trans1 ");
	// print_matrix(trans1);
	// res1 = matrix_multiplication(arr1, trans1);
	// printf("res1 ");
	// print_matrix(res1);
	// ft_matrix_del(arr1);
	// ft_matrix_del(trans1);
	// ft_matrix_del(res1);

	arr2 = ft_matrix_new(2, 3);
	trans2 = ft_matrix_new(3, 4);
	i = -1;
	j = -1;
	while (++i < 6)
		arr2->data[i] = i;
	while (++j < 12)
		trans2->data[j] = j + 1;
	printf("arr2 ");
	print_matrix(arr2);
	printf("trans2 ");
	print_matrix(trans2);
	res2 = matrix_multiplication(arr2, trans2);
	// 23 26 29 32 68 80 92 104
	printf("res2 ");
	print_matrix(res2);
	get_element(res2, 1, 3);
	update_element(res2, 1, 3, 10);
	get_element(res2, 1, 3);
	ft_matrix_del(arr2);
	ft_matrix_del(trans2);
	ft_matrix_del(res2);

	// identity_mat = ft_mat_identity(2);
	// printf("identitymat ");
	// print_matrix(identity_mat);
	// ft_matrix_del(identity_mat);

	// identity_mat2 = ft_mat_identity(5);
	// printf("identitymat2 ");
	// print_matrix(identity_mat2);
	// ft_matrix_del(identity_mat2);

}
