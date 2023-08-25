/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemy.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/25 17:13:14 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/25 19:32:24 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_image	*load_death(mlx_t *mlx, t_image *img)
{
	mlx_texture_t	*death;

	death = mlx_load_png("sprites/death.png");
	if (!death)
		exit_error("Couldn't load death png");
	img->you_die = mlx_texture_to_image(mlx, death);
	if (!img->you_die)
		exit_error("Couldn't create your death image");
	return (img);
}

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
				if ((mlx_image_to_window(game->mlx, game->img->you_die, \
				x * PIXELS, y * PIXELS)) < 0)
					exit_error("couldn't place RIP images");
			}
			x++;
		}
		y++;
	}
	game->death = true;
}
