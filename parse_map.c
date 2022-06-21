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
size_t	count_num(char *str)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 1;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			ret++;
			while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0' && str[i] != '\n')
				i++;
		}
		else
			i++;
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
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_perror("Cannot open file.\n");
	map->data = malloc(sizeof(double));
	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL)
			break ;
		map->col = count_num(s);
		arr = ft_split(s, ' ');
		printf("map->col %li\n", map->col);
		map->row++;
		map->data[++i] = malloc(sizeof(double) * map->col);
		if (map->data[i] == NULL)
			ft_perror("parse_map error\n");
		j = -1;
		while (++j < map->col)
		{
			map->data[i][j] = ft_atoi(arr[j]);
			printf("map->data[%li][%li] = %f\n", i, j, map->data[i][j]);
			free(arr[j]);
		}
		free(s);
		free(arr);
	}
	close(fd);
}
