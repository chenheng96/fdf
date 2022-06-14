/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:11:22 by cchong            #+#    #+#             */
/*   Updated: 2022/06/14 13:57:35 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	matrix_multiplication(int arr[4], int trans[4][4], int *res)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			res[i] += arr[j] * trans[j][i];
	}
}

int	main(void)
{
	int	i;
	int arr[4] = {17, 18, 19, 20};
	int trans[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	int res[4] = {0, 0, 0, 0};

	i = -1;
	matrix_multiplication(arr, trans, res);
	while (++i < 4)
		printf("res[%i] = %i\n", i, res[i]);
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
