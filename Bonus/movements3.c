/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mekk <yel-mekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:54:03 by yel-mekk          #+#    #+#             */
/*   Updated: 2022/11/22 20:54:40 by yel-mekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (i == 4)
	{
		ft_printf("the enemy spotted you, YOU LOST!!\n");
		exit(1);
	}
	return (1);
}
