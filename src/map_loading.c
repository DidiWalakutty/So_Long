#HEADER

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
				map->player_pos_x == x;
				map->player_pos_y == y;
				return ;
			}
			x++;
		}
		y++;
	}
}

// Copy the map to check for floodfill.
// Create a 2D array, so **.
char	**duplicate_map(char **)
{
	char	**copy;
	int		x;

	x = 0;
	copy = (char **)ft_calloc((map->heigth_y + 1), sizeof(char *));
	if (!copy)
		exit_error("Couldn't calloc copy of map");
	while (map->contents[x])
	{
		copy[x] = ft_strdup(map->contents[x]);
		x++;
	}
	copy[x] = NULL;
	return (copy);
}

static bool	walkable(t_map *map, int x_pos, int y_pos)
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
char	**floodfill(t_map *map, int x_pos, int y_pos)
{
	if (map[y][x] != '1')
	{
		if (walkable(map, x_pos, y_pas) == true)
			map[y][x] == 'T';
		else
			return (map);
		floodfill(map, x_pos + 1, y_pos);
		floodfill(map, x_pos - 1, y_pos);
		floodfill(map, x_pos, y_pos + 1);
		floodfill(map, x_pos, y_pos - 1);
	}
	return (map);
}

int	after_floodfille(char **checked)
{
	int	x;
	int	y;

	y = 0;
	while (checked[y])
	{
		x = 0;
		while (checked[y][x])
		{

		}
	}
}