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

void	free_game_resources(t_game *game)
{
	if (game)
	{
		if (game->wall_t)
			mlx_delete_texture(game->wall_t);
		if (game->player_t)
			mlx_delete_texture(game->player_t);
		if (game->collect_t)
			mlx_delete_texture(game->collect_t);
		if (game->floor_t)
			mlx_delete_texture(game->floor_t);
		if (game->exit_t)
			mlx_delete_texture(game->exit_t);
	}
}
