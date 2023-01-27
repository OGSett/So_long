/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mekk <yel-mekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 02:06:55 by yel-mekk          #+#    #+#             */
/*   Updated: 2021/12/13 04:10:30 by yel-mekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*t;

	t = (unsigned char *)s;
	while (*t != (unsigned char)c && *t)
	{
		t++;
	}
	if (*t == (unsigned char)c)
	{
		return ((char *)t);
	}
	return (0);
}
