/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 05:32:51 by cchong            #+#    #+#             */
/*   Updated: 2022/06/27 14:20:19 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
To free the variables in vars struct and free vars.
*/
void	ft_vars_del(t_vars *vars)
{
	free(vars->addr);
	free(vars->mlx);
	free(vars);
}

/*
To multiply the map->map[k] with trans mat and put the new frame onto the window.
Also reset the transform mat after transforming map->map[k].
*/
void    new_frame(t_data *data, t_vars *vars, t_map *map)
{
    size_t	k;
	t_mat	*temp;

	k = -1;
	vars->img = mlx_new_image(vars->mlx, 1920, 1080);
	while (++k < map->row * map->col)
	{
		temp = ft_mat_mul(map->transform, map->map[k]);
		ft_mat_del(map->map[k]);
		map->map[k] = temp;
	}
	ft_mat_del(map->transform);
	map->transform = ft_mat_identity(4);
	connect_dot(data, vars, map);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}

/*
To print an error msg and crash the program.
*/
void	ft_perror(const char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

/*
To malloc size and crash the program if malloc fails.
*/
void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		ft_perror("Cannot malloc.\n");
	return (ptr);
}

/*
To open file and crash the program if open fails.
*/
int	ft_open(const char *pathname, int flags)
{
	int	fd;

	fd = open(pathname, flags);
	if (fd == -1)
		ft_perror("Cannot open file.\n");
	return (fd);
}
