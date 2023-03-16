/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:30:28 by bsengeze          #+#    #+#             */
/*   Updated: 2023/03/05 18:18:15 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

# define ERROR		-1

typedef struct s_flags
{
	char	*ptr;
	int		length;
	int		left_align;
	int		min_width;
	int		precision;
	int		zero_padding;
}	t_flags;


int			ft_printf(const char *str, ...);

#endif
