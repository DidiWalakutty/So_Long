/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/16 11:09:08 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/21 20:10:09 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
// print moves and collectables in window?
// update game

void	end_game(t_game *game)
{
	int	x;
	int	y;
	mlx_instance_t *ending;

	x = x * PIXELS;
	y = y * PIXELS;
	// ending = &game->img->player->instances[0];
	// ending->enabled = false;
	game->death = 1;
	// mlx_image_to_window(game->mlx, game->gameover, (game->width_x / 2) * PIXELS, (game->height_y / 2) * PIXELS);
	
}

void	remove_collectable(t_game *game, int y, int x)
{
	int	i;

	i = 0;

	while (i < game->count_c)
	{
		if (game->img->collectable->instances[i].y == game->player_y * PIXELS\
		&& game->img->collectable->instances[i].x - 8 == game->player_x * PIXELS)
		{
			game->img->collectable->instances[i].enabled = false;
		}
		i++;
	}
}

// reprint same number of moves if hitting wall?
// Doesn't remove collectable
void	update_game(t_game *game)
{
	if (game->steps >= 1)
		ft_printf("%i moves\n", game->steps);
	if (game->data[game->player_y][game->player_x] == 'C')
	{
		remove_collectable(game, game->player_y, game->player_x);
		game->data[game->player_y][game->player_x] = '0';
		game->total_collect += 1;
	}
	// if (game->total_collect == game->count_c \
	// && game->data[game->player_y][game->player_x] == 'E')
	// {
	// 	end_game(game);
	// 	mlx_close_window(game->mlx);
	// }
}
