/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:47:24 by cchong            #+#    #+#             */
/*   Updated: 2022/06/03 14:08:05 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	abs(int n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

void	draw_line_low(double x0, double y0, double x1, double y1)
{
	size_t	dx;
	size_t	dy;
	size_t	yi;
	size_t	D;
	size_t	x;

	x = -1;
	dx = x1 - x0;
	dy = y1 - y0;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	D = (2 * dy) - dx;
	y = y0;
	while (++x < x1)
	{
		plox(x, y);
		if (D > 0)
		{
			y += yi;
			D += (2 * (dy - dx));
		}
		else
			D += 2 * dy;
	}
}

void	draw_line_high(double x0, double y0, double x1, double y1)
{
	size_t	dx;
	size_t	dy;
	size_t	yi;
	size_t	D;
	size_t	y;

	y = -1;
	dx = x1 - x0;
	dy = y1 - y0;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	D = (2 * dx) - dy;
	x = x0;
	while (++y < y1)
	{
		plox(x, y);
		if (D > 0)
		{
			x += xi;
			D += (2 * (dx - dy));
		}
		else
			D += 2 * dx;
	}
}

void	draw_line(double x0, double y0, double x1, double y1)
{
	if (abs(y1 - y0) < abs(x1-x0))
	{
		if (x0 > x1)
			draw_line_low(x1, y1, x0, y0);
		else
			draw_line_low(x0, y0, x1, y1);
	}
	else
		if (y0 > y1)
			draw_line_high(x1, y1, x0, y0);
		else
			draw_line_high(x0, y0, x1, y1);
}