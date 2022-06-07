/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:47:06 by cchong            #+#    #+#             */
/*   Updated: 2022/06/07 14:44:06 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlxpixelput(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	handle_key(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	else
		ft_putnbr_fd(keycode, 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_data	data;
	char	**map;
	int		**map_coor;

	if (argc != 2)
	{
		ft_putnbr_fd("Usage:./fdf map", 1);
		return (-1);
	}
	if (parse_map(argv[1], map, data) == -1)
		return (-1);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FDF");
	vars.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel,
			&vars.line_length, &vars.endian);
	fill_map(map, data, vars);
	data.x0 = 100;
	data.y0 = 100;
	data.x1 = 50;
	data.y1 = 50;
	draw_line1(&data, &vars, 0xFF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_hook(vars.win, 2, 1L << 0, handle_key, &vars);
	mlx_loop(vars.mlx);
}
