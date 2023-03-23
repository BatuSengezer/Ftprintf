/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:11:15 by bsengeze          #+#    #+#             */
/*   Updated: 2023/03/23 21:11:17 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	len;

	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	len = ft_strlen(str);
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
	return (len);
}
