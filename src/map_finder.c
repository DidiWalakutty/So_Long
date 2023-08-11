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
void	find_player_position(t_game *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->data[y])
	{
		x = 0;
		while (map->data[y][x])
		{
			if (map->data[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

// Copy the map to check for floodfill.
// Create a 2D array, so **.
//
// printf("map_copy is: %s\n", map->map_copy[x]);
char	**duplicate_map(t_game *map)
{
	int		x;

	x = 0;
	map->map_copy = (char **)ft_calloc((map->height_y + 1), sizeof(char *));
	if (!map->map_copy)
		exit_error("Couldn't calloc copy of map");
	while (map->data[x])
	{
		map->map_copy[x] = ft_strdup(map->data[x]);
		if (!map->map_copy[x])
		{
			free_complete_map(map->map_copy);
			exit_error("Couldn't copy data to copy of map");
		}
		x++;
	}
	return (map->map_copy);
}

static bool	walkable(char **map, int y, int x)
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
//
// printf("in loop: char is %c\n", copy_map[y_pos][x_pos]);
char	**floodfill(char **copy_map, int y_pos, int x_pos)
{
	if (copy_map[y_pos][x_pos] != '1')
	{
		if (walkable(copy_map, y_pos, x_pos) == true)
			copy_map[y_pos][x_pos] = 'T';
		else
			return (copy_map);
		floodfill(copy_map, y_pos, x_pos + 1);
		floodfill(copy_map, y_pos, x_pos - 1);
		floodfill(copy_map, y_pos + 1, x_pos);
		floodfill(copy_map, y_pos - 1, x_pos);
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
			if (checked[y][x] != 'T' && checked[y][x] != '1')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}
