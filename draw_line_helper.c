/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:51:06 by cchong            #+#    #+#             */
/*   Updated: 2022/07/05 16:02:05 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
To set the data in data struct to coordinates of point a and point b.
*/
void	set_coordinates(t_vars *vars, t_map *map, size_t k, size_t n)
{
    double x0;
    double x1;
    double y0;
    double y1;

    x0 = ft_get_val(map->map[k], 0, 0);
    x1 = ft_get_val(map->map[k + n], 0, 0);
    y0 = ft_get_val(map->map[k], 1, 0);
    y1 = ft_get_val(map->map[k + n], 1, 0);
    if (x0 >= 0 && x0 < WIDTH && x1 >= 0 && x1 < WIDTH && y0 >= 0 && y0 < HEIGHT
        && y1 >= 0 && y1 < HEIGHT)
    {
        vars->data->x0 = x0;
        vars->data->x1 = x1;
        vars->data->y0 = y0;
        vars->data->y1 = y1;
        draw_line(vars->data, vars);
    }
}

/*
To connect all the points in the map->map struct.
*/
void	connect_dot(t_vars *vars)
{
    size_t  i;
    size_t  j;
    size_t  k;

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
