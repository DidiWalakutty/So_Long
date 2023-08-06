/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 15:29:02 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/07/31 17:50:26 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_invalids(char c)
{
	if (c != '0' || c != '1')
		exit_error("This is not a valid character");
}

// It sets len to the length of the first row in map.
// We check each data[i]/row on it's length
// compare it with len.
// If it's not the same, it's not rectangular.
// As long as it has four right angles, we're good.
bool	check_rectangle(t_map *map)
{
	int	i;
	int	len;

	i = 0;
	len = map->width_x;
	while (map->data[i])
	{
		if (ft_strlen(map->data[i]) != len)
			return (false);
		i++;
	}
	return (true);
}

// This function checks if the upper and lower
// horizontal rows are '1's only.
// height_y - 1, because of array index 0.
// Checks the positions in different rows
// simultaneously per iterations.
bool	check_horizontal_walls(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->data[0][i])
	{
		if (map->data[0][i] != '1')
			return (false);
		if (map->data[map->height_y - 1][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

// This functions checks if the first and last
// vertical rows are '1's only.
// width_x - 1, because of array index 0.
// Checks the positions in different rows
// simultaneously per iterations
bool	check_vertical_walls(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->data[i][0])
	{
		if (map->data[i][0] != '1')
			return (false);
		if (map->data[i][map->width_x - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

// This functions counts how many CEP's
// are found and if they have a max or min
// of player-pos, exit and collectibles.
// Also checks if the other chars are only
// allowed chars. Set i to 1, because 0 is 1's only
void	check_chars(t_map *map)
{
	int	i;
	int	x;

	i = 1;
	while (map->data[i])
	{
		x = 0;
		while (map->data[i][x])
		{
			if (map->data[i][x] == 'C')
				map->count_c += 1;
			else if (map->data[i][x] == 'E')
				map->count_e += 1;
			else if (map->data[i][x] == 'P')
				map->count_p += 1;
			else
				check_invalids(map->data[i][x]);
			x++;
		}
		i++;
	}
	if (map->count_c < 1 || map->count_e != 1 || map->count_p != 1)
		exit_error("Wrong amount of collectibles, exits or start positions");
}
