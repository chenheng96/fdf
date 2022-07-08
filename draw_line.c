/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:47:24 by cchong            #+#    #+#             */
/*   Updated: 2022/07/08 11:16:06 by cchong           ###   ########.fr       */
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
void	draw_line_low(t_vars *vars)
{
	int	yi;
	int	dx;
	int	dy;
	int	d;

	dx = vars->x1 - vars->x0;
	dy = vars->y1 - vars->y0;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = (2 * dy) - dx;
	while (++vars->x0 < vars->x1)
	{
		if (vars->x0 >= 0 && vars->x0 < WIDTH && vars->y0 >= 0 && vars->y0 < HEIGHT)
			my_mlxpixelput(vars, vars->x0, vars->y0, 0x00FF0000);
		if (d > 0)
		{
			vars->y0 += yi;
			d += (2 * (dy - dx));
		}
		else
			d += 2 * dy;
	}
}

/*
To draw line with more than 1 gradient.
*/
void	draw_line_high(t_vars *vars)
{
	int	xi;
	int	dx;
	int	dy;
	int	d;

	dx = vars->x1 - vars->x0;
	dy = vars->y1 - vars->y0;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	d = (2 * dx) - dy;
	while (++vars->y0 < vars->y1)
	{
		if (vars->x0 >= 0 && vars->x0 < WIDTH && vars->y0 >= 0 && vars->y0 < HEIGHT)
			my_mlxpixelput(vars, vars->x0, vars->y0, 0x00FF0000);
		if (d > 0)
		{
			vars->x0 += xi;
			d += (2 * (dx - dy));
		}
		else
			d += 2 * dx;
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
			draw_line_low(vars);
		else
			draw_line_low(vars);
	}
	else
	{
		if (vars->y0 > vars->y1)
			draw_line_high(vars);
		else
			draw_line_high(vars);
	}
}
