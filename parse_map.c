/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:05:17 by cchong            #+#    #+#             */
/*   Updated: 2022/06/22 14:21:49 by cchong           ###   ########.fr       */
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
	while (++i < map->row * map->col)
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
To count number of rows in the file and check whether each row has same col.
*/
size_t	countrow_checkcol(char	*str, t_map *map)
{
	int 	fd;
	char	*s;
	size_t	col_temp;
	size_t	ret;

	ret = 0;
	fd = open(str, O_RDONLY);
	map->col = 0;
	if (fd == -1)
		ft_perror("Cannot open file.\n");
	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL)
			break ;
		if (map->col == 0)
			map->col = count_col(s);
		col_temp = count_col(s);
		if (map->col != col_temp)
			ft_perror("Number of columns in each row are not same\n");
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
	map->row = countrow_checkcol(str, map);
	map->data = ft_malloc(sizeof(double) * map->row);
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
			ft_set_val(map->map[k], 0, 0, k % map->col * n - i * n + n);
			ft_set_val(map->map[k], 1, 0, (k % map->col * n + i * n + n) * 0.57);
			ft_set_val(map->map[k], 2, 0, map->data[i][j] * n);
			ft_set_val(map->map[k], 3, 0, 1);
			++k;
		}
	}
}
