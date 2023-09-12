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
	int		fd;

	atexit(check_leaks);
	if (argc != 2)
		not_enough_args();
	map.img = (t_image *)ft_calloc(1, sizeof(t_image));
	if (!map.img)
		exit_error("Couldn't malloc space for images");
	fd = receive_map(argv);
	map.data = process_map(fd);
	if (!map.data)
		return (1);
	if (validate_map(&map) == false)
		exit_error("Couldn't validate map");
	if (initialize_window(&map) == false)
		free_complete_map(map.data);
	make_images(&map, map.img);
	fill_map(&map);
	start_game_message();
	mlx_key_hook(map.mlx, keydata, &map);
	mlx_loop(map.mlx);
	mlx_terminate(map.mlx);
	free_textures(map.img);
	free_complete_map(map.data);
	return (0);
}
