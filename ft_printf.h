/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:30:28 by bsengeze          #+#    #+#             */
/*   Updated: 2023/03/23 21:11:03 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(int c);
size_t	ft_strlen(const char *s);
void	ft_putstr(const char *str);
int		ft_numlen(int n);
char	*ft_itoa(int n);
int		ft_unumlen(unsigned int n);
char	*ft_uitoa(unsigned int n);
int		print_char(int c, char format);
int		print_str(char *str);
int		print_dec(int dec);
int		print_unsigned_int(unsigned int ui);
int		hex_length(unsigned long int hex);
void	convert_hex(unsigned long int hex, char format);
int		print_hex(unsigned int hex, char format);
int		print_ptr(uintptr_t *ptr, char format);
int		format_identifier(const char format, va_list args);

#endif
