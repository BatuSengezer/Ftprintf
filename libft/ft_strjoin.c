/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:30:30 by bsengeze          #+#    #+#             */
/*   Updated: 2022/12/20 23:15:48 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*mal;
	char	*cs1;
	char	*cs2;

	cs1 = (char *)s1;
	cs2 = (char *)s2;
	j = 0;
	mal = malloc(sizeof(char) * (ft_strlen(cs1) + ft_strlen(cs2)) + 1);
	if (!mal)
		return (0);
	i = 0;
	while (ft_strlen(cs1) > i)
	{
		mal[i] = cs1[i];
		i++;
	}
	while (ft_strlen(cs2) > j)
	{
		mal[i + j] = cs2[j];
		j++;
	}
	mal[i + j] = 0;
	return (mal);
}
/*
int main(void)
{
	printf("result : %s", ft_strjoin("ABCD","EFGH"));
}
*/
