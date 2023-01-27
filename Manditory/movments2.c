/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movments2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mekk <yel-mekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:57:55 by yel-mekk          #+#    #+#             */
/*   Updated: 2022/11/22 19:12:45 by yel-mekk         ###   ########.fr       */
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
	return (0);
}

int	execute(t_engine *game, char c)
{
	int	i;

	i = status(c);
	if (i == 3 || (i == 1 && game->coins > 0))
		return (0);
	if (i == 2)
		game->coins--;
	if (i == 1)
	{
		ft_printf("The game is over !\n");
		exit(1);
	}
	return (1);
}
