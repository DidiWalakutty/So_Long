/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_sprites.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/05 19:15:16 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/06 16:36:31 by diwalaku      ########   odam.nl         */
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
	mlx_texture_t	*wall_png;

	wall_png = mlx_load_png("./ path to png");
	if (!wall_png)
		exit_error("Couldn't load wall png");
	img->wall = mlx_texture_to_image(mlx, wall_png);
	if (!img->wall)
		exit_error("Couldn't create wall image");
	return (img);
}

t_game	*load_floor_texture(mlx_t *mlx, t_game *img)
{
	mlx_texture_t	*floor_png;

	floor_png = mlx_load_png("./ path to png");
	if (!floor_png)
		exit_error("Couldn't load floor png");
	img->floor = mlx_texture_to_image(mlx, floor_png);
	if (!img->floor)
		exit_error("Couldn't create floor image");
	return (img);
}

// somewhere else if I want close exit?
t_game	*load_player_texture(mlx_t *mlx, t_game *img)
{
	mlx_texture_t	*player_png;

	player_png = mlx_load_png("./ path to png");
	if (!player_png)
		exit_error("Couldn't load player png");
	img->playr = mlx_texture_to_image(mlx, player_png);
	if (img->playr)
		exit_error("Couldn't create player image");
	return (img);
}

t_game	*load_collectable_texture(mlx_t *mlx, t_game *img)
{
	mlx_texture_t	*collectable_png;

	collectable_png = mlx_load_png("./ path to png");
	if (!collectable_png)
		exit_error("Couldn't load collectable png");
	img->coll = mlx_texture_to_image(mlx, collectable_png);
	if (!img->coll)
		exit_error("Couldn't craete collectable image");
	return (img);
}

t_game	*load_exit_texture(mlx_t *mlx, t_game *img)
{
	mlx_texture_t	*exit_png;

	exit_png = mlx_load_png("./ path to png");
	if (!exit_png)
		exit_error("Couldn't load exit png");
	img->exit = mlx_texture_to_image(mlx, exit_png);
	if (img->exit)
		exit_error("Couldn't create exit image");
	return (img);
}
