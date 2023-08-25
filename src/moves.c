/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 21:33:30 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/25 19:28:44 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	change_direction(t_game *game, char c, int x, int y)
{
	if (c == 'u')
		mlx_image_to_window(game->mlx, game->img->player_up, \
		x * PIXELS, y * PIXELS);
	if (c == 'd')
		mlx_image_to_window(game->mlx, game->img->player_down, \
		x * PIXELS, y * PIXELS);
	if (c == 'l')
		mlx_image_to_window(game->mlx, game->img->player_left, \
		x * PIXELS, y * PIXELS);
	if (c == 'r')
		mlx_image_to_window(game->mlx, game->img->player_right, \
		x * PIXELS, y * PIXELS);
}

t_game	*move_up(t_game *game)
{
	if (game->data[game->player_y - 1][game->player_x] == 'E' && \
	game->total_collect == game->count_c)
	{
		game->player_y -= 1;
		game->img->player->instances[0].y -= 1 * PIXELS;
		game->steps += 1;
		winner_message(game);
		mlx_close_window(game->mlx);
		return (game);
	}
	if (game->data[game->player_y - 1][game->player_x] != '1' \
	&& game->data[game->player_y - 1][game->player_x] != 'E')
	{
		mlx_image_to_window(game->mlx, game->img->floor, \
		game->player_x * PIXELS, game->player_y * PIXELS);
		game->player_y -= 1;
		game->steps += 1;
		change_direction(game, 'u', game->player_x, game->player_y);
		game->img->player->instances[0].y -= 1 * PIXELS;
		update_game(game);
	}
	return (game);
}

t_game	*move_down(t_game *game)
{
	if (game->data[game->player_y + 1][game->player_x] == 'E' && \
	game->total_collect == game->count_c)
	{
		game->player_y += 1;
		game->img->player->instances[0].y += 1 * PIXELS;
		game->steps += 1;
		winner_message(game);
		mlx_close_window(game->mlx);
		return (game);
	}
	if (game->data[game->player_y + 1][game->player_x] != '1' \
	&& game->data[game->player_y + 1][game->player_x] != 'E')
	{
		mlx_image_to_window(game->mlx, game->img->floor, \
		game->player_x * PIXELS, game->player_y * PIXELS);
		game->player_y += 1;
		game->steps += 1;
		change_direction(game, 'd', game->player_x, game->player_y);
		game->img->player->instances[0].y += 1 * PIXELS;
		update_game(game);
	}
	return (game);
}

t_game	*move_left(t_game *game)
{
	if (game->data[game->player_y][game->player_x - 1] == 'E' && \
	game->total_collect == game->count_c)
	{
		game->player_x -= 1;
		game->img->player->instances[0].x -= 1 * PIXELS;
		game->steps += 1;
		winner_message(game);
		mlx_close_window(game->mlx);
		return (game);
	}
	if (game->data[game->player_y][game->player_x - 1] != '1' \
	&& game->data[game->player_y][game->player_x - 1] != 'E')
	{
		mlx_image_to_window(game->mlx, game->img->floor, \
		game->player_x * PIXELS, game->player_y * PIXELS);
		game->player_x -= 1;
		game->steps += 1;
		change_direction(game, 'l', game->player_x, game->player_y);
		game->img->player->instances[0].x -= 1 * PIXELS;
		update_game(game);
	}
	return (game);
}

t_game	*move_right(t_game *game)
{
	if (game->data[game->player_y][game->player_x + 1] == 'E' && \
	game->total_collect == game->count_c)
	{
		game->player_x += 1;
		game->img->player->instances[0].x += 1 * PIXELS;
		game->steps += 1;
		winner_message(game);
		mlx_close_window(game->mlx);
		return (game);
	}
	if (game->data[game->player_y][game->player_x + 1] != '1' \
	&& game->data[game->player_y][game->player_x + 1] != 'E')
	{
		mlx_image_to_window(game->mlx, game->img->floor, \
		game->player_x * PIXELS, game->player_y * PIXELS);
		game->player_x += 1;
		game->steps += 1;
		game->img->player->instances[0].x += 1 * PIXELS;
		change_direction(game, 'r', game->player_x, game->player_y);
		update_game(game);
	}
	return (game);
}
