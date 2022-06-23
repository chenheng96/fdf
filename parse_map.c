/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:05:17 by cchong            #+#    #+#             */
/*   Updated: 2022/06/22 15:07:59 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Open file and pass struct and fd to parse_map.
Need to count row and col before allocating mem for mat.
*/
void	open_file(char *str, t_map *map)
{
	int		fd;

	fd = ft_open(str, O_RDONLY);
	map->row = countrow_checkcol(str, map);
	map->data = ft_malloc(sizeof(double) * map->row);
	parse_map(fd, map);
}

/*
Parse map into matrix.
*/
void	parse_map(int fd, t_map *map)
{
	size_t	i;
	size_t	j;
	char	*s;
	char	**arr;

	i = -1;
	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL)
			break ;
		arr = ft_split(s, ' ');
		map->data[++i] = ft_malloc(sizeof(double) * map->col);
		j = -1;
		while (++j < map->col)
		{
			map->data[i][j] = ft_atoi(arr[j]);
			free(arr[j]);
		}
		free(arr[j]);
		free(arr);
		free(s);
	}
	close(fd);
}

/*
To fill in the matrix in map->map with data from map->data.
*/
void	fill_map(t_map *map)
{
	size_t	i;
	size_t	j;
	size_t	k;
	double	n;

	n = 100;
	map->map = malloc(sizeof(t_map) * map->row * map->col);
	k = -1;
	while (++k < map->row * map->col)
		map->map[k] = ft_mat_new(4, 1);
	k = 0;
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			ft_set_val(map->map[k], 0, 0, j * n);
			ft_set_val(map->map[k], 1, 0, i * n);
			ft_set_val(map->map[k], 2, 0, map->data[i][j] * n);
			ft_set_val(map->map[k], 3, 0, 1);
			++k;
		}
	}
}
