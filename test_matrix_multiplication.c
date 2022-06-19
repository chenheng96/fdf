/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrix_multiplication.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 05:29:54 by cchong            #+#    #+#             */
/*   Updated: 2022/06/19 02:56:38 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

/*
To print out the matrix.
*/
void	print_mat(t_mat *mat)
{
	int	i = -1;

	while (++i < mat->row * mat->col)
	{
		printf("%i ", (int)mat->data[i]);
		if((i + 1)% mat->col == 0)
			printf("\n");
	}
}

/*
To compare the info in mat data struct.
*/
int	compare_mat(t_mat *A, t_mat *B)
{
	int	i;

	i = -1;
	if (A->row != B->row || A->col != B->col)
		return (1);
	while (++i < A->row * A->col)
	{
		if (A->data[i] != B->data[i])
			return (1);
	}
	return (0);
}

/*
To test ft_mat_new f(x).
*/
void	test_ft_mat_new(void)
{
	t_mat	*mat;
	size_t	i;

	mat = ft_mat_new(2, 3);
	if (mat->row != 2 || mat->col != 3)
	{
		printf("ft_mat_new: KO\n");
		ft_mat_del(mat);
		return ;
	}
	i = -1;
	while (++i < mat->row * mat->col)
	{
		if (mat->data[i] != 0)
		{
			printf("ft_mat_new: KO\n");
			ft_mat_del(mat);
			return ;
		}
	}
	printf("ft_mat_new: OK\n");
}

/*
To test ft_mat_identity f(x).
*/
void	test_ft_mat_identity(void)
{
	t_mat	*A;
	t_mat	*B;

	A = ft_mat_identity(3);
	B = ft_mat_new(3, 3);
	B->data[0] = 1;
	B->data[4] = 1;
	B->data[8] = 1;
	if (compare_mat(A, B) == 1)
		printf("ft_mat_identity: KO\n");
	else
		printf("ft_mat_identity: OK\n");
	ft_mat_del(A);
	ft_mat_del(B);
}

/*
Test1 of ft_mat_mul.
*/
void	test_ft_mat_mul1(void)
{
	t_mat	*A;
	t_mat	*B;
	t_mat	*C;
	t_mat	*D;
	int		i;
	int		j;

	i = -1;
	j = -1;
	A = ft_mat_new(1, 4);
	B = ft_mat_new(4, 4);
	D = ft_mat_new(1, 4);
	while (++i < 4)
		D->data[i] = 62 + (i * 6);
	i = -1;
	while (++i < 4)
		A->data[i] = i;
	while (++j < 16)
		B->data[j] = j + 1;
	C = ft_mat_mul(A, B);
	if (compare_mat(C, D) == 1)
		printf("ft_mat_mul1: KO\n");
	else
		printf("ft_mat_mul1: OK\n");
	ft_mat_del(B);
	ft_mat_del(C);
	ft_mat_del(D);
}

/*
Test2 of ft_mat_mul.
*/
void	test_ft_mat_mul2(void)
{
	t_mat	*A;
	t_mat	*B;
	t_mat	*C;
	t_mat	*D;
	int		i;
	int		j;

	i = -1;
	j = -1;
	A = ft_mat_new(3, 3);
	B = ft_mat_new(3, 4);
	D = ft_mat_new(3, 4);
	D->data[0] = 23;
	D->data[1] = 26;
	D->data[2] = 29;
	D->data[3] = 32;
	D->data[4] = 68;
	D->data[5] = 80;
	D->data[6] = 92;
	D->data[7] = 104;
	D->data[8] = 113;
	D->data[9] = 134;
	D->data[10] = 155;
	D->data[11] = 176;
	while (++i < 9)
		A->data[i] = i;
	while (++j < 12)
		B->data[j] = j + 1;
	C = ft_mat_mul(A, B);
	if (compare_mat(C, D) == 1)
		printf("ft_mat_mul2: KO\n");
	else
		printf("ft_mat_mul2: OK\n");
	ft_mat_del(B);
	ft_mat_del(C);
	ft_mat_del(D);
}

/*
Test3 of ft_mat_mul.
*/
void	test_ft_mat_mul3(void)
{
	t_mat	*A;
	t_mat	*B;
	t_mat	*C;
	t_mat	*D;
	int		i;
	int		j;

	i = -1;
	j = -1;
	A = ft_mat_new(2, 4);
	B = ft_mat_new(4, 5);
	D = ft_mat_new(2, 5);
	D->data[0] = 76;
	D->data[1] = 82;
	D->data[2] = 88;
	D->data[3] = 94;
	D->data[4] = 100;
	D->data[5] = 212;
	D->data[6] = 234;
	D->data[7] = 256;
	D->data[8] = 278;
	D->data[9] = 300;
	while (++i < 8)
		A->data[i] = i;
	while (++j < 20)
		B->data[j] = j + 1;
	C = ft_mat_mul(A, B);
	if (compare_mat(C, D) == 1)
		printf("ft_mat_mul3: KO\n");
	else
		printf("ft_mat_mul3: OK\n");
	ft_mat_del(B);
	ft_mat_del(C);
	ft_mat_del(D);
}

int	main(void)
{
	test_ft_mat_new();
	test_ft_mat_identity();
	test_ft_mat_mul1();
	test_ft_mat_mul2();
	test_ft_mat_mul3();
}
