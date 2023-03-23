/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:07:17 by bsengeze          #+#    #+#             */
/*   Updated: 2023/03/23 21:08:15 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_ptr(uintptr_t ptr, char format)
{
	convert_hex(ptr, format);
}

int	print_ptr(uintptr_t *ptr, char format)
{
	if (ptr == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	if (ptr)
	{
		ft_putstr("0x");
		ft_put_ptr((uintptr_t)ptr, format);
	}
	return (hex_length((uintptr_t)ptr) + 2);
}
