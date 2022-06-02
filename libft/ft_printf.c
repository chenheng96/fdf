/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:15:26 by cchong            #+#    #+#             */
/*   Updated: 2022/05/31 12:22:18 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_format(char format, va_list args)
{
	char	*str;
	int		ret;

	ret = 0;
	if (format == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (format == 's')
		str = ft_strdup(va_arg(args, char *));
	else if (format == 'p')
		str = ft_itoa_add(va_arg(args, unsigned long), "0123456789abcdef", 16);
	else if (format == 'd' || format == 'i')
		str = ft_itoa_base(va_arg(args, int), "0123456789", 10);
	else if (format == 'u')
		str = ft_itoa_unsigned(va_arg(args, size_t), "0123456789", 10);
	else if (format == 'x')
		str = ft_itoa_unsigned(va_arg(args, size_t), "0123456789abcdef", 16);
	else if (format == 'X')
		str = ft_itoa_unsigned(va_arg(args, size_t), "0123456789ABCDEF", 16);
	else if (format == '%')
		return (ft_putchar_fd('%', 1));
	else
		return (-1);
	ret = ft_putstr_fd(str, 1);
	free(str);
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		ret;
	int		input;

	va_start(args, str);
	i = 0;
	ret = 0;
	while (str != NULL && str[i] != '\0')
	{
		input = -1;
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			input = handle_format(str[i], args);
			if (input != -1)
				i++;
		}
		if (str[i] != '\0' && input == -1)
			input = ft_putchar_fd(str[i++], 1);
		ret += input;
	}
	va_end(args);
	return (ret);
}
