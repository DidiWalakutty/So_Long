/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/06 15:58:56 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/21 14:25:03 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	place_walls(t_game *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->data[y])
	{
		x = 0;
		while (map->data[y][x])
		{
			if (map->data[y][x] == '1')
			{
				if ((mlx_image_to_window(map->mlx, map->img->wall, \
				x * 32, y * 32)) < 0)
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

bool	place_player(t_game *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->data[y])
	{
		x = 0;
		while (map->data[y][x])
		{
			if (map->data[y][x] == 'P')
			{
				if ((mlx_image_to_window(map->mlx, map->img->player, \
				x * PIXELS, y * PIXELS)) < 0)
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

bool	place_collectables(t_game *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->data[y])
	{
		x = 0;
		while (map->data[y][x])
		{
			if (map->data[y][x] == 'C')
			{
				if ((mlx_image_to_window(map->mlx, map->img->collectable, \
				x * PIXELS + 8, y * PIXELS)) < 0)
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

bool	place_exit(t_game *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->data[y])
	{
		x = 0;
		while (map->data[y][x])
		{
			if (map->data[y][x] == 'E')
			{
				if ((mlx_image_to_window(map->mlx, map->img->exit, \
				x * PIXELS, y * PIXELS)) < 0)
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

bool	place_floor(t_game *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->data[y])
	{
		x = 0;
		while (map->data[y][x])
		{
			if (map->data[y][x] == '0' || map->data[y][x] == '1' || \
			map->data[y][x] == 'C' || map->data[y][x] == 'E' || \
			map->data[y][x] == 'P')
			{
				if ((mlx_image_to_window(map->mlx, map->img->floor, \
				x * PIXELS, y * PIXELS)) < 0)
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}
