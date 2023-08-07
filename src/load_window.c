/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_window.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/05 15:18:54 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/07 20:14:52 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	initialize_window(t_map *map, t_game *game)
{
	map->mlx = mlx_init(map->width_x * PIXELS, map->height_y * PIXELS, \
				"so_long", false);
	if (!map->mlx)
		return (false);
	return (true);
}

t_game	*load_images(mlx_t *mlx, t_map *map)
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
	fill_map(map, bag);
	return (bag);
}

void	fill_map(t_map *map, t_game *game)
{
	game->steps = 0;
	game->dead = 0;
	game->player_x = map->player_pos_x;
	game->player_y = map->player_pos_y;
	if (!place_floor(map, game) || \
	!place_walls(map, game) ||
	!place_collectables(map, game) || \
	!place_exit(map, game) || \
	!place_player(map, game))
		exit_error("Couldn't load images to window");
}
