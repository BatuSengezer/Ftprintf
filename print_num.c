/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:08:50 by bsengeze          #+#    #+#             */
/*   Updated: 2023/03/23 21:08:53 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_dec(int dec)
{
	char	*nbr;
	int		len;

	nbr = ft_itoa(dec);
	len = print_str(nbr);
	free(nbr);
	return (len);
}

int	ft_unumlen(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		i++;
		n = n / 10 ;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char			*ret;
	int				numlen;
	unsigned long	num;

	num = n;
	numlen = ft_unumlen(n);
	ret = malloc(sizeof(char) * (numlen + 1));
	if (!ret)
		return (0);
	if (n == 0)
		ret[0] = '0';
	ret[numlen] = 0;
	while (num != 0)
	{
		ret[--numlen] = num % 10 + '0';
		num = num / 10;
	}
	return (ret);
}

int	print_unsigned_int(unsigned int ui)
{
	char	*nbr;
	int		len;

	nbr = ft_uitoa((ui));
	len = print_str(nbr);
	free(nbr);
	return (len);
}
