/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/16 11:09:08 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/17 16:29:12 by diwalaku      ########   odam.nl         */
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
	ending = &game->player->instances[0];
	ending->enabled = false;
	game->death = 1;
	mlx_image_to_window(game->mlx, game->gameover, (game->width_x / 2) * PIXELS, (game->height_y / 2) * PIXELS);
	ft_printf("Game Over!\n");
}

void	update_game(t_game *game)
{
	if (game->steps >= 1)
		ft_printf("%i moves\n", game->steps);
	if (game->player_x == 'C' && game->player_y == 'C')
		{
			remove_collectable(game, game->player_x, game->player_y);
			game->data[game->player_y][game->player_x] = '0';
			game->total_collect += 1;
		}
	if (game->total_collect == game->count_c \
	&& game->player_x == 'E' && game->player_y == 'E')
	{
		end_game(game);
		mlx_close_window(game->mlx);
	}
}