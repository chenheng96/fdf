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
To count number of numbers in a row in the file.
*/
size_t	count_col(char *str)
{
	size_t	ret;

	ret = 0;
	while (*str != '\0' && *str != '\n')
	{
		if (*str >= '0' || *str == '9')
		{
			ret++;
			while (*str >= '0' || *str == '9')
				str++;
		}
		else if (*str == ',')
		{
			while (*str != ' ')
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
	close(fd);
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
			// printf("map->data[%li][%li] = %f\n", i, j, map->data[i][j]);
			free(arr[j]);
		}
		free(arr[j]);
		free(arr);
		free(s);
	}
	close(fd);
}
