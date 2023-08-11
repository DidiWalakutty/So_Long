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

// difference between map.game and map->game:
//
// map.game reaches directly in the box "map" and
// grabbing what's in the "game" department.
//
// map->game points to the box "map" and says:
// go to the "game" compartment and find what's
// inside it.
//
// Use '&' when you want a function to modify 
// the value of a variable and pass it by reference.
int	main(int argc, char **argv)
{
	t_game	map;
	t_game	*images;
	int		fd;
	int		i;

	i = 0;
	if (argc != 2)
		exit_error("There should only be 2 arguments");
	fd = receive_map(argc, argv);
	map.data = process_map(fd);
	if (!map.data)
		return (0);
	if (validate_map(&map) == false)
		exit_error("Couldn't validate map");
	if (initialize_window(&map) == false)
		free_complete_map(map.data);
	// can't fill map with images after putting it all in one struct.
	images = load_images(map.mlx, &map);
	// mlx_key_hook(map.mlx, keydata, &map);
	// loop and hook's aren't done yet, current mlx_loop is just for checking
	mlx_loop(map.mlx);
	return (1);
}
