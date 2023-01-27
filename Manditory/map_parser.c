/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mekk <yel-mekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:54:31 by yel-mekk          #+#    #+#             */
/*   Updated: 2022/11/22 19:07:33 by yel-mekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ext_checker(char *map)
{
	int	result;
	int	p;

	p = (ft_strlen(map) - 4);
	result = ft_strncmp(map + p, ".ber", 4);
	if (result == 0)
		return ;
	else
	{
		ft_printf("check ur map and try again\n");
		exit(1);
	}
}

char	**map_reader(char *map, t_engine *game)
{
	int		fd;
	int		i;
	char	*amap;
	char	*temp;

	i = 0;
	temp = malloc(2);
	amap = malloc(2);
	ext_checker(map);
	fd = open(map, O_RDONLY);
	while (1)
	{
		temp[1] = '\0';
		if (read(fd, temp, 1) == 0)
			break ;
		amap = ft_strjoin(amap, temp);
	}
	if (!amap[0])
	{
		ft_printf("INVALID MAP !\n");
		exit(1);
	}
	game->map = amap;
	return (ft_split(amap, '\n'));
}

int	coin_checker(t_engine *game)
{
	int	i;

	i = 0;
	game->coins = 0;
	while (game->map[i])
	{
		if (game->map[i] == 'C')
			game->coins++;
		i++;
	}
	if (game->coins == 0)
		return (0);
	return (1);
}

void	check_assests(t_engine *game)
{
	int	counter;

	counter = element_checker(game->map, 'P');
	if (counter != 1)
	{
		ft_printf("Player error!\n");
		exit (1);
	}
	counter = element_checker(game->map, 'E');
	if (counter != 1)
	{
		ft_printf("Exit error !\n");
		exit (1);
	}
	if (!coin_checker(game))
	{
		ft_printf("Coins error !\n");
		exit (1);
	}
}
