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

	i = 1;
	while (*str != '\0')
	{
		if (*str == ' ' || *str == '\t')
			i++;
	}
	return (i);
}

/*
Parse map into matrix. Need to count row and col before allocating mem for mat.
*/
void	**parse_map(char *str, t_map *map)
{
	size_t	i;
	size_t	j;
	size_t	k;
	t_map	map;
	int 	fd;
	char	**str;
	int		*arr;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	arr = malloc(sizeof(int));
	if (arr == NULL)
		return (NULL);
	i = -1;
	k = -1;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_perror("Cannot open file.\n");
	while (1)
	{
		str = ft_split(get_next_line(fd), ' ');
		if (str == NULL)
			break ;
		map->col = count_num(str[++i]);
		map->row++;
		arr = malloc(sizeof(int) * map->col);
		j = -1;
		while (++j < map->col)
			arr[++k] = ft_atoi(str[j]);
		free(str);
	}
	close(fd);
}
