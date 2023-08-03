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

bool	check_walls_and_chars(t_map *map)
{
	if (check_rectangle(map) == false)
		exit_error("The map is not rectangular");
	if (check_horizontal(map) == false)
		exit_error("The map isn't surrounded with walls");
	if (check_vertical(map) == false)
		exit_error("The map isn't surrounded with walls");
	check_chars(map);
	return (true);
}

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
	char	**map_copy;
	char	**floodfill_check;

	initialize_map(map);
	if (check_rectangle(map) == false)
		exit_error("This map is not rectangular!");
	if (check_horizontal(map) == false)
		exit_error("The map isn't surrounded with walls.");
	if (check_vertical(map) == false)
		exit_error("The map isn't surrounded with walls.");
	check_chars(map);
	player_position(map);
	map_copy = duplicate_map(char **map_copy);
	floodfill_check = floodfill(map_copy, map->player_pos_x, map->player_pos_y);
	if (after_floodfill(floodfill_check != 'T'))
	// if ! floodfill
	return (true);
}
