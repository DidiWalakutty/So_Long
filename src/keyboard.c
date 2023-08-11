/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyboard.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 17:17:40 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/11 22:21:04 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	choose_player_direction(mlx_t *mlx, t_game *game, char dir)
{
	if (dir == 'u')
		mlx_image_to_window(mlx, game->player_up, \
		game->player_x * PIXELS, game->player_y * PIXELS);
	if (dir == 'd')
		mlx_image_to_window(mlx, game->player_down, \
		game->player_x * PIXELS, game->player_y * PIXELS);
	if (dir == 'l')
		mlx_image_to_window(mlx, game->player_left, \
		game->player_x * PIXELS, game->player_y * PIXELS);
	if (dir == 'r')
		mlx_image_to_window(mlx, game->player_right, \
		game->player_x * PIXELS, game->player_y * PIXELS);
}

static void	move(mlx_t *mlx, t_game *game, char line, char dir)
{
	// select_move(game, line, dir);
	choose_player_direction(mlx, game, dir);
}

void	keydata(mlx_key_data_t keys, void *data)
{
	t_game	*grid;

	grid = (t_game *) data;
	if (keys.action == MLX_PRESS && grid->death != 0)
	{
		if (keys.key == MLX_KEY_ESCAPE)
			mlx_close_window(grid->mlx);
		else if (keys.key == MLX_KEY_W)
			move(grid->mlx, grid, 'y', 'u');
		else if (keys.key == MLX_KEY_S)
			move(grid->mlx, grid, 'y', 'd');
		else if (keys.key == MLX_KEY_A)
			move(grid->mlx, grid, 'x', 'l');
		else if (keys.key == MLX_KEY_D)
			move(grid->mlx, grid, 'x', 'r');
	}
}

// static void	select_move(t_game *game, char line, char dir)
// {
// 	if (line == 'y')
// 	{
// 		if (dir == 'u')
// 			move_up(game->);
// 		else
// 			move_down();
// 	}
// 	if (line == 'x')
// 	{
// 		if (dir == 'l')
// 			move_left();
// 		else
// 			move_right();
// 	}
// }

