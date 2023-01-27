/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mekk <yel-mekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:45:45 by yel-mekk          #+#    #+#             */
/*   Updated: 2022/11/22 20:58:05 by yel-mekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moveleft(t_engine *game)
{
	int	i;
	int	l;

	l = 0;
	while (game->smap[l])
	{
		i = 0;
		while (game->smap[l][i])
		{
			if (game->smap[l][i] == 'P')
			{
				if (!execute(game, (game->smap[l][i - 1])))
					return ;
				game->movements++;
				game->smap[l][i - 1] = 'P';
				game->smap[l][i] = '0';
				return ;
			}
			i++;
		}
		l++;
	}
}

void	moveright(t_engine *game)
{
	int	i;
	int	l;

	l = 0;
	while (game->smap[l])
	{
		i = 0;
		while (game->smap[l][i])
		{
			if (game->smap[l][i] == 'P')
			{
				if (!execute(game, (game->smap[l][i + 1])))
					return ;
				game->movements++;
				game->smap[l][i + 1] = 'P';
				game->smap[l][i] = '0';
				return ;
			}
			i++;
		}
		l++;
	}
}

void	moveup(t_engine *game)
{
	int	i;
	int	l;

	l = 0;
	while (game->smap[l])
	{
		i = 0;
		while (game->smap[l][i])
		{
			if (game->smap[l][i] == 'P')
			{
				if (!execute(game, (game->smap[l - 1][i])))
					return ;
				game->movements++;
				game->smap[l - 1][i] = 'P';
				game->smap[l][i] = '0';
				return ;
			}
			i++;
		}
		l++;
	}
}

void	movedown(t_engine *game)
{
	int	i;
	int	l;

	l = 0;
	while (game->smap[l])
	{
		i = 0;
		while (game->smap[l][i])
		{
			if (game->smap[l][i] == 'P')
			{
				if (!execute(game, (game->smap[l + 1][i])))
					return ;
				game->movements++;
				game->smap[l + 1][i] = 'P';
				game->smap[l][i] = '0';
				return ;
			}
			i++;
		}
		l++;
	}
}

int	movments(int keycode, t_engine *game)
{
	if (keycode == 0 || keycode == 1 || keycode == 2
		|| keycode == 13 || keycode == 53)
	{
		printf("movements = %d\n", game->movements);
		if (keycode == 53)
			exit(1);
		if (keycode == 0)
			moveleft(game);
		if (keycode == 1)
			movedown(game);
		if (keycode == 2)
			moveright(game);
		if (keycode == 13)
			moveup(game);
	}
	mlx_clear_window(game->mlxp, game->window);
	img_to_win(game);
	return (0);
}
