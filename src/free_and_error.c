/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_and_error.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 11:30:57 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/07/31 11:30:57 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_error(char *str)
{
	ft_printf("ERROR\n%s\n", str);
	exit(EXIT_FAILURE);
}

void	free_complete_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_textures(t_image *img)
{
	mlx_delete_texture(img->floor_t);
	mlx_delete_texture(img->wall_t);
	mlx_delete_texture(img->player_t);
	mlx_delete_texture(img->collectable_t);
	mlx_delete_texture(img->exit_t);
	mlx_delete_texture(img->player_up_t);
	mlx_delete_texture(img->player_down_t);
	mlx_delete_texture(img->player_left_t);
	mlx_delete_texture(img->player_right_t);
	mlx_delete_texture(img->enemy_t);
	mlx_delete_texture(img->rip_t);
	free(img);
}
