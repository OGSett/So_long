/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemymov2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mekk <yel-mekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:58:10 by yel-mekk          #+#    #+#             */
/*   Updated: 2022/11/22 23:58:56 by yel-mekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animationright(t_engine	*game)
{
	int	tmp;

	game->imgs->enemy = mlx_xpm_file_to_image(game->mlxp,
			"Bonus/Textures/enemy_right.xpm", &tmp, &tmp);
}

void	animationleft(t_engine	*game)
{
	int	tmp;

	game->imgs->enemy = mlx_xpm_file_to_image(game->mlxp,
			"Bonus/Textures/image_left.xpm", &tmp, &tmp);
}
