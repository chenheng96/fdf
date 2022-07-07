/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 05:32:51 by cchong            #+#    #+#             */
/*   Updated: 2022/07/07 19:52:26 by cchong           ###   ########.fr       */
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
To multiply the vars->map->map[k] with trans mat and put the new frame onto the 
window. Also reset the transform mat after transforming vars->map->map[k].
*/
void	new_frame(t_vars *vars)
{
	size_t	k;
	t_mat	*temp;

	k = -1;
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	while (++k < vars->map->row * vars->map->col)
	{
		temp = ft_mat_mul(vars->map->transform, vars->map->map[k]);
		ft_mat_del(vars->map->map[k]);
		vars->map->map[k] = temp;
	}
	ft_mat_del(vars->map->transform);
	vars->map->transform = ft_mat_identity(4);
	connect_dot(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	free(vars->img);
}

	// printf("\nmap[i]\n");
	// size_t i = -1;
	// while (++i < vars->map->row * vars->map->col)
	// {
	// 	print_mat(vars->map->map[i]);
	// 	printf("\n");
	// }
	// printf("row %li\ncol %li\n", vars->map->row, vars->map->col);

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
