/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_affine_transformation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:08:02 by cchong            #+#    #+#             */
/*   Updated: 2022/06/20 14:16:14 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
To print out the matrix.
*/
void	print_mat(t_mat *mat)
{
	size_t	i = -1;

	printf("row:%li col:%li\n", mat->row, mat->col);
	while (++i < mat->row * mat->col)
	{
		printf("%f ", mat->data[i]);
		if((i + 1) % mat->col == 0)
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
	{
		printf("A row:%li A col:%li B row:%li B col:%li\n", A->row, A->col, B->row, B->col);
		return (1);
	}
	while (++i < A->row * A->col)
	{
		if (A->data[i] != B->data[i])
		{
			printf("A[%li]: %f B[%li]: %f\n", i, A->data[i], i, B->data[i]);
			printf("A[%li]: %lf B[%li]: %lf\n", i, A->data[i], i, B->data[i]);
			printf("A[%li]: %g B[%li]: %g\n", i, A->data[i], i, B->data[i]);
			printf("A[%li]: %e B[%li]: %e\n", i, A->data[i], i, B->data[i]);
			return (1);
		}
	}
	return (0);
}

void	test_ft_translate1(void)
{
	t_mat	*A; //point
	t_mat	*B; //trans mat
	t_mat	*C; //correct ans
	t_mat	*D; //res of mul of AB
	size_t	i;

	i = -1;
	A = ft_mat_new(4, 1);
	C = ft_mat_new(4, 1);
	while (++i < 4)
		A->data[i] = i + 1;
	B = ft_translate(10, 15, 0);
    C->data[0] = 41;
	C->data[1] = 62;
	C->data[2] = 3;
	C->data[3] = 4;
	D = ft_mat_mul(B, A);
	if (compare_mat(C, D) == 1)
		printf("ft_translate test 1: KO\n");
	else
		printf("ft_translate test 1: OK\n");
	ft_mat_del(A);
	ft_mat_del(B);
	ft_mat_del(C);
	ft_mat_del(D);
}

void	test_ft_translate2(void)
{
	t_mat	*A; //point
	t_mat	*B; //trans mat
	t_mat	*C; //correct ans
	t_mat	*D; //res of mul of AB
	size_t	i;

	i = -1;
	A = ft_mat_new(4, 1);
	C = ft_mat_new(4, 1);
	while (++i < 4)
		A->data[i] = i + 1;
	B = ft_translate(0, 5, 3);
    C->data[0] = 1;
	C->data[1] = 22;
	C->data[2] = 15;
	C->data[3] = 4;
	D = ft_mat_mul(B, A);
	if (compare_mat(C, D) == 1)
		printf("ft_translate test 2: KO\n");
	else
		printf("ft_translate test 2: OK\n");
	ft_mat_del(A);
	ft_mat_del(B);
	ft_mat_del(C);
	ft_mat_del(D);
}

void	test_ft_translate3(void)
{
	t_mat	*A; //point
	t_mat	*B; //trans mat
	t_mat	*C; //correct ans
	t_mat	*D; //res of mul of AB
	size_t	i;

	i = -1;
	A = ft_mat_new(4, 1);
	C = ft_mat_new(4, 1);
	while (++i < 4)
		A->data[i] = i + 1;
	B = ft_translate(4, 0, 7);
    C->data[0] = 17;
	C->data[1] = 2;
	C->data[2] = 31;
	C->data[3] = 4;
	D = ft_mat_mul(B, A);
	if (compare_mat(C, D) == 1)
		printf("ft_translate test 3: KO\n");
	else
		printf("ft_translate test 3: OK\n");
	ft_mat_del(A);
	ft_mat_del(B);
	ft_mat_del(C);
	ft_mat_del(D);
}

void	test_ft_scale1(void)
{
	t_mat	*A; //point
	t_mat	*B; //trans mat
	t_mat	*C; //correct ans
	t_mat	*D; //res of mul of AB

	A = ft_mat_new(4, 1);
	C = ft_mat_new(4, 1);
	A->data[0] = 10;
    A->data[1] = 22;
    A->data[2] = 58;
    A->data[3] = 81;
	B = ft_scale(4, 1, 7);
    C->data[0] = 40;
	C->data[1] = 22;
	C->data[2] = 406;
	C->data[3] = 81;
	D = ft_mat_mul(B, A);
	if (compare_mat(C, D) == 1)
		printf("ft_scale test 1: KO\n");
	else
		printf("ft_scale test 1: OK\n");
	ft_mat_del(A);
	ft_mat_del(B);
	ft_mat_del(C);
	ft_mat_del(D);
}

void	test_ft_scale2(void)
{
	t_mat	*A; //point
	t_mat	*B; //trans mat
	t_mat	*C; //correct ans
	t_mat	*D; //res of mul of AB

	A = ft_mat_new(4, 1);
	C = ft_mat_new(4, 1);
	A->data[0] = 10;
    A->data[1] = 22;
    A->data[2] = 58;
    A->data[3] = 81;
	B = ft_scale(10, 5, 3);
    C->data[0] = 100;
	C->data[1] = 110;
	C->data[2] = 174;
	C->data[3] = 81;
	D = ft_mat_mul(B, A);
	if (compare_mat(C, D) == 1)
		printf("ft_scale test 2: KO\n");
	else
		printf("ft_scale test 2: OK\n");
	ft_mat_del(A);
	ft_mat_del(B);
	ft_mat_del(C);
	ft_mat_del(D);
}

void	test_ft_scale3(void)
{
	t_mat	*A; //point
	t_mat	*B; //trans mat
	t_mat	*C; //correct ans
	t_mat	*D; //res of mul of AB

	A = ft_mat_new(4, 1);
	C = ft_mat_new(4, 1);
	A->data[0] = 10;
    A->data[1] = 22;
    A->data[2] = 58;
    A->data[3] = 81;
	B = ft_scale(3, 10, 90);
    C->data[0] = 30;
	C->data[1] = 220;
	C->data[2] = 5220;
	C->data[3] = 81;
	D = ft_mat_mul(B, A);
	if (compare_mat(C, D) == 1)
		printf("ft_scale test 3: KO\n");
	else
		printf("ft_scale test 3: OK\n");
	ft_mat_del(A);
	ft_mat_del(B);
	ft_mat_del(C);
	ft_mat_del(D);
}

void	test_ft_shear1(void)
{
	t_mat	*A; //point
	t_mat	*B; //trans mat
	t_mat	*C; //correct ans
	t_mat	*D; //res of mul of AB

	A = ft_mat_new(4, 1);
	C = ft_mat_new(4, 1);
	A->data[0] = 10;
    A->data[1] = 22;
    A->data[2] = 58;
    A->data[3] = 81;
	B = ft_shear(3, 10, 90);
    C->data[0] = 16330;
	C->data[1] = 52522;
	C->data[2] = 22558;
	C->data[3] = 81;
	D = ft_mat_mul(B, A);
	if (compare_mat(C, D) == 1)
		printf("ft_shear test 1: KO\n");
	else
		printf("ft_shear test 1: OK\n");
	ft_mat_del(A);
	ft_mat_del(B);
	ft_mat_del(C);
	ft_mat_del(D);
}

void	test_ft_shear2(void)
{
	t_mat	*A; //point
	t_mat	*B; //trans mat
	t_mat	*C; //correct ans
	t_mat	*D; //res of mul of AB

	A = ft_mat_new(4, 1);
	C = ft_mat_new(4, 1);
	A->data[0] = 10;
    A->data[1] = 22;
    A->data[2] = 58;
    A->data[3] = 81;
	B = ft_shear(0.5, 2.5, 1.5);
    C->data[0] = 81;
	C->data[1] = 252;
	C->data[2] = 148;
	C->data[3] = 81;
	D = ft_mat_mul(B, A);
	if (compare_mat(C, D) == 1)
		printf("ft_shear test 2: KO\n");
	else
		printf("ft_shear test 2: OK\n");
	ft_mat_del(A);
	ft_mat_del(B);
	ft_mat_del(C);
	ft_mat_del(D);
}

void	test_ft_shear3(void)
{
	t_mat	*A; //correct trans mat
	t_mat	*B; //trans mat

	A = ft_mat_identity(4);
	ft_set_val(A, 0, 1, 0.55);
	ft_set_val(A, 1, 0, 0.55);
	ft_set_val(A, 0, 2, 1.1 * 2.7); // 1.1 * 2.7 works
	ft_set_val(A, 2, 0, 2.97); // 2.97 does not work
	ft_set_val(A, 1, 2, 1.35);
	ft_set_val(A, 2, 1, 1.35);
	B = ft_shear(1.1, 0.5, 2.7);
	if (compare_mat(A, B) == 1)
		printf("ft_shear test 3: KO\n");
	else
		printf("ft_shear test 3: OK\n");
	ft_mat_del(A);
	ft_mat_del(B);
}

void	test_ft_shear4(void)
{
	t_mat	*A; //correct trans mat
	t_mat	*B; //trans mat
	double	x;
	double	y;
	double	z;

	x = 0.75;
	y = 1.23;
	z = 3.334;
	A = ft_mat_identity(4);
	ft_set_val(A, 0, 1, 0.9225); // xy = 0.9225
	ft_set_val(A, 1, 0, x * y);
	ft_set_val(A, 0, 2, 2.5005); // xz = 2.5005
	ft_set_val(A, 2, 0, x * z);
	ft_set_val(A, 1, 2, 4.10082); // yz = 4.10082
	ft_set_val(A, 2, 1, y * z);
	B = ft_shear(x, y, z);
	if (compare_mat(A, B) == 1)
		printf("ft_shear test 4: KO\n");
	else
		printf("ft_shear test 4: OK\n");
	ft_mat_del(A);
	ft_mat_del(B);
}

int main(void)
{
    test_ft_translate1();
    test_ft_translate2();
    test_ft_translate3();
    test_ft_scale1();
    test_ft_scale2();
    test_ft_scale3();
	test_ft_shear1();
	test_ft_shear2();
	test_ft_shear3();
	test_ft_shear4();
}
