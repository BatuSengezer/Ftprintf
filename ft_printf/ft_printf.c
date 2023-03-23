/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:15:21 by bsengeze          #+#    #+#             */
/*   Updated: 2023/03/21 18:04:40 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <limits.h>

int	ft_printf(const char *str, ...)
{
	int		print_length;
	va_list	args;

	print_length = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str != '%')
				print_length += format_identifier(*str, args);
			if (*str == '%')
				print_length += print_char('%', '%');
		}
		else
		{
			ft_putchar(*str);
			print_length++;
		}
		str++;
	}
	va_end(args);
	return (print_length);
}
/*
//test
int main (void)
{
    int c = 49;
    char *str = "ABC";
    int hex = 479;
    void *ptr = &hex;
    unsigned int ui = 4294967295;

    //ft_printf("%c %% %s  %x  %X \n",c,str,hex,hex);
    //printf("%c %% %s  %x  %X \n",c,str,hex,hex);
	//ft_printf("%p  %d  %d  %i  %u\n",ptr,*(int*)ptr,c,c,ui);
    //printf("%p  %d  %d  %i  %u\n",ptr,*(int*)ptr,c,c,ui);
    //printf(" NULL %s NULL \n", NULL);
    //ft_printf(" NULL %s NULL ", NULL);
    //printf("\n hex length is %i",hex_length(hex));
	//printf(" %p\n", -1);
	//ft_printf(" %p\n", -1);
	//ft_printf(" %d ",hex_length(hex));
	//ft_printf(" %x ",hex);
	//ft_printf(" %p ",hex);
	//ft_printf(" %x hex length is: %d\n", 0, hex_length(hex));
	//printf(" %x \n", LONG_MAX);
	//ft_printf(" %x %d\n", LONG_MAX, hex_length(LONG_MAX));
	//printf(" %p %p \n", LONG_MIN, LONG_MAX);
	//ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
}
*/