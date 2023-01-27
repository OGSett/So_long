/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mekk <yel-mekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 02:02:33 by yel-mekk          #+#    #+#             */
/*   Updated: 2021/12/13 04:10:11 by yel-mekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		*(char *)(dest + j) = *(char *)(src + i);
		i++;
		j++;
	}
	return (dest);
}
