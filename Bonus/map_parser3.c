/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mekk <yel-mekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:05:42 by yel-mekk          #+#    #+#             */
/*   Updated: 2022/11/22 20:50:03 by yel-mekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_enemy(t_engine *game)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (game->map[i])
	{
		if (game->map[i] == 'N')
			count++;
		i++;
	}
}

void	outsiders(t_engine *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (game->map[i] != '1' && game->map[i] != '0' && game->map[i] != 'P'
			&& game->map[i] != 'E' && game->map[i] != 'C'
			&& game->map[i] != '\n' && game->map[i] != 'N')
		{
			ft_printf("INVALID CHARACTER IN MAP\n");
			exit (1);
		}
		i++;
	}
}

void	map_checker(t_engine *game)
{
	outsiders(game);
	nl_checker(game);
	walls_checker(game);
	check_assests(game);
	check_enemy(game);
}
