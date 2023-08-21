/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyboard.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 17:17:40 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/21 17:49:35 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// static void	choose_player_direction(mlx_t *mlx, t_game *game, char dir)
// {
// 	if (dir == 'u')
// 		mlx_image_to_window(mlx, game->player_up, 0, 0);
// 	// mlx->player, game->player_up, 0, 0);
// 	if (dir == 'd')
// 		mlx_image_to_window(mlx, game->player_down, 0, 0);
// 	if (dir == 'l')
// 		mlx_image_to_window(mlx, game->player_left, 0, 0);
// 	if (dir == 'r')
// 		mlx_image_to_window(mlx, game->player_right, 0, 0);
// }

static void	select_move(t_game *game, char line, char dir)
{
	if (line == 'y')
	{
		if (dir == 'u')
			move_up(game);
		else
			move_down(game);
	}
	if (line == 'x')
	{
		if (dir == 'l')
			move_left(game);
		else
			move_right(game);
	}
}

static void	move(t_game *game, char line, char dir)
{
	// printf("line: %c, dir: %c\n", line, dir);
	select_move(game, line, dir);
	// choose_player_direction(game->mlx, game, dir);
}

// add functionality for arrow buttons?
void	keydata(mlx_key_data_t keys, void *data)
{
	t_game	*game;

	game = (t_game *) data;
	if (keys.key == MLX_KEY_ESCAPE && keys.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keys.key == MLX_KEY_W && keys.action == MLX_PRESS)
		move_up(game);
	if (keys.key == MLX_KEY_S && keys.action == MLX_PRESS)
		move_down(game);
	if (keys.key == MLX_KEY_A && keys.action == MLX_PRESS)
		move_left(game);
	if (keys.key == MLX_KEY_D && keys.action == MLX_PRESS)
		move_right(game);
}
