# HEADER

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	int		fd;
	int		i;

	i = 0;
	fd = receive_map(argc, argv);
	map.contents = process_map(fd);

}