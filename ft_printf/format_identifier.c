/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_identifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:08:30 by bsengeze          #+#    #+#             */
/*   Updated: 2023/03/23 21:08:37 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_identifier(const char format, va_list args)
{
	int	length;

	length = 0;
	if (format == 'c' || format == '%')
		length += print_char(va_arg(args, int), format);
	if (format == 's')
		length += print_str(va_arg(args, char *));
	if (format == 'x' || format == 'X')
		length += print_hex(va_arg(args, unsigned int), format);
	if (format == 'p')
		length += print_ptr(va_arg(args, void *), format);
	if (format == 'd' || format == 'i')
		length += print_dec(va_arg(args, int));
	if (format == 'u')
		length += print_unsigned_int(va_arg(args, unsigned int));
	return (length);
}
