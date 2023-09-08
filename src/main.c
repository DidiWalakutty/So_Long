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

void check_leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_game	map;
	t_image	*images;
	int		fd;
	int		i;

	i = 0;
	atexit(check_leaks);
	// system("leaks -q so_long");
	if (argc != 2)
		not_enough_args();
	fd = receive_map(argc, argv);
	map.data = process_map(fd);
	if (!map.data)
		return (0);
	if (validate_map(&map) == false)
		exit_error("Couldn't validate map");
	if (initialize_window(&map) == false)
		free_complete_map(map.data);
	images = load_images(map.mlx, &map); // how to free bag in load_images? just above terminate?
	map.img = images;
	fill_map(&map);
	start_game_message();
	mlx_key_hook(map.mlx, keydata, &map);
	mlx_loop(map.mlx);
	// free_image_resources(map.mlx, map.img);
	mlx_terminate(map.mlx);
	return (1);
}
