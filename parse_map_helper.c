/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:54:32 by cchong            #+#    #+#             */
/*   Updated: 2022/07/08 10:07:52 by cchong           ###   ########.fr       */
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
		ft_mat_del(map->coor[i]);
	free(map->coor);
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
	int		fd;
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
