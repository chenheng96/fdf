#include "libft/libft.h"
#include <stdio.h>

int	main(void)
{
	char 	*str = "1 2 3 4 5";
	char	**str2 = ft_split(str, ' ');
	int	i = -1;

	while (++i < 5)
	{
		printf("%i\n", ft_atoi(str2[i]));
	}
}
