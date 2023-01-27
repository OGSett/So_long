/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemymov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mekk <yel-mekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:02:46 by yel-mekk          #+#    #+#             */
/*   Updated: 2022/11/23 00:01:26 by yel-mekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	emoveright(t_engine *game, int i, int l)
{
	animationright(game);
	game->smap[l][i] = '0';
	game->smap[l][i + 1] = 'N';
}

void	emoveleft(t_engine *game, int i, int l)
{
	animationleft(game);
	game->smap[l][i] = '0';
	game->smap[l][i - 1] = 'N';
}

int	act(t_engine *game, int l, int i)
{
	if (game->smap[l][i] == 'N')
	{
		if (game->smap[l][i - 1] != '1' && game->smap[l][i - 1] != 'C'
			&& game->smap[l][i - 1] != 'P' && game->smap[l][i - 1] != 'E')
		{
			emoveleft(game, i, l);
			return (0);
		}
		if (game->smap[l][i + 1] != '1' && game->smap[l][i + 1] != 'C'
			&& game->smap[l][i + 1] != 'P' && game->smap[l][i + 1] != 'E')
		{
			emoveright(game, i, l);
			return (0);
		}
	}
	return (1);
}

void	enemymov(t_engine *game)
{
	int	i;
	int	l;

	l = 0;
	while (game->smap[l])
	{
		i = 0;
		while (game->smap[l][i])
		{
			if (!act(game, l, i))
				return ;
			i++;
		}
		l++;
	}	
}
