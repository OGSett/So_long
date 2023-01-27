/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mekk <yel-mekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 02:06:35 by yel-mekk          #+#    #+#             */
/*   Updated: 2021/12/13 04:10:13 by yel-mekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*l;
	unsigned char	*r;

	r = (unsigned char *)src;
	l = (unsigned char *)dst;
	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	if (l > r)
	{
		while (i < len)
		{
			l[len - 1] = r[len - 1];
			len--;
		}
	}
	else
	{
		i = -1;
		while (++i < len)
			l[i] = r[i];
	}
	return (dst);
}
