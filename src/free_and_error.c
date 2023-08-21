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

void	free_image_resources(mlx_t *mlx, t_image *img)
{
	if (img)
	{
		if (img->wall)
			mlx_delete_image(mlx, img->wall);
		if (img->player)
			mlx_delete_image(mlx, img->player);
		if (img->collectable)
			mlx_delete_image(mlx, img->collectable);
		if (img->floor)
			mlx_delete_image(mlx, img->floor);
		if (img->exit)
			mlx_delete_image(mlx, img->exit);
	}
}
