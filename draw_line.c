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

void	draw_line1(t_data *data, t_vars *vars, int color)
{
	data->sx = -1;
	data->sy = -1;
	data->dx = abs(data->x1 - data->x0);
	data->dy = -abs(data->y1 - data->y0);
	if (data->x1 > data->x0)
		data->sx = 1;
	if (data->y1 > data->y0)
		data->sy = 1;
	data->error = data->dx + data->dy;
	draw_line2(data, vars, color);
}

void	draw_line2(t_data *data, t_vars *vars, int color)
{
	while (1)
	{
		my_mlxpixelput(vars, data->x0, data->y0, color);
		if (data->x0 == data->x1 && data->y0 == data->y1)
			break ;
		data->e2 = 2 * data->error;
		if (data->e2 >= data->dy)
		{
			if (data->x0 == data->x1)
				break ;
			data->error += data->dy;
			data->x0 += data->sx;
		}
		if (data->e2 <= data->dx)
		{
			if (data->y0 == data->y1)
				break ;
			data->error += data->dx;
			data->y0 += data->sy;
		}
	}
}
