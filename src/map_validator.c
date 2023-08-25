/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_validator.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 15:00:24 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/07/31 17:40:23 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static size_t	row_count(char **grid)
{
	size_t	y;

	y = 0;
	while (grid[y])
		y++;
	return (y);
}

void	initialize_map(t_game *map)
{
	map->width_x = ft_strlen(map->data[0]);
	map->height_y = row_count(map->data);
	map->count_p = 0;
	map->count_c = 0;
	map->count_e = 0;
	map->player_x = 0;
	map->player_y = 0;
}

// This functions checks if the map
// is rectangular, is surrounded with walls,
// and has the right chars.
// It initializes the map first, so it knows
// the height and width of the map
bool	validate_map(t_game *map)
{
	char	**flood_map;
	char	**flood_check;

	initialize_map(map);
	if (check_rectangle(map) == false)
		exit_error("This map isn't rectangular! Those ticks will escape!");
	if (check_walls(map) == false)
		exit_error("No surrounding walls, there's ticks everywhere!");
	check_chars(map);
	find_player_position(map);
	flood_map = duplicate_map(map);
	flood_check = floodfill(flood_map, map->player_y, map->player_x);
	if (valid_path(flood_check) == false)
	{
		free_complete_map(flood_check);
		exit_error("Couldn't find a valid path in this infested forest.");
	}
	return (true);
}
