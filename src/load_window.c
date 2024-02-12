/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:18:54 by diwalaku          #+#    #+#             */
/*   Updated: 2024/02/11 13:40:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Resizing of the window is possible
// through this function.
bool	initialize_window(t_game *map)
{
	map->mlx = mlx_init(map->width_x * PIXELS, map->height_y * PIXELS, \
				"Lyme Warriors", false);
	if (!map->mlx)
		return (false);
	return (true);
}

void	moves_to_screen(t_game *game)
{
	game->img->print_string = mlx_put_string(game->mlx, \
	"Movecount:", 8, game->height_y * PIXELS - 25);
}

void	print_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->steps);
	mlx_delete_image(game->mlx, game->img->screen_moves);
	game->img->screen_moves = mlx_put_string(game->mlx, moves, \
	110, game->height_y * PIXELS - 25);
	free(moves);
}

void	fill_map(t_game *map)
{
	if (!place_floor(map) || \
	!place_walls(map) || \
	!place_collectables(map) || \
	!place_exit(map) || \
	!place_player(map))
		exit_error("Couldn't load images to window");
	place_enemy(map);
	moves_to_screen(map);
}
