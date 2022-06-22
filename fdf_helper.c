/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 05:32:51 by cchong            #+#    #+#             */
/*   Updated: 2022/06/22 14:46:39 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
To print an error msg and crash the program.
*/
void	ft_perror(const char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		ft_perror("Cannot malloc.\n");
	return (ptr);
}

int	ft_open(const char *pathname, int flags)
{
	int	fd;

	fd = open(pathname, flags);
	if (fd == -1)
		ft_perror("Cannot open file.\n");
	return (fd);
}
