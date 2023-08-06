/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_sprites.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/05 19:15:16 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/06 11:55:20 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// mlx_load_png loads a PNG file and returns a mlx_texture_t
// file. 
// mlx_text_to_image converts the pixel data (width heigth etc)
// and returns a pointer to the transformed pixel data.
// mlx_image_to_window takes a pointer to mlx_image_t and
// a pointer to the graphics window.
t_game	*load_wall_texture(mlx_t *mlx, t_game *img)
{
	mlx_texture_t	*wall;

	wall = mlx_load_png("./ path to png");
	if (!wall)
		exit_error("Couldn't load wall png");
	img->wall_t = mlx_texture_to_image(mlx, wall);
	if (!img->wall_t)
		exit_error("Couldn't create wall image");
	mlx_delete_texture(wall);
	return (img);
}

t_game	*load_floor_texture(mlx_t *mlx, t_game *img)
{
	mlx_texture_t	*floor;

	floor = mlx_load_png("./ path to png");
	if (!floor)
		exit_error("Couldn't load floor png");
	img->floor_t = mlx_texture_to_image(mlx, floor);
	if (!img->floor_t)
		exit_error("Couldn't create floor image");
	mlx_delete_texture(floor);
	return (img);
}

// somewhere else if I want close exit?
t_game	*load_player_texture(mlx_t *mlx, t_game *img)
{
	mlx_texture_t	*player;

	player = mlx_load_png("./ path to png");
	if (!player)
		exit_error("Couldn't load player png");
	img->player_t = mlx_texture_to_image(mlx, player);
	if (img->player_t)
		exit_error("Couldn't create player image");
	mlx_delete_texture(player);
	return (img);
}

t_game	*load_collectable_texture(mlx_t *mlx, t_game *img)
{
	mlx_texture_t	*collectable;

	collectable = mlx_load_png("./ path to png");
	if (!collectable)
		exit_error("Couldn't load collectable png");
	img->collect_t = mlx_texture_to_image(mlx, collectable);
	if (!img->collect_t)
		exit_error("Couldn't craete collectable image");
	mlx_delete_texture(collectable);
	return (img);
}

t_game	*load_exit_texture(mlx_t *mlx, t_game *img)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("./ path to png");
	if (!exit)
		exit_error("Couldn't load exit png");
	img->exit_t = mlx_texture_to_image(mlx, exit);
	if (img->exit_t)
		exit_error("Couldn't create exit image");
	mlx_delete_texture(exit);
	return (img);
}
