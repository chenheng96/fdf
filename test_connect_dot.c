#include "fdf.h"

void	test_connect_dot(void)
{
	t_map	*map;
	t_data	*data;
	t_vars	*vars;
	size_t	i;

	i = -1;
	map = malloc(sizeof(t_map));
	if (map == NULL)
		ft_perror("test_parse_map error\n");
	vars = ft_malloc(sizeof(t_vars));
	data = ft_malloc(sizeof(t_data));
	open_file("test_maps/basictest.fdf", map);
	map->transform = ft_mat_identity(4);
	while (++i < map->row * map->col)
	{
		print_mat(map->map[i]);
		printf("\n");
	}
	printf("row %li\ncol %li\n", map->row, map->col);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "FDF");
	new_frame(vars);
	mlx_hook(vars->win, 2, 1L << 0, handle_key, vars);
	mlx_loop(vars->mlx);
}

int	main(void)
{
	test_connect_dot();
}
