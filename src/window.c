/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/16 11:09:08 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/09/16 11:40:19 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	remove_collectable(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->count_c)
	{
		if (game->img->collectable->instances[i].y == game->player_y * PIXELS \
		&& game->img->collectable->instances[i].x - 8 \
		== game->player_x * PIXELS)
		{
			game->img->collectable->instances[i].enabled = false;
		}
		i++;
	}
}

void	update_game(t_game *game)
{
	if (game->steps >= 1)
	{
		print_moves(game);
		ft_printf("%i moves\n", game->steps);
	}
	if (game->data[game->player_y][game->player_x] == 'F')
		you_die(game);
	if (game->data[game->player_y][game->player_x] == 'C')
	{
		remove_collectable(game);
		game->data[game->player_y][game->player_x] = '0';
		game->total_collect += 1;
	}
}
