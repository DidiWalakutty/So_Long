# HEADER

#include "so_long.h"

int	receive_map(int argc, char **argv)
{
    int fd;

	if (argc != 2)
		exit_error("Argument count should be 2.");
	fd = open(argv[i], O_RDONLY);
	if (fd <= 0)
		exit_error("Couldn't open file.");
	if (strncmp(argv[i] + ft_strlen(1) - 4, ".ber", 4))
		exit_error("This is not a .ber file.");
	return (fd);
}

// **char represents a 2D array map/grid and will use
// X-rows and Y-columns 
char	**process_map(int fd)
{
	char	*map;
	char	*row;
	char	**result;

	map = NULL;
	row = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		
	}
}