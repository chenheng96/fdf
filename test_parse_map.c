#include <stdio.h>
#include "libft/libft.h"
#include "fdf.h"

size_t	count_col(char *str);

void	test_parse_map(void)
{
	t_map	*map;
	size_t	i;
	size_t	j;

	i = -1;
	// printf("in test parse map1\n");
	map = malloc(sizeof(t_map));
	if (map == NULL)
		ft_perror("test_parse_map error\n");
	parse_map("test_maps/julia.fdf", map);
	printf("in test parse map2\n");
	while (++i < map->row)
	{
		// printf("in test parse map3\n");
		j = -1;
		while (++j < map->col)
			printf("%i ", (int)map->data[i][j]);
		printf("\n");
			// printf("map->data[%li][%li] = %f\n", i, j, map->data[i][j]);
	}
	i = -1;
	printf("row %li\ncol %li\n", map->row, map->col);
	while (++i < map->row)
		free(map->data[i]);
	free(map->data);
	free(map);
}

void	test_count_col(void)
{
	char	*str1 = "1 2 3 4 5";
	char	*str10 = "1 2 3 4 5 ";
	char	*str11 = " 1 2 3 4 5";
	char	*str12 = " 1 2 3 4 5 ";
	char	*str2 = "1  2  3  4  5  6";
	char	*str3 = "1  1  1  1  1  1  1  1  1 ";
	char	*str4 = " 141,0xffffff 137,0xffffff 151,0xffffff 200,0xffffff 200,0xffffff 180,0xffffff";
	char	*str5t1 = " 0,0xff 0,0xff 1,0xff 0,0xff 5,0xff00 3,0xff 5,0xff00 6,0xff00 7,0xff00 11,0xff00";
	char	*str6t2 = " 110,0xffffff 111,0xffffff 118,0xffffff 103,0xffffff";
	char	*str7ef = " 1,0x810202 1,0x810202 1,0x810202 1,0x810202";
	char	*str8julia = " 1,0x810202 1,0x810202 1,0x810202";
	size_t	i;

	i = count_col(str1);
	if (i == 5)
		printf("test_count_col1: OK %li\n", i);
	else
		printf("test_count_col1: KO %li\n", i);
	i = count_col(str10);
	if (i == 5)
		printf("test_count_col10: OK %li\n", i);
	else
		printf("test_count_col10: KO %li\n", i);
	i = count_col(str11);
	if (i == 5)
		printf("test_count_col11: OK %li\n", i);
	else
		printf("test_count_col11: KO %li\n", i);
	i = count_col(str12);
	if (i == 5)
		printf("test_count_col12: OK %li\n", i);
	else
		printf("test_count_col12: KO %li\n", i);
	i = count_col(str2);
	if (i == 6)
		printf("test_count_col2: OK %li\n", i);
	else
		printf("test_count_col2: KO %li\n", i);
	i = count_col(str3);
	if (i == 9)
		printf("test_count_col3: OK %li\n", i);
	else
		printf("test_count_col3: KO %li\n", i);
	i = count_col(str4);
	if (i == 6)
		printf("test_count_col4: OK %li\n", i);
	else
		printf("test_count_col4: KO %li\n", i);
	i = count_col(str5t1);
	if (i == 10)
		printf("test_count_col str5t1: OK %li\n", i);
	else
		printf("test_count_col str5t1: KO %li\n", i);
	i = count_col(str6t2);
	if (i == 4)
		printf("test_count_col str6t2: OK %li\n", i);
	else
		printf("test_count_col str6t2: KO %li\n", i);
	i = count_col(str7ef);
	if (i == 4)
		printf("test_count_col str7ef: OK %li\n", i);
	else
		printf("test_count_col str7ef: KO %li\n", i);
	i = count_col(str8julia);
	if (i == 3)
		printf("test_count_col str8julia: OK %li\n", i);
	else
		printf("test_count_col str8julia: KO %li\n", i);
}

int	main(void)
{
	test_count_col();
	test_parse_map();
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
