/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_sprites.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/05 19:15:16 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/09/12 18:12:52 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


static void	make_textures(t_image *img)
{
	img->floor_t = mlx_load_png("sprites/floor.png");
	img->wall_t = mlx_load_png("sprites/wall.png");
	img->exit_t = mlx_load_png("sprites/exit.png");
	img->collectable_t = mlx_load_png("sprites/collectable.png");
	img->player_t = mlx_load_png("sprites/player.png");
	img->player_up_t = mlx_load_png("sprites/player_up.png");
	img->player_down_t = mlx_load_png("sprites/player_down.png");
	img->player_left_t = mlx_load_png("sprites/player_left.png");
	img->player_right_t = mlx_load_png("sprites/player_right.png");
	img->enemy_t = mlx_load_png("sprites/enemies.png");
	img->rip_t = mlx_load_png("sprites/death.png");
}

void	make_images(t_game *map, t_image *img)
{
	make_textures(img);
	img->floor = mlx_texture_to_image(map->mlx, img->floor_t);
	img->wall = mlx_texture_to_image(map->mlx, img->wall_t);
	img->exit = mlx_texture_to_image(map->mlx, img->exit_t);
	img->collectable = mlx_texture_to_image(map->mlx, img->collectable_t);
	img->player = mlx_texture_to_image(map->mlx, img->player_t);
	img->player_up = mlx_texture_to_image(map->mlx, img->player_up_t);
	img->player_down = mlx_texture_to_image(map->mlx, img->player_down_t);
	img->player_left = mlx_texture_to_image(map->mlx, img->player_left_t);
	img->player_right = mlx_texture_to_image(map->mlx, img->player_right_t);
	img->enemy = mlx_texture_to_image(map->mlx, img->enemy_t);
	img->rip = mlx_texture_to_image(map->mlx, img->rip_t);
}

