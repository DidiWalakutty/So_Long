/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_player_sprites.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 19:09:09 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/16 12:44:00 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_game	*load_player_up(mlx_t *mlx, t_game *img)
{
	img->player_up_t = mlx_load_png("sprites/player_up.png");
	if (!img->player_up_t)
		exit_error("Couldn't load player_up png");
	img->player_up = mlx_texture_to_image(mlx, img->player_up_t);
	if (!img->player_up)
		exit_error("Couldn't create player_up image");
	return (img);
}

t_game	*load_player_down(mlx_t *mlx, t_game *img)
{
	img->player_down_t = mlx_load_png("sprites/player_down.png");
	if (!img->player_down_t)
		exit_error("Couldn't load player_down png");
	img->player_down = mlx_texture_to_image(mlx, img->player_down_t);
	if (!img->player_down)
		exit_error("Couldn't create player_down image");
	return (img);
}

t_game	*load_player_left(mlx_t *mlx, t_game *img)
{
	img->player_left_t = mlx_load_png("sprites/player_left.png");
	if (!img->player_left_t)
		exit_error("Couldn't load player_left png");
	img->player_left = mlx_texture_to_image(mlx, img->player_left_t);
	if (!img->player_left)
		exit_error("Couldn't create player_left image");
	return (img);
}

t_game	*load_player_right(mlx_t *mlx, t_game *img)
{
	img->player_right_t = mlx_load_png("sprites/player_right.png");
	if (!img->player_right_t)
		exit_error("Couldn't load player_right png");
	img->player_right = mlx_texture_to_image(mlx, img->player_right_t);
	if (!img->player_right)
		exit_error("Couldn't create player_right image");
	return (img);
}

t_game	*load_gameover(mlx_t *mlx, t_game *img)
{
	img->gameover_t = mlx_load_png("sprites/gameover.png");
	if (!img->gameover_t)
		exit_error("Couldn't load gameover png");
	img->gameover = mlx_texture_to_image(mlx, img->gameover_t);
	if (!img->gameover)
		exit_error("Couldn't create gameover image");
	return (img);
}