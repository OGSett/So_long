/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movments2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mekk <yel-mekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:57:55 by yel-mekk          #+#    #+#             */
/*   Updated: 2022/11/22 20:53:44 by yel-mekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	itsadoor(char c)
{
	if (c == 'E')
	{
		return (1);
	}
	return (0);
}

int	itsanenemy(char c)
{
	if (c == 'N')
	{
		return (1);
	}
	return (0);
}

int	itsacoin(char c)
{
	if (c == 'C')
	{
		return (1);
	}
	return (0);
}

int	itsawall(char c)
{
	if (c == '1')
	{
		return (1);
	}
	return (0);
}

int	status(char c)
{
	int	i;

	i = itsadoor(c);
	if (i == 1)
		return (1);
	i = itsacoin(c);
	if (i == 1)
		return (2);
	i = itsawall(c);
	if (i == 1)
		return (3);
	i = itsanenemy(c);
	if (i == 1)
		return (4);
	return (0);
}
