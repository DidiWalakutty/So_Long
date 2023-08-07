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

void	free_image_resources(mlx_t *mlx, t_game *game)
{
	if (game)
	{
		if (game->wall)
			mlx_delete_image(mlx, game->wall);
		if (game->playr)
			mlx_delete_image(mlx, game->playr);
		if (game->collc)
			mlx_delete_image(mlx, game->collc);
		if (game->floor)
			mlx_delete_image(mlx, game->floor);
		if (game->exit)
			mlx_delete_image(mlx, game->exit);
	}
}
