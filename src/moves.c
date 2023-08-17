/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 21:33:30 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/17 17:05:17 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// up: check y
// down: check y
// left: check x
// right: check x

t_game	*move_up(t_game *game)
{
	if (game->data[game->player_x][game->player_y - 1] != '1' \
	&& game->data[game->player_x][game->player_y - 1] != 'E')
	{
		game->player_y -= 1;
		game->steps += 1;
		game->player->instances[0].y -= 1 * PIXELS;
	}
	update_game(game);
	return (game);
}

t_game	*move_down(t_game *game)
{
	if (game->data[game->player_x][game->player_y + 1] != '1' \
	&& game->data[game->player_x][game->player_y + 1] != 'E')
	{
		game->player_y += 1;
		game->steps += 1;
		game->player->instances[0].y += 1 * PIXELS;
	}
	update_game(game);
	return (game);
}

t_game	*move_left(t_game *game)
{
	if (game->data[game->player_x - 1][game->player_y] != '1' \
	&& game->data[game->player_x - 1][game->player_y] != 'E')
	{
		game->player_x -= 1;
		game->steps += 1;
		game->player->instances[0].x -= 1 * PIXELS;
	}
	update_game(game);
	return (game);
}

t_game	*move_right(t_game *game)
{
	if (game->data[game->player_x + 1][game->player_y] != '1' \
	&& game->data[game->player_x + 1][game->player_y] != 'E')
	{
		game->player_x += 1;
		game->steps += 1;
		game->player->instances[0].x += 1 * PIXELS;
	}
	update_game(game);
	return (game);
}