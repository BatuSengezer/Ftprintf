/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:11:34 by bsengeze          #+#    #+#             */
/*   Updated: 2023/03/23 21:11:41 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_length(unsigned long int hex)
{
	int	len;

	len = 0;
	if (hex == 0)
		return (1);
	while (hex != 0)
	{	
		hex = hex / 16;
		len++;
	}
	return (len);
}

void	convert_hex(unsigned long int hex, char format)
{
	if (hex >= 16)
	{
		convert_hex(hex / 16, format);
		convert_hex(hex % 16, format);
	}
	else
	{
		if (hex < 10)
			ft_putchar(hex + '0');
		else
		{
			if (format == 'x' || format == 'p')
				ft_putchar(hex - 10 + 'a');
			if (format == 'X')
				ft_putchar(hex - 10 + 'A');
		}
	}
}

int	print_hex(unsigned int hex, char format)
{
	convert_hex(hex, format);
	return (hex_length(hex));
}
