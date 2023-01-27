/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mekk <yel-mekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:01:47 by yel-mekk          #+#    #+#             */
/*   Updated: 2022/11/22 20:49:29 by yel-mekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	nl_checker(t_engine *game)
{
	int	i;

	i = 0;
	if (game->map[0] == '\n' || game->map[ft_strlen(game->map) - 1] == '\n')
		ft_printf("New line error\n");
	while (game->map[i])
	{
		if (game->map[i] == '\n' && game->map[i + 1] == '\n')
		{
			ft_printf("Double new line error\n");
			exit(1);
		}
		i++;
	}
}

void	check_first(char *game)
{
	int	i;

	i = 0;
	while (game[i])
	{
		if (game[i] == '1')
			i++;
		else
		{
			ft_printf("first or last wall error\n");
			exit(1);
		}
	}
}

void	walls_checker(t_engine *game)
{
	int	l;
	int	len;

	l = 0;
	len = ft_strlen(game->smap[0]);
	while (game->smap[l])
	{
		if ((game->smap[l][0] != '1' && game->smap[l][len - 1] != '1')
				|| (ft_len(game->smap[l]) != len))
		{
			ft_printf("walls error check again\n");
			exit(1);
		}
		l++;
	}
	check_first(game->smap[0]);
	check_first(game->smap[l - 1]);
}

int	element_checker(char *game, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (game[i])
	{
		if (game[i] == c)
			counter++;
		i++;
	}
	return (counter);
}
