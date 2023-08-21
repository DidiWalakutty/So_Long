/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_sprites.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/05 19:15:16 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/19 11:27:05 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// mlx_load_png loads a PNG file and returns a mlx_texture_t
// file. 
// mlx_text_to_image converts the pixel data (width heigth etc)
// and returns a pointer to the transformed pixel data.
// mlx_image_to_window takes a pointer to mlx_image_t and
// a pointer to the graphics window.
t_image	*load_wall_texture(mlx_t *mlx, t_image *img)
{
	mlx_texture_t	*wall;

	wall = mlx_load_png("sprites/wall.png");
	if (!wall)
		exit_error("Couldn't load wall png");
	img->wall = mlx_texture_to_image(mlx, wall);
	if (!img->wall)
		exit_error("Couldn't create wall image");
	mlx_delete_texture(wall);
	return (img);
}

// need to delete textures if we already free_image_resources in load_images?
//
// place player_texture back to player_sprites.c
t_image	*load_player_texture(mlx_t *mlx, t_image *img)
{
	mlx_texture_t	*player;

	player = mlx_load_png("sprites/player.png");
	if (!player)
		exit_error("Couldn't load player png");
	img->player = mlx_texture_to_image(mlx, player);
	if (!img->player)
		exit_error("Couldn't create player image");
	mlx_delete_texture(player);
	return (img);
}

t_image	*load_floor_texture(mlx_t *mlx, t_image *img)
{
	mlx_texture_t	*floor;

	floor = mlx_load_png("sprites/floor.png");
	if (!floor)
		exit_error("Couldn't load floor png");
	img->floor = mlx_texture_to_image(mlx, floor);
	if (!img->floor)
		exit_error("Couldn't create floor image");
	mlx_delete_texture(floor);
	return (img);
}

t_image	*load_collectable_texture(mlx_t *mlx, t_image *img)
{
	mlx_texture_t	*collectable;

	collectable = mlx_load_png("sprites/collectable.png");
	if (!collectable)
		exit_error("Couldn't load collectable png");
	img->collectable = mlx_texture_to_image(mlx, collectable);
	if (!img->collectable)
		exit_error("Couldn't craete collectable image");
	mlx_delete_texture(collectable);
	return (img);
}

t_image	*load_exit_texture(mlx_t *mlx, t_image *img)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("sprites/exit.png");
	if (!exit)
		exit_error("Couldn't load exit png");
	img->exit = mlx_texture_to_image(mlx, exit);
	if (!img->exit)
		exit_error("Couldn't create exit image");
	mlx_delete_texture(exit);
	return (img);
}
