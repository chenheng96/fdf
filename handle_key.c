#include "fdf.h"

void    handle_xyz(int keycode, t_vars *vars, t_map *map, t_data *data)
{
    t_mat   *mat;
    t_mat   *temp;

    if (keycode == 'x')
        mat = ft_rotate_x(20);
    else if (keycode == 'y')
        mat = ft_rotate_y(20);
    else
        mat = ft_rotate_z(20);
    temp = ft_mat_mul(map->transform, mat);
    ft_mat_del(map->transform);
    ft_mat_del(mat);
    map->transform = temp;
    new_frame(data, vars, map);
}

void    handle_translate(int keycode, t_vars *vars, t_map *map, t_data *data)
{
    t_mat   *mat;
    t_mat   *temp;
    double  x;
    double  y;
    double  z;

    x = 0;
    y = 0;
    z = 0;
    if (keycode == 'up')
        y = -20;
    else if (keycode == 'down')
        y = 20;
    else if (keycode == 'left')
        x = -20;
    else
        x = 20;
    mat = ft_translate(x, y, z);
    temp = ft_mat_mul(map->transform, mat);
    ft_mat_del(map->transform);
    ft_mat_del(mat);
    map->transform = temp;
    new_frame(data, vars, map);
}

void    handle_scale(int keycode, t_vars *vars, t_map *map, t_data *data)
{
    t_mat   *mat;
    t_mat   *temp;
    double  x;
    double  y;
    double  z;

    x = 20;
    y = 20;
    z = 0;
    if (keycode == '-')
    {
        x = -x;
        y = -y;
    }
    mat = ft_scale(x, y, z);
    temp = ft_mat_mul(map->transform, mat);
    ft_mat_del(map->transform);
    ft_mat_del(mat);
    map->transform = temp;
    new_frame(data, vars, map);
}

void    handle_shear(int keycode, t_vars *vars, t_map *map, t_data *data)
{
    t_mat   *mat;
    t_mat   *temp;
    double  x;
    double  y;
    double  z;

    x = 20;
    y = 20;
    z = 0;
    if (keycode == 'q')
    {
        x = -x;
        y = -y;
    }
    mat = ft_scale(x, y, z);
    temp = ft_mat_mul(map->transform, mat);
    ft_mat_del(map->transform);
    ft_mat_del(mat);
    map->transform = temp;
    new_frame(data, vars, map);
}

/*
To handle events when certain keys are pressed.
*/
void	handle_key(int keycode, t_vars *vars, t_map *map, t_data *data)
{
	if (keycode == 53 || keycode == 'close window')
	{
		mlx_destroy_window(vars->mlx, vars->win);
		ft_map_del(map);
		ft_vars_del(vars);
		free(data);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 'x' || keycode == 'y' || keycode == 'z')
        handle_xyz(keycode, vars, map, data);
    else if (keycode == 'up' || keycode == 'down' || keycode == 'left' || keycode == 'right')
        handle_translate(keycode, vars, map, data);
    else if (keycode == '+' || keycode == '-')
        handle_scale(keycode, vars, map, data);
    else if (keycode == 'q' || keycode == 'r')
        handle_shear(keycode, vars, map, data);
	else
		ft_putnbr_fd(keycode, 1);
}
