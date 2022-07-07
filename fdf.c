/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:47:06 by cchong            #+#    #+#             */
/*   Updated: 2022/07/07 17:24:33 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 2)
		ft_perror("Usage:./fdf map\n");
	vars = ft_malloc(sizeof(t_vars));
	vars->map = ft_malloc(sizeof(t_map));
	vars->map->transform = ft_mat_identity(4);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "FDF");
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	open_file(argv[1], vars->map);
	connect_dot(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_hook(vars->win, 2, 1L << 0, handle_key, vars);
	mlx_loop(vars->mlx);
}

	// size_t i = -1;
	// while (++i < vars->map->row * vars->map->col)
	// {
	// 	print_mat(vars->map->map[i]);
	// 	printf("\n");
	// }
	// printf("row %li\ncol %li\n", vars->map->row, vars->map->col);