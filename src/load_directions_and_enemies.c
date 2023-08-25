/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_directions_and_enemies.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/25 17:08:23 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/25 19:24:43 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_image	*load_player_up(mlx_t *mlx, t_image *img)
{
	mlx_texture_t	*player_up;

	player_up = mlx_load_png("sprites/player_up.png");
	if (!player_up)
		exit_error("Couldn't load player_up png");
	img->player_up = mlx_texture_to_image(mlx, player_up);
	if (!img->player_up)
		exit_error("Couldn't create player_up image");
	return (img);
}

t_image	*load_player_down(mlx_t *mlx, t_image *img)
{
	mlx_texture_t	*player_down;

	player_down = mlx_load_png("sprites/player_down.png");
	if (!player_down)
		exit_error("Couldn't load player_down png");
	img->player_down = mlx_texture_to_image(mlx, player_down);
	if (!img->player_down)
		exit_error("Couldn't create player_down image");
	return (img);
}

t_image	*load_player_left(mlx_t *mlx, t_image *img)
{
	mlx_texture_t	*player_left;

	player_left = mlx_load_png("sprites/player_left.png");
	if (!player_left)
		exit_error("Couldn't load player_left png");
	img->player_left = mlx_texture_to_image(mlx, player_left);
	if (!img->player_left)
		exit_error("Couldn't create player_left image");
	return (img);
}

t_image	*load_player_right(mlx_t *mlx, t_image *img)
{
	mlx_texture_t	*player_right;

	player_right = mlx_load_png("sprites/player_right.png");
	if (!player_right)
		exit_error("Couldn't load player_right png");
	img->player_right = mlx_texture_to_image(mlx, player_right);
	if (!img->player_right)
		exit_error("Couldn't create player_right image");
	return (img);
}

t_image	*load_enemies(mlx_t *mlx, t_image *img)
{
	mlx_texture_t	*enemy;

	enemy = mlx_load_png("sprites/enemies.png");
	if (!enemy)
		exit_error("Couldn't load enemies png");
	img->enemy = mlx_texture_to_image(mlx, enemy);
	if (!img->enemy)
		exit_error("Couldn't create enemy image");
	return (img);
}
