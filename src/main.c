/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/31 11:30:49 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/07/31 11:30:49 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	int		fd;
	int		i;

	i = 0;
	if (argc != 2)
		exit_error("There should only be 2 arguments");
	fd = receive_map(argc, argv);
	map.contents = process_map(fd);
	if (!map.contents)
		return (0);
	if (validate_map(&map) == false)
		exit_error("Couldn't validate map");
}
