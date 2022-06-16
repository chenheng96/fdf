/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:05:17 by cchong            #+#    #+#             */
/*   Updated: 2022/06/07 16:36:29 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int **parse_map(char *str, char ***map, t_data *data, int **map_coor)
{
	int	i;
	int	j;
	int fd;

	i = -1;
	fd = open(str, O_RDONLY);
	if (fd < 3)
		return (NULL);
	data->x = 0;
	data->y = 0;
	while (1)
	{
		map[++i] = ft_split(get_next_line(fd), ' ');
		data->x++;
		if (map[i] == NULL)
			break ;
	}
	close(fd);
	i = -1;
	while (++i < data->x)
	{
		j = -1;
		while (++j < data->y)
			map_coor[i][j] = ft_atoi(map[i][j]);
	}
	return (0);
}
