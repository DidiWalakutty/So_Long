/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_loading.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/05 10:43:56 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/05 10:43:56 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// This functions searches for the position of
// the start position of the player "P".
// Y is length, x is width.
void	find_player_position(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->contents[y])
	{
		x = 0;
		while (map->contents[y][x])
		{
			if (map->contents[y][x] == 'P')
			{
				map->player_pos_x = x;
				map->player_pos_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

// Copy the map to check for floodfill.
// Create a 2D array, so **.
char	**duplicate_map(t_map *map)
{
	int		x;

	x = 0;
	map->map_copy = (char **)ft_calloc((map->height_y + 1), sizeof(char *));
	if (!map->map_copy)
		exit_error("Couldn't calloc copy of map");
	while (map->contents[x])
	{
		map->map_copy[x] = ft_strdup(map->contents[x]);
		if (!map->map_copy[x])
		{
			free_complete_map(map->map_copy);
			exit_error("Couldn't copy contents to copy of map");
		}
		x++;
	}
	return (map->map_copy);
}

static bool	walkable(char **map, int x, int y)
{
	if (map[y][x] == 'P' || map[y][x] == 'C' || \
	map[y][x] == 'E' || map[y][x] == '0')
		return (true);
	else
		return (false);
}

// This function crosses and marks all connectable
// walkable cells in the array, using recursion.
// The recursion calls handle the adjacent cells - or
// 4 directionally. When it's done, all cells that aren't
// '1' will be marked with 'T' (for true).
// All non-walkable/'1' cells are left untouched.
char	**floodfill(char **copy_map, int x_pos, int y_pos)
{
	if (copy_map[y_pos][x_pos] != '1')
	{
		if (walkable(copy_map, x_pos, y_pos) == true)
			copy_map[y_pos][x_pos] = 'T';
		else
			return (copy_map);
		floodfill(copy_map, x_pos + 1, y_pos);
		floodfill(copy_map, x_pos - 1, y_pos);
		floodfill(copy_map, x_pos, y_pos + 1);
		floodfill(copy_map, x_pos, y_pos - 1);
	}
	return (copy_map);
}

// This function checks if the data from floodfill
// contains 'T' from True, or '1's, walls only.
bool	valid_path(char **checked)
{
	int	x;
	int	y;

	y = 0;
	while (checked[y])
	{
		x = 0;
		while (checked[y][x])
		{
			if (checked[y][x] != 'T' || checked[y][x] != '1')
				return (false);
			x++;
		}
		y++;
	}
}