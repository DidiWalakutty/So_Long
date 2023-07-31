/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/28 14:35:42 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/07/28 21:03:54 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <memory.h>
# include <time.h>

typedef struct s_map
{
    char	**contents;
	char	**copy_content;
	int		width_x;
	int		height_y;
	int		count_p;
	int		count_c;
	int		count_e;
	int		player_pos_x;
	int		player_pos_y;
	int		steps;
}	t_map;

// Base
int		main(int argc, char **argv); 

// Map Functions
int		receive_map(int argc, char **argv);
char	**process_map(int fd);
void	initialize_map(t_map *map);

// Map Validation
bool	validate_map(t_map *map);
size_t	row_count(char **grid);
bool	check_walls_and_chars(t_map *map);
bool	check_rectangle(t_map *map);
bool	check_horizontal(t_map *map);
bool	check_vertical(t_map *map);
void	check_chars(t_map *map);

// Image Functions

// Move Functions

// Free and Errors
void	exit_error(char *str);


#endif