/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mekk <yel-mekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 01:12:09 by yel-mekk          #+#    #+#             */
/*   Updated: 2021/12/13 04:19:52 by yel-mekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*src;
	unsigned char	*dst;
	size_t			i;

	src = (unsigned char *)s1;
	dst = (unsigned char *)s2;
	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (src[i] != '\0' && dst[i] != '\0'
		&& (src[i] == dst[i]) && (i < n - 1))
	{
		i++;
	}
	return (src[i] - dst[i]);
}
