#include <stdio.h>
#include "libft/libft.h"
#include "fdf.h"

size_t	count_num(char *str);

void	test_parse_map(void)
{
	t_map	*map;
	size_t	i;
	size_t	j;

	i = -1;
	printf("in test parse map\n");
	map = malloc(sizeof(t_map));
	if (map == NULL)
		ft_perror("test_parse_map error\n");
	parse_map("test.txt", map);
	printf("in test parse map2\n");
	while (++i < map->row)
	{
		printf("in test parse map3\n");
		j = -1;
		while (++j < map->col)
			printf("map->data[%li][%li] = %f\n", i, j, map->data[i][j]);
	}
	free(map->data);
	free(map);
}

void	test_count_num(void)
{
	char	*str1 = "1 2 3 4 5";
	char	*str2 = "1  2  3  4  5";
	char	*str3 = "1  1  1  1  1  1  1  1  1";
	char	*str4 = "0 2  0  4  0  5  0  0 80  0  0  9  0  0  0 11  0  0  0";
	size_t	i;

	i = count_num(str1);
	printf("%li\n", i);
	i = count_num(str2);
	printf("%li\n", i);
	i = count_num(str3);
	printf("%li\n", i);
	i = count_num(str4);
	printf("%li\n", i);
}

int	main(void)
{
	test_parse_map();
	// test_count_num();
}

// int	main(void)
// {
// 	char 	*str = "1 2 3 4 5";
// 	char	**str2 = ft_split(str, ' ');
// 	int	i = -1;

// 	while (++i < 5)
// 	{
// 		printf("%i\n", ft_atoi(str2[i]));
// 	}
// }
