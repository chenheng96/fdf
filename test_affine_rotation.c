/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_affine_rotation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:39:23 by cchong            #+#    #+#             */
/*   Updated: 2022/06/20 15:05:55 by cchong           ###   ########.fr       */
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

void	test_ft_rotate_x(void)
{
	t_mat	*A; //correct trans mat
	t_mat	*B; //trans mat
	double	x;

	x = 0;
	while (x <= 45)
	{
		A = ft_mat_identity(4);
		ft_set_val(A, 1, 1, cos(x));
		ft_set_val(A, 1, 2, -sin(x));
		ft_set_val(A, 2, 1, sin(x));
		ft_set_val(A, 2, 2, cos(x));
		B = ft_rotate_x(x);
		if (compare_mat(A, B) == 1)
			printf("ft_rotate_x test %f: KO\n", x);
		// else
		// 	printf("ft_rotate_x test %f: OK\n", x);
		ft_mat_del(A);
		ft_mat_del(B);
		x += 0.1;
	}
}

void	test_ft_rotate_y(void)
{
	t_mat	*A; //correct trans mat
	t_mat	*B; //trans mat
	double	y;

	y = 0;
	while (y <= 45)
	{
		A = ft_mat_identity(4);
		ft_set_val(A, 0, 0, cos(y));
		ft_set_val(A, 0, 2, sin(y));
		ft_set_val(A, 2, 0, -sin(y));
		ft_set_val(A, 2, 2, cos(y));
		B = ft_rotate_y(y);
		if (compare_mat(A, B) == 1)
			printf("ft_rotate_y test %f: KO\n", y);
		// else
		// 	printf("ft_rotate_y test %f: OK\n", y);
		ft_mat_del(A);
		ft_mat_del(B);
		y += 0.1;
	}
}

void	test_ft_rotate_z(void)
{
	t_mat	*A; //correct trans mat
	t_mat	*B; //trans mat
	double	z;
	
	z = 0;
	while (z <= 45)
	{
		A = ft_mat_identity(4);
		ft_set_val(A, 0, 0, cos(z));
		ft_set_val(A, 0, 1, -sin(z));
		ft_set_val(A, 1, 0, sin(z));
		ft_set_val(A, 1, 1, cos(z));
		B = ft_rotate_z(z);
		if (compare_mat(A, B) == 1)
			printf("ft_rotate_z test %f: KO\n", z);
		// else
		// 	printf("ft_rotate_z test %f: OK\n", z);
		ft_mat_del(A);
		ft_mat_del(B);
		z += 0.1;
	}
}

int	main(void)
{
	test_ft_rotate_x();
	test_ft_rotate_y();
	test_ft_rotate_z();
}