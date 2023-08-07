/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/06 15:58:56 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/07 16:08:17 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	place_walls(t_map *map, t_game *game)
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
				if (!mlx_image_to_window(map->mlx, game->wall, x * 32, y * 32))
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

bool	place_player(t_map *map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (map->data[y])
	{
		x = 0;
		while (map->data[y][x])
		{
			if (map->data[y][x] == '0')
			{
				if (!mlx_image_to_window(map->mlx, game->playr, x * 32, y * 32))
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

bool	place_collectables(t_map *map, t_game *game)
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
				if (!mlx_image_to_window(map->mlx, game->collc, x * 32, y * 32))
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

bool	place_exit(t_map *map, t_game *game)
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
				if (!mlx_image_to_window(map->mlx, game->exit, x * 32, y * 32))
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

bool	place_floor(t_map *map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (map->data[y])
	{
		x = 0;
		while (map->data[y][x])
		{
			if (map->data[y][x] == '0')
			{
				if (!mlx_image_to_window(map->mlx, game->floor, x * 32, y * 32))
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}
