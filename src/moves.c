/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 21:33:30 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/21 19:24:11 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// up: check y
// down: check y
// left: check x
// right: check x

t_game	*move_up(t_game *game)
{
	if (game->data[game->player_y - 1][game->player_x] != '1' \
	&& game->data[game->player_y - 1][game->player_x] != 'E')
	{
		game->player_y -= 1;
		game->steps += 1;
		game->img->player->instances[0].y -= 1 * PIXELS;
	}
	update_game(game);
	return (game);
}

t_game	*move_down(t_game *game)
{
	if (game->data[game->player_y + 1][game->player_x] != '1' \
	&& game->data[game->player_y + 1][game->player_x] != 'E')
	{
		game->player_y += 1;
		game->steps += 1;
		game->img->player->instances[0].y += 1 * PIXELS;
	}
	update_game(game);
	return (game);
}

t_game	*move_left(t_game *game)
{
	if (game->data[game->player_y][game->player_x - 1] != '1' \
	&& game->data[game->player_y][game->player_x - 1] != 'E')
	{
		game->player_x -= 1;
		game->steps += 1;
		game->img->player->instances[0].x -= 1 * PIXELS;
	}
	update_game(game);
	return (game);
}

t_game	*move_right(t_game *game)
{
	if (game->data[game->player_y][game->player_x + 1] != '1' \
	&& game->data[game->player_y][game->player_x + 1] != 'E')
	{
		game->player_x += 1;
		game->steps += 1;
		game->img->player->instances[0].x += 1 * PIXELS;
	}
	update_game(game);
	return (game);
}
