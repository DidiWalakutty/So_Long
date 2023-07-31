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

bool	check_rectangle(t_map *map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map->contents[i]);
	while (map->contents[i])
	{
		if (ft_strlen(map->contents[i]) != len)
			return (false);
		i++;
	}
	return (true);
}

bool	check_horizontal(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->contents[0][i])
	{
		if (map->contents[0][i] != '1')
			return (false);
		if (map->contents[map->height_y - 1][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	check_vertical(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->contents[i][0])
	{
		if (map->contents[i][0] != '1')
			return (false);
		if (map->contents[i][map->width_x - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

void	check_chars(t_map *map)
{
	int	i;
	int	x;

	i = 1;
	while (map->contents[i])
	{
		x = 0;
		while (map->contents[i][x])
		{
			if (map->contents[i][x] == 'C')
				map->count_c += 1;
			if (map->contents[i][x] == 'E')
				map->count_e += 1;
			if (map->contents[i][x] == 'P')
				map->count_p += 1;
			else
				check_invalids(map->contents[i][x]);
			x++;
		}
		i++;
	}
	if (map->count_c < 1 || map->count_e != 1 || map->count_p != 1)
		exit_error("Wrong amount of collectibles, exits or start positions");
}
