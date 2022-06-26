/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:47:06 by cchong            #+#    #+#             */
/*   Updated: 2022/06/24 15:44:51 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
To free the variables in vars struct and free vars.
*/
void	ft_vars_del(t_vars *vars)
{
	free(vars->addr);
	free(vars->mlx);
	free(vars);
}

/*
To multiply the map->map[k] with trans mat and put the new frame onto the window.
Also reset the transform mat after transforming map->map[k].
*/
void    new_frame(t_data *data, t_vars *vars, t_map *map)
{
    size_t	k;
	t_mat	*temp;

	k = -1;
	vars->img = mlx_new_image(vars->mlx, 1920, 1080);
	while (++k < map->row * map->col)
	{
		temp = ft_mat_mul(map->transform, map->map[k]);
		ft_mat_del(map->map[k]);
		map->map[k] = temp;
	}
	ft_mat_del(map->transform);
	map->transform = ft_mat_identity(4);
	connect_dot(data, vars, map);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	free(vars->img);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;
	t_data	*data;
	t_map	*map;

	if (argc != 2)
		ft_perror("Usage:./fdf map\n");
	map = ft_malloc(sizeof(t_map));
	map->transform = ft_mat_identity(4);
	vars = ft_malloc(sizeof(t_vars));
	data = ft_malloc(sizeof(t_data));
	open_file(argv[1], map);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "FDF");
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	new_frame(data, vars, map);
	mlx_hook(vars->win, 2, 1L << 0, handle_key, vars);
	mlx_loop(vars->mlx);
}
