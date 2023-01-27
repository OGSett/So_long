/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mekk <yel-mekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:05:42 by yel-mekk          #+#    #+#             */
/*   Updated: 2022/11/22 19:09:40 by yel-mekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	outsiders(t_engine *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (game->map[i] != '1' && game->map[i] != '0' && game->map[i] != 'P'
			&& game->map[i] != 'E' && game->map[i] != 'C'
			&& game->map[i] != '\n')
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
}
