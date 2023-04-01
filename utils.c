/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:09:28 by bsengeze          #+#    #+#             */
/*   Updated: 2023/03/23 21:09:41 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(const char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	ft_numlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
		i = 1;
	while (n != 0)
	{
		i++;
		n = n / 10 ;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		numlen;
	long	num;

	num = n;
	numlen = ft_numlen(n);
	ret = malloc(sizeof(char) * (numlen + 1));
	if (!ret)
		return (0);
	if (n == 0)
		ret[0] = '0';
	ret[numlen] = 0;
	if (n < 0)
	{
		ret[0] = '-';
		num = -num;
	}
	while (num != 0)
	{
		ret[--numlen] = num % 10 + '0';
		num = num / 10;
	}
	return (ret);
}
