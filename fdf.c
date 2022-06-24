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
	(void)vars;
	free(vars->addr);
	free(vars->mlx);
	free(vars->img);
	free(vars);
}

/*
To put pixel in an image.
*/
void	my_mlxpixelput(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
To handle events when key is pressed.
*/
int	handle_key(int keycode, t_vars *vars, t_map *map, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		// ft_map_del(map);
		// ft_vars_del(vars);
		// free(data);
		exit(EXIT_SUCCESS);
	}
	else
		ft_putnbr_fd(keycode, 1);
	return (0);
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
	data->x0 = 500;
	data->y0 = 500;
	data->x1 = 1000;
	data->y1 = 1000;
	open_file(argv[1], map);
	fill_map(map);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "FDF");
	vars->img = mlx_new_image(vars->mlx, 1920, 1080);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	draw_line(data, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_hook(vars->win, 2, 1L << 0, handle_key, vars);
	mlx_loop(vars->mlx);
}
