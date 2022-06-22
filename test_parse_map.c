#include <stdio.h>
#include "libft/libft.h"
#include "fdf.h"

size_t	count_col(char *str);

void	print_mat(t_mat *mat)
{
	size_t	i = -1;

	while (++i < mat->row * mat->col)
	{
		printf("%f ", mat->data[i]);
		if ((i + 1)% mat->col == 0)
			printf("\n");
	}
}

void	test_parse_map(void)
{
	t_map	*map;
	size_t	i;

	i = -1;
	map = malloc(sizeof(t_map));
	if (map == NULL)
		ft_perror("test_parse_map error\n");
	open_file("test_maps/basictest.fdf", map);
	fill_map(map);
	map->transform = ft_mat_identity(4);
	while (++i < map->row * map->col)
	{
		print_mat(map->map[i]);
		printf("\n");
	}
	printf("row %li\ncol %li\n", map->row, map->col);
	ft_map_del(map);
}

void	test_count_col(void)
{
	char	*test1 = "1 2 3 4 5";
	char	*test2 = "1 2 3 4 5 ";
	char	*test3 = " 1 2 3 4 5";
	char	*test4 = " 1 2 3 4 5 ";
	char	*test5 = "1  2  3  4  5  6";
	char	*test6 = "1  1  1  1  1  1  1  1  1 ";
	char	*test7 = " 141,0xffffff 137,0xffffff 151,0xffffff 200,0xffffff 200,0xffffff 180,0xffffff";
	char	*test8 = " 0,0xff 0,0xff 1,0xff 0,0xff 5,0xff00 3,0xff 5,0xff00 6,0xff00 7,0xff00 11,0xff00";
	char	*test9 = " 110,0xffffff 111,0xffffff 118,0xffffff 103,0xffffff";
	char	*test10 = " 1,0x810202 1,0x810202 1,0x810202 1,0x810202";
	char	*test11 = " 1,0x810202 1,0x810202 1,0x810202";
	size_t	i;

	i = count_col(test1);
	if (i == 5)
		printf("test1_count_col: OK %li\n", i);
	else
		printf("test1_count_col: KO %li\n", i);
	i = count_col(test2);
	if (i == 5)
		printf("test2_count_col: OK %li\n", i);
	else
		printf("test2_count_col: KO %li\n", i);
	i = count_col(test3);
	if (i == 5)
		printf("test3_count_col: OK %li\n", i);
	else
		printf("test3_count_col: KO %li\n", i);
	i = count_col(test4);
	if (i == 5)
		printf("test4_count_col: OK %li\n", i);
	else
		printf("test4_count_col: KO %li\n", i);
	i = count_col(test5);
	if (i == 6)
		printf("test5_count_col: OK %li\n", i);
	else
		printf("test5_count_col: KO %li\n", i);
	i = count_col(test6);
	if (i == 9)
		printf("test6_count_col: OK %li\n", i);
	else
		printf("test6_count_col: KO %li\n", i);
	i = count_col(test7);
	if (i == 6)
		printf("test7_count_col: OK %li\n", i);
	else
		printf("test7_count_col: KO %li\n", i);
	i = count_col(test8);
	if (i == 10)
		printf("test8_count_col: OK %li\n", i);
	else
		printf("test8_count_col: KO %li\n", i);
	i = count_col(test9);
	if (i == 4)
		printf("test9_count_col: OK %li\n", i);
	else
		printf("test9_count_col: KO %li\n", i);
	i = count_col(test10);
	if (i == 4)
		printf("test10_count_col: OK %li\n", i);
	else
		printf("test10_count_col: KO %li\n", i);
	i = count_col(test11);
	if (i == 3)
		printf("test11_count_col: OK %li\n", i);
	else
		printf("test11_count_col: KO %li\n", i);
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
