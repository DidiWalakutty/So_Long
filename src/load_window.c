/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_window.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/05 15:18:54 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/21 19:36:19 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	initialize_window(t_game *map)
{
	map->mlx = mlx_init(map->width_x * PIXELS, map->height_y * PIXELS, \
				"so_long", false);
	if (!map->mlx)
		return (false);
	return (true);
}

t_image	*load_images(mlx_t *mlx, t_game *map)
{
	t_image	*bag;

	bag = (t_image *)ft_calloc(1, sizeof(t_image));
	if (!bag)
		exit_error("Couldn't calloc space for images");
	if (!load_wall_texture(mlx, bag) || \
		!load_floor_texture(mlx, bag) || \
		!load_player_texture(mlx, bag) || \
		!load_collectable_texture(mlx, bag) || \
		!load_exit_texture(mlx, bag))
	{
		free_image_resources(mlx, bag);
		exit_error("Couldn't load all images");
	}
	printf("loaded pictures\n");
	return (bag);
}
// static void	load_all_players(mlx_t *mlx, t_game *game)
// {
// 	load_player_up(mlx, game);
// 	load_player_down(mlx, game);
// 	load_player_left(mlx, game);
// 	load_player_right(mlx, game);
// }

void	fill_map(t_game *map)
{
	map->steps = 0;
	map->death = 0;
	if (!place_floor(map) || \
	!place_walls(map) || \
	!place_collectables(map) || \
	!place_exit(map) || \
	!place_player(map))
		exit_error("Couldn't load images to window");
	// load_all_players(map->mlx, bag);
	// printf("loaded all player-moves\n");
}
