/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:47:24 by cchong            #+#    #+#             */
/*   Updated: 2022/06/27 14:59:57 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
To return the absolute value of int.
*/
int	abs(int n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

/*
To plot pixel in an image.
*/
void	my_mlxpixelput(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
To draw line with less than 1 gradient.
*/
void	draw_line_low(t_data *data, t_vars *vars)
{
	my_mlxpixelput(vars, 10, 10, 0xFF0000);
	data->x = -1;
	data->dx = data->x1 - data->x0;
	data->dy = data->y1 - data->y0;
	data->yi = 1;
	if (data->dy < 0)
	{
		data->yi = -1;
		data->dy = -data->dy;
	}
	data->D = (2 * data->dy) - data->dx;
	data->y = data->y0;
	while (++data->x < data->x1)
	{
		my_mlxpixelput(vars, data->x, data->y, 0x00FF0000);
		if (data->D > 0)
		{
			data->y += data->yi;
			data->D += (2 * (data->dy - data->dx));
		}
		else
			data->D += 2 * data->dy;
	}
}

/*
To draw line with more than 1 gradient.
*/
void	draw_line_high(t_data *data, t_vars *vars)
{
	my_mlxpixelput(vars, 20, 20, 0xFF0000);
	data->y = -1;
	data->dx = data->x1 - data->x0;
	data->dy = data->y1 - data->y0;
	data->xi = 1;
	if (data->dx < 0)
	{
		data->xi = -1;
		data->dx = -data->dx;
	}
	data->D = (2 * data->dx) - data->dy;
	data->x = data->x0;
	while (++data->y < data->y1)
	{
		my_mlxpixelput(vars, data->x, data->y, 0x00FF0000);
		if (data->D > 0)
		{
			data->x += data->xi;
			data->D += (2 * (data->dx - data->dy));
		}
		else
			data->D += 2 * data->dx;
	}
}

/*
To check if first coordinates is before or after second coordinates.
Then, call draw_line_low/high accordingly.
*/
void	draw_line(t_data *data, t_vars *vars)
{
	if (abs(data->y1 - data->y0) < abs(data->x1 - data->x0))
	{
		if (data->x0 > data->x1)
			draw_line_low(data, vars);
		else
			draw_line_low(data, vars);
	}
	else
		if (data->y0 > data->y1)
			draw_line_high(data, vars);
		else
			draw_line_high(data, vars);
}
