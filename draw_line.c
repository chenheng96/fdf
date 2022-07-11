/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:47:24 by cchong            #+#    #+#             */
/*   Updated: 2022/07/11 15:57:52 by cchong           ###   ########.fr       */
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

	if (vars->x0 >= 0 && vars->x0 < WIDTH && vars->y0 >= 0
		&& vars->y0 < HEIGHT)
	{
		dst = vars->addr + (y * vars->line_length + x
				* (vars->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

/*
To draw line with less than 1 gradient.
*/
void	draw_line_low(t_vars *vars)
{
	int	yi;
	int	d;

	vars->dx = vars->x1 - vars->x0;
	vars->dy = vars->y1 - vars->y0;
	yi = 1;
	if (vars->dy < 0)
	{
		yi = -1;
		vars->dy = -vars->dy;
	}
	d = (2 * vars->dy) - vars->dx;
	while (vars->x0 <= vars->x1)
	{
		my_mlxpixelput(vars, vars->x0, vars->y0, 0x00FF0000);
		if (d > 0)
		{
			vars->y0 += yi;
			d += (2 * (vars->dy - vars->dx));
		}
		else
			d += 2 * vars->dy;
		vars->x0++;
	}
}

/*
To draw line with more than 1 gradient.
*/
void	draw_line_high(t_vars *vars)
{
	int	xi;
	int	d;

	vars->dx = vars->x1 - vars->x0;
	vars->dy = vars->y1 - vars->y0;
	xi = 1;
	if (vars->dx < 0)
	{
		xi = -1;
		vars->dx = -vars->dx;
	}
	d = (2 * vars->dx) - vars->dy;
	while (vars->y0 <= vars->y1)
	{
		my_mlxpixelput(vars, vars->x0, vars->y0, 0x00FF0000);
		if (d > 0)
		{
			vars->x0 += xi;
			d += (2 * (vars->dx - vars->dy));
		}
		else
			d += 2 * vars->dx;
		vars->y0++;
	}
}

/*
To check if first coordinates is before or after second coordinates.
Then, call draw_line_low/high accordingly.
*/
void	draw_line(t_vars *vars)
{
	if (abs(vars->y1 - vars->y0) < abs(vars->x1 - vars->x0))
	{
		if (vars->x0 > vars->x1)
		{
			swap_xy(vars);
			draw_line_low(vars);
		}
		else
			draw_line_low(vars);
	}
	else
	{
		if (vars->y0 > vars->y1)
		{
			swap_xy(vars);
			draw_line_high(vars);
		}
		else
			draw_line_high(vars);
	}
}
