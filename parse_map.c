/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:05:17 by cchong            #+#    #+#             */
/*   Updated: 2022/06/20 16:52:38 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
To free the map struct.
*/
void	ft_map_del(t_map *map)
{
	size_t	i;

	i = -1;
	while (++i < map->row)
		free(map->data[i]);
	free(map->data);
	i = -1;
	while (++i < 4)
		ft_mat_del(map->map[i]);
	free(map->map);
	ft_mat_del(map->transform);
	free(map);
}

/*
To count number of numbers in a row in the file.
*/
size_t	count_col(char *str)
{
	size_t	ret;

	ret = 0;
	while (*str != '\0' && *str != '\n')
	{
		if (*str >= '0' && *str <= '9')
		{
			ret++;
			while (*str != ' ' && *str != '\0' && *str != '\n')
				str++;
		}
		else
			str++;
	}
	return (ret);
}

/*
To count number of rows in the file.
*/
size_t	count_row(char	*str)
{
	int 	fd;
	size_t	ret;
	char	*s;

	ret = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_perror("Cannot open file.\n");
	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL)
			break ;
		++ret;
		free(s);
	}
	return (ret);
}

/*
Parse map into matrix. Need to count row and col before allocating mem for mat.
*/
void	parse_map(char *str, t_map *map)
{
	size_t	i;
	size_t	j;
	int 	fd;
	char	*s;
	char	**arr;

	i = -1;
	fd = ft_open(str, O_RDONLY);
	map->row = count_row(str);
	map->data = ft_malloc(sizeof(double) * map->row);
	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL)
			break ;
		map->col = count_col(s);
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

	n = 10;
	map->map = malloc(sizeof(t_map) * 4);
	k = -1;
	while (++k < 4)
		map->map[k] = ft_mat_new(map->row, map->col);
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			ft_set_val(map->map[0], i, j, n * i);
			ft_set_val(map->map[1], i, j, n * j);
			ft_set_val(map->map[2], i, j, n * map->data[i][j]);
			ft_set_val(map->map[3], i, j, 1);
		}
	}
}
