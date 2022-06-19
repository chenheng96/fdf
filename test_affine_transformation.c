/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_affine_transformation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:08:02 by cchong            #+#    #+#             */
/*   Updated: 2022/06/19 09:08:40 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
To print out the matrix.
*/
void	print_mat(t_mat *mat)
{
	size_t	i = -1;

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
	size_t	i;

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

void	test_ft_translate1(void)
{
	t_mat	*A;
	t_mat	*B;
	t_mat	*C;
	size_t	i;

	i = -1;
	A = ft_mat_new(4, 1);
	C = ft_mat_new(4, 1);
	while (++i < 4)
		A->data[i] = i + 1;
	B = ft_translate(A, 10, 15, 0);
    C->data[0] = 41;
	C->data[1] = 62;
	C->data[2] = 3;
	C->data[3] = 4;
	if (compare_mat(B, C) == 1)
		printf("ft_translate test 1: KO\n");
	else
		printf("ft_translate test 1: OK\n");
	ft_mat_del(A);
	ft_mat_del(B);
	ft_mat_del(C);
}

void	test_ft_translate2(void)
{
	t_mat	*A;
	t_mat	*B;
	t_mat	*C;
	size_t	i;

	i = -1;
	A = ft_mat_new(4, 1);
	C = ft_mat_new(4, 1);
	while (++i < 4)
		A->data[i] = i + 1;
	B = ft_translate(A, 0, 5, 3);
    C->data[0] = 1;
	C->data[1] = 22;
	C->data[2] = 15;
	C->data[3] = 4;
	if (compare_mat(B, C) == 1)
		printf("ft_translate test 2: KO\n");
	else
		printf("ft_translate test 2: OK\n");
	ft_mat_del(A);
	ft_mat_del(B);
	ft_mat_del(C);
}

void	test_ft_translate3(void)
{
	t_mat	*A;
	t_mat	*B;
	t_mat	*C;
	size_t	i;

	i = -1;
	A = ft_mat_new(4, 1);
	C = ft_mat_new(4, 1);
	while (++i < 4)
		A->data[i] = i + 1;
	B = ft_translate(A, 4, 0, 7);
    C->data[0] = 17;
	C->data[1] = 2;
	C->data[2] = 31;
	C->data[3] = 4;
	if (compare_mat(B, C) == 1)
		printf("ft_translate test 3: KO\n");
	else
		printf("ft_translate test 3: OK\n");
	ft_mat_del(A);
	ft_mat_del(B);
	ft_mat_del(C);
}

void	test_ft_scale1(void)
{
	t_mat	*A;
	t_mat	*B;
	t_mat	*C;

	A = ft_mat_new(4, 1);
	C = ft_mat_new(4, 1);
	A->data[0] = 10;
    A->data[1] = 22;
    A->data[2] = 58;
    A->data[3] = 81;
	B = ft_scale(A, 4, 1, 7);
    C->data[0] = 40;
	C->data[1] = 22;
	C->data[2] = 406;
	C->data[3] = 81;
	if (compare_mat(B, C) == 1)
		printf("ft_scale test 1: KO\n");
	else
		printf("ft_scale test 1: OK\n");
	ft_mat_del(A);
	ft_mat_del(B);
	ft_mat_del(C);
}

void	test_ft_scale2(void)
{
	t_mat	*A;
	t_mat	*B;
	t_mat	*C;

	A = ft_mat_new(4, 1);
	C = ft_mat_new(4, 1);
	A->data[0] = 10;
    A->data[1] = 22;
    A->data[2] = 58;
    A->data[3] = 81;
	B = ft_scale(A, 10, 5, 3);
    C->data[0] = 100;
	C->data[1] = 110;
	C->data[2] = 174;
	C->data[3] = 81;
	if (compare_mat(B, C) == 1)
		printf("ft_scale test 2: KO\n");
	else
		printf("ft_scale test 2: OK\n");
	ft_mat_del(A);
	ft_mat_del(B);
	ft_mat_del(C);
}

void	test_ft_scale3(void)
{
	t_mat	*A;
	t_mat	*B;
	t_mat	*C;

	A = ft_mat_new(4, 1);
	C = ft_mat_new(4, 1);
	A->data[0] = 10;
    A->data[1] = 22;
    A->data[2] = 58;
    A->data[3] = 81;
	B = ft_scale(A, 3, 10, 90);
    C->data[0] = 30;
	C->data[1] = 220;
	C->data[2] = 5220;
	C->data[3] = 81;
	if (compare_mat(B, C) == 1)
		printf("ft_scale test 3: KO\n");
	else
		printf("ft_scale test 3: OK\n");
	ft_mat_del(A);
	ft_mat_del(B);
	ft_mat_del(C);
}

int main(void)
{
    test_ft_translate1();
    test_ft_translate2();
    test_ft_translate3();
    test_ft_scale1();
    test_ft_scale2();
    test_ft_scale3();
}
