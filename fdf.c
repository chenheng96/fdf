/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:47:06 by cchong            #+#    #+#             */
/*   Updated: 2022/06/27 14:57:46 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_vars	*vars;
	t_data	*data;
	t_map	*map;

	(void)argv;
	if (argc != 2)
		ft_perror("Usage:./fdf map\n");
	map = ft_malloc(sizeof(t_map));
	map->transform = ft_mat_identity(4);
	vars = ft_malloc(sizeof(t_vars));
	data = ft_malloc(sizeof(t_data));
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "FDF");
	vars->img = mlx_new_image(vars->mlx, 1920, 1080);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	open_file(argv[1], map);
	connect_dot(data, vars, map);
	// my_mlxpixelput(vars, 5, 5, 0xFF0000);
	// my_mlxpixelput(vars, 10, 10, 0xFF0000);
	// my_mlxpixelput(vars, 20, 20, 0xFF0000);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_hook(vars->win, 2, 1L << 0, handle_key, vars);
	mlx_loop(vars->mlx);
}
