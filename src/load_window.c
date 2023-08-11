/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_window.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/05 15:18:54 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/11 22:22:21 by diwalaku      ########   odam.nl         */
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

t_game	*load_images(mlx_t *mlx, t_game *map)
{
	t_game	*bag;

	bag = (t_game *)ft_calloc(1, sizeof(t_game));
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
	fill_map(map, bag);
	return (bag);
}
// static void	load_all_players(mlx_t *mlx, t_game *game)
// {
// 	load_player_up(mlx, game);
// 	load_player_down(mlx, game);
// 	load_player_left(mlx, game);
// 	load_player_right(mlx, game);
// }

void	fill_map(t_game *map, t_game *bag)
{
	map->steps = 0;
	map->death = 0;
	if (!place_floor(map, bag) || \
	!place_walls(map, bag) || \
	!place_collectables(map, bag) || \
	!place_exit(map, bag) || \
	!place_player(map, bag))
		exit_error("Couldn't load images to window");
	// load_all_players(map->mlx, bag);
	printf("loaded all player-moves\n");
}
