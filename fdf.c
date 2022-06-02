/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:47:06 by cchong            #+#    #+#             */
/*   Updated: 2022/06/02 16:52:59 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

int	abs(int	n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

void	my_mlxpixelput(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_line(int x0, int y0, int x1, int y1, t_vars *data)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int error;
	int e2;

	sx = 0;
	sy = 0;
	dx = abs(x1 - x0);
	dy = -abs(y1 - y0);
	if (x1 > x0)
		sx = 1;
	if (y1 > y0)
		sy = 1;
	error = dx + dy;
	while (1)
	{
		my_mlxpixelput(data, x0, y0, 0xFF0000);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * error;
		if (e2 >= dy)
		{
			if (x0 == x1)
				break ;
			error += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			if (y0 == y1)
				break ;
			error += dx;
			y0 += sy;
		}
	}
}

int	handle_key(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	else
		ft_putnbr_fd(keycode, 1);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "FDF");
	vars.img = mlx_new_image(vars.mlx, 1000, 1000);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
	draw_line(100, 100, 400, 200, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, handle_key, &vars);
	mlx_loop(vars.mlx);
}
