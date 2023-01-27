/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mekk <yel-mekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:36:30 by yel-mekk          #+#    #+#             */
/*   Updated: 2022/11/22 23:37:49 by yel-mekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quit_game(t_engine	*game)
{
	mlx_destroy_window(game->mlxp, game->window);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_engine	*game;

	if (ac == 2)
	{
		game = malloc(sizeof(t_engine));
		game->movements = 1;
		game->smap = map_reader(av[1], game);
		map_checker(game);
		game->mwidth = ft_len(game->smap[0]);
		get_height(game);
		game->mlxp = mlx_init();
		game->imgs = allocation(game);
		win_creator(game);
		img_to_win(game);
		mlx_hook(game->window, 2, 0, movments, game);
		mlx_hook(game->window, 17, 0, quit_game, game);
		mlx_string_put(game->mlxp, game->window, 1, 1,
			0x00FFFF, ft_itoa(game->movements));
		mlx_loop(game->mlxp);
	}
}
