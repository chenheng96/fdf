/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:51:06 by cchong            #+#    #+#             */
/*   Updated: 2022/06/29 14:28:28 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
To set the data in data struct to coordinates of point a and point b.
*/
void	set_coordinates(t_data *data, t_map *map, size_t k, size_t n)
{
    data->x0 = ft_get_val(map->map[k], 0, 0);
    data->x1 = ft_get_val(map->map[k + n], 0, 0);
    data->y0 = ft_get_val(map->map[k], 1, 0) - ft_get_val(map->map[k], 2, 0);
    data->y1 = ft_get_val(map->map[k + n], 1, 0) - ft_get_val(map->map[k + n], 2, 0);
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
            {
                set_coordinates(vars->data, vars->map, k, 1);
                draw_line(vars->data, vars);
            }
            if (i != vars->map->row - 1)
            {
                set_coordinates(vars->data, vars->map, k, vars->map->col);
                draw_line(vars->data, vars);
            }
            ++k;
        }
    }
}
