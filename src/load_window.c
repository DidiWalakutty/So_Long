/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_window.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/05 15:18:54 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/25 19:06:42 by diwalaku      ########   odam.nl         */
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
		!load_exit_texture(mlx, bag) || \
		!load_enemies(mlx, bag) || \
		!load_player_up(mlx, bag) || \
		!load_player_down(mlx, bag) || \
		!load_player_left(mlx, bag) || \
		!load_player_right(mlx, bag) || \
		!load_death(mlx, bag))
	{
		free_image_resources(mlx, bag);
		exit_error("Couldn't load all images");
	}
	return (bag);
}

void	fill_map(t_game *map)
{
	map->steps = 0;
	map->death = false;
	if (!place_floor(map) || \
	!place_walls(map) || \
	!place_collectables(map) || \
	!place_exit(map) || \
	!place_player(map) || \
	!place_enemy(map))
		exit_error("Couldn't load images to window");
}
