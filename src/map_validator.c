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

void	initialize_map(t_map *map)
{
map->width_x = ft_strlen(map->contents[0]);
map->height_y = row_count(map->contents);
map->count_p = 0;
map->count_c = 0;
map->count_e = 0;
map->player_pos_x = 0;
map->player_pos_y = 0;
map->steps = 0;
}

// This functions checks if the map
// is rectangular, is surrounded with walls,
// and has the right chars.
// It initializes the map first, so it knows
// the height and width of the map
bool	validate_map(t_map *map)
{
	char	**floodfill_map;
	char	**floodfill_check;

	initialize_map(map);
	if (check_rectangle(map) == false)
		exit_error("This map is not rectangular!");
	if (check_horizontal_walls(map) == false)
		exit_error("The map isn't surrounded with walls.");
	if (check_vertical_walls(map) == false)
		exit_error("The map isn't surrounded with walls.");
	check_chars(map);
	find_player_position(map);
	floodfill_map = duplicate_map(map);
	floodfill_check = floodfill(floodfill_map, map->player_pos_x, map->player_pos_y);
	if (valid_path(floodfill_check) == false)
	{
		free_complete_map(floodfill_check);
		exit_error("Couldn't find a valid path.");
	}
	return (true);
}
