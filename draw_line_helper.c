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
void	connect_dot(t_data *data, t_vars *vars, t_map *map)
{
    size_t  i;
    size_t  j;
    size_t  k;

    k = 0;
    i = -1;
    while (++i < map->row)
    {
        j = -1;
        while (++j < map->column)
        {
            if (j != map->column - 1)
            {
                set_coordinates(data, map, k, 1);
                draw_line(data, vars);
            }
            if (i != map->row - 1)
            {
                set_coordinates(data, map, k, map->col);
                draw_line(data, vars);
            }
            ++k;
        }
    }
}
