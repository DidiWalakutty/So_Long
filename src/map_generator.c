/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_checker.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 11:30:44 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/07/31 11:30:44 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// This function checks the argc, opens the fd
// and checks if there's a .ber file given
// strncmp compares argv[i] on position strlen - 4
// so points to the last 4 chars of argv[i].
// It searches for ".ber". If it returns 0,
// the ".ber" has been found, if it != 0,
// those 4 chars don't match ".ber"
int	receive_map(int argc, char **argv)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(argv[i], O_RDONLY);
	if (fd <= 0)
		exit_error("Couldn't open file.");
	if ((ft_strncmp(argv[i] + ft_strlen(argv[1]) - 4, ".ber", 4)) != 0)
		exit_error("This is not a .ber file.");
	return (fd);
}

	//ft_strlcpy(new, s1, len1 + 1);
	//ft_strlcat(new + len1, s2, len2 + 1);
static char	*add_row_to_map(char *s1, char *s2)
{
	char	*new;
	int		len1;
	int		len2;
	int		totallen;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	totallen = len1 + len2;
	new = ft_calloc((totallen + 1), sizeof(char));
	if (!new)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	copy_str(s1, s2);
	copy_str(&s1[len1], s2);
	free(s1);
	free(s2);
	return (new);
}

// **result represents a 2D array map/grid and will use
// X-rows and Y-columns. Each row is filled with gnl.
// We add each row to the map and split it on each \n.
char	**process_map(int fd)
{
	char	*map;
	char	*row;
	char	**parsed;

	map = NULL;
	row = NULL;
	while (1)
	{
		row = get_next_line(fd);
		if (row == NULL)
			break ;
		map = add_row_to_map(map, row);
		if (!map)
			exit_error("Couldn't add row to map");
	}
	if (map == NULL)
		exit_error("Unable to read and create map");
	parsed = ft_split(map, '\n');
	free(map);
	if (!parsed)
		exit_error("Couldn't split on newline");
	return (parsed);
}
