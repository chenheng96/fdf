#include "fdf.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char 	**str;
	int		*arr;
	int	i = -1;
	int	j;

	str = ft_split(av[1], ' ');
	arr = malloc(3);
	while (str[++i] != NULL)
		printf("str[%i] is %s\n", i, str[i]);
	i = -1;
	while (str[++i] != NULL)
	{
		arr[i] = ft_atoi(str[i]);
	}
	i = -1;
	while (++i < 5)
		printf("arr[%i] is %i\n", i, arr[i]);
	free(arr);
}
