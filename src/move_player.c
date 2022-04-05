/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:57:55 by kwarpath          #+#    #+#             */
/*   Updated: 2022/03/31 17:56:30 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	drow_map2(t_map *map, int i, int j)
{
	if (map->map[i][j] == '1')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.wall, j * 64, i * 64);
	else if (map->map[i][j] == '0')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.floor, j * 64, i * 64);
	else if (map->map[i][j] == 'P')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.player, j * 64, i * 64);
	else if (map->map[i][j] == 'E')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.exit, j * 64, i * 64);
	else if (map->map[i][j] == 'C')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.coin1, j * 64, i * 64);
}

int	drow_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
			drow_map2(map, i, j);
	}
	return (0);
}

int	keys(int key, t_map *map)
{
	if (key == UP)
		move_player_up(map);
	else if (key == DOWN)
		move_player_down(map);
	else if (key == LEFT)
		move_player_left(map);
	else if (key == RIGHT)
		move_player_right(map);
	else if (key == ESC)
		end_game();
	drow_map(map);
	return (0);
}

int	end_game(void)
{
	ft_printf("Игра окончена.\n");
	exit(0);
	return (0);
}

void	steps(t_map *map)
{
	map->steps++;
	ft_printf("Steps: %d\n", map->steps);
}
