/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:51:06 by cchong            #+#    #+#             */
/*   Updated: 2022/07/11 15:55:07 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
To set the x0,y0,x1,y1 in vars struct to coordinates of point a and point b.
*/
void	set_coordinates(t_vars *vars, t_map *map, size_t k, size_t n)
{
	vars->x0 = ft_get_val(map->coor[k], 0, 0);
	vars->x1 = ft_get_val(map->coor[k + n], 0, 0);
	vars->y0 = ft_get_val(map->coor[k], 1, 0);
	vars->y1 = ft_get_val(map->coor[k + n], 1, 0);
	draw_line(vars);
}

/*
To connect all the points in the map->coor struct.
*/
void	connect_dot(t_vars *vars)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	i = -1;
	while (++i < vars->map->row)
	{
		j = -1;
		while (++j < vars->map->col)
		{
			if (j != vars->map->col - 1)
				set_coordinates(vars, vars->map, k, 1);
			if (i != vars->map->row - 1)
				set_coordinates(vars, vars->map, k, vars->map->col);
			++k;
		}
	}
}

void	swap_xy(t_vars *vars)
{
	int	temp1;
	int	temp2;

	temp1 = vars->x0;
	temp2 = vars->y0;
	vars->x0 = vars->x1;
	vars->y0 = vars->y1;
	vars->x1 = temp1;
	vars->y1 = temp2;
}
