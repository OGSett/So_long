/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mekk <yel-mekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:23:11 by yel-mekk          #+#    #+#             */
/*   Updated: 2022/11/23 00:06:16 by yel-mekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_creator(t_engine *game)
{
	game->window = mlx_new_window(game->mlxp, game->mwidth * 64,
			game->mheight * 64, "SO_LONG's GAME");
}

void	get_height(t_engine *game)
{
	int	i;

	i = 0;
	while (game->smap[i])
		i++;
	game->mheight = i;
}

t_img	*allocation(t_engine *game)
{
	int		tmp;
	t_img	*imgs;

	imgs = malloc(sizeof(t_img));
	imgs->coin = mlx_xpm_file_to_image(game->mlxp,
			"Manditory/Textures/coin.xpm", &tmp, &tmp);
	imgs->player = mlx_xpm_file_to_image(game->mlxp,
			"Manditory/Textures/player.xpm", &tmp, &tmp);
	imgs->wall = mlx_xpm_file_to_image(game->mlxp,
			"Manditory/Textures/wall.xpm", &tmp, &tmp);
	imgs->door = mlx_xpm_file_to_image(game->mlxp,
			"Manditory/Textures/door.xpm", &tmp, &tmp);
	return (imgs);
}

void	render_sprite(t_engine	*game, t_img	*imgs, int il, int ic)
{
	if (game->smap[il][ic] == '1')
		mlx_put_image_to_window(game->mlxp, game->window,
			imgs->wall, ic * 64, il * 64);
	if (game->smap[il][ic] == 'P')
		mlx_put_image_to_window(game->mlxp, game->window,
			imgs->player, ic * 64, il * 64);
	if (game->smap[il][ic] == 'C')
		mlx_put_image_to_window(game->mlxp, game->window,
			imgs->coin, ic * 64, il * 64);
	if (game->smap[il][ic] == 'E')
		mlx_put_image_to_window(game->mlxp, game->window,
			imgs->door, ic * 64, il * 64);
}

void	img_to_win(t_engine *game)
{
	int		il;
	int		ic;
	t_img	*imgs;

	imgs = allocation(game);
	il = 0;
	while (game->smap[il])
	{
		ic = 0;
		while (game->smap[il][ic])
		{
			render_sprite(game, imgs, il, ic);
			ic++;
		}
		il++;
	}
}
