/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mekk <yel-mekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:08:30 by yel-mekk          #+#    #+#             */
/*   Updated: 2022/11/22 23:57:17 by yel-mekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

typedef struct s_img
{
	void	*wall;
	void	*player;
	void	*coin;
	void	*door;
	void	*enemy;
}				t_img;

typedef struct s_engine
{
	char	**smap;
	char	*map;
	void	*mlxp;
	void	*window;
	int		coins;
	int		movements;
	int		mwidth;
	int		mheight;
	char	*steps;
	t_img	*imgs;
}				t_engine;

char	**map_reader(char *map, t_engine *game);
void	map_checker(t_engine *game);
void	nl_checker(t_engine *game);
void	check_first(char *game);
void	walls_checker(t_engine *game);
int		element_checker(char *game, char c);
int		ft_len(char *str);
void	outsiders(t_engine *game);
void	check_assests(t_engine *game);
void	get_height(t_engine *game);
void	win_creator(t_engine *game);
void	img_to_win(t_engine *game);
int		movments(int keycode, t_engine *game);
int		count(t_engine *game);
int		execute(t_engine *game, char c);
int		itsadoor(char c);
int		itsawall(char c);
int		itsacoin(char c);
int		status(char c);
void	enemymov(t_engine *game);
t_img	*allocation(t_engine *game);
void	animationright(t_engine	*game);
void	animationleft(t_engine	*game);
#endif