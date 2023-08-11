/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_sprites.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/05 19:15:16 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/11 21:58:21 by diwalaku      ########   odam.nl         */
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
	img->wall_t = mlx_load_png("sprites/wall.png");
	if (!img->wall_t)
		exit_error("Couldn't load wall png");
	img->wall = mlx_texture_to_image(mlx, img->wall_t);
	if (!img->wall)
		exit_error("Couldn't create wall image");
	return (img);
}

// place player_texture back to player_sprites.c
t_game	*load_player_texture(mlx_t *mlx, t_game *img)
{
	img->player_t = mlx_load_png("sprites/player.png");
	if (!img->player_t)
		exit_error("Couldn't load player png");
	img->player = mlx_texture_to_image(mlx, img->player_t);
	if (!img->player)
		exit_error("Couldn't create player image");
	return (img);
}

t_game	*load_floor_texture(mlx_t *mlx, t_game *img)
{
	img->floor_t = mlx_load_png("sprites/floor.png");
	if (!img->floor_t)
		exit_error("Couldn't load floor png");
	img->floor = mlx_texture_to_image(mlx, img->floor_t);
	if (!img->floor)
		exit_error("Couldn't create floor image");
	return (img);
}

t_game	*load_collectable_texture(mlx_t *mlx, t_game *img)
{
	img->collectable_t = mlx_load_png("sprites/collectable.png");
	if (!img->collectable_t)
		exit_error("Couldn't load collectable png");
	img->collectable = mlx_texture_to_image(mlx, img->collectable_t);
	if (!img->collectable)
		exit_error("Couldn't craete collectable image");
	return (img);
}

t_game	*load_exit_texture(mlx_t *mlx, t_game *img)
{
	img->exit_t = mlx_load_png("sprites/exit.png");
	if (!img->exit_t)
		exit_error("Couldn't load exit png");
	img->exit = mlx_texture_to_image(mlx, img->exit_t);
	if (!img->exit)
		exit_error("Couldn't create exit image");
	return (img);
}
