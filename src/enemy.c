/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:13:14 by diwalaku          #+#    #+#             */
/*   Updated: 2024/02/11 13:40:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	place_enemy(t_game *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->data[y])
	{
		x = 0;
		while (map->data[y][x])
		{
			if (map->data[y][x] == 'F')
			{
				if ((mlx_image_to_window(map->mlx, map->img->enemy, \
				x * PIXELS, y * PIXELS)) < 0)
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

void	you_die(t_game *game)
{
	int	x;
	int	y;

	death_message();
	y = 0;
	while (game->data[y])
	{
		x = 0;
		while (game->data[y][x])
		{
			if (game->data[y][x] == '0' || game->data[y][x] == '1' || \
				game->data[y][x] == 'C' || game->data[y][x] == 'E' || \
				game->data[y][x] == 'P')
			{
				if ((mlx_image_to_window(game->mlx, game->img->rip, \
				x * PIXELS, y * PIXELS)) < 0)
					exit_error("couldn't place RIP images");
			}
			x++;
		}
		y++;
	}
	game->death = true;
}
