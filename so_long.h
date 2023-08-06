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

# define PIXELS 64

typedef struct s_game
{
	int				steps;
	int				collectables;
	mlx_image_t		*wall_i;
	mlx_texture_t	*wall_t;
	mlx_image_t		*player_i;
	mlx_texture_t	*player_t;
	mlx_image_t		*collect_i;
	mlx_texture_t	*collect_t;
	mlx_image_t		*exit_i;
	mlx_texture_t	*exit_t;
	mlx_image_t		*floor_i;
	mlx_texture_t	*floor_t;
}	t_game;

typedef struct s_map
{
	char	**data;
	char	**map_copy;
	int		width_x;
	int		height_y;
	int		count_p;
	int		count_c;
	int		count_e;
	int		player_pos_x;
	int		player_pos_y;
	mlx_t	*mlx;
	t_game	*game;
}	t_map;

// Base
int		main(int argc, char **argv); 

// Map Functions
int		receive_map(int argc, char **argv);
char	**process_map(int fd);
void	initialize_map(t_map *map);

// Map Validation
bool	validate_map(t_map *map);
bool	check_rectangle(t_map *map);
bool	check_horizontal_walls(t_map *map);
bool	check_vertical_walls(t_map *map);
void	check_chars(t_map *map);
void	find_player_position(t_map *map);
char	**duplicate_map(t_map *map);
char	**floodfill(char **copy_map, int x_pos, int y_pos);
bool	valid_path(char **checked);

// Create Window
bool	initialize_window(t_map *map, t_game *game);	
t_game	*load_images(mlx_t *mlx);

// Image Functions
t_game	*load_wall_texture(mlx_t *mlx, t_game *img);
t_game	*load_floor_texture(mlx_t *mlx, t_game *img);
t_game	*load_player_texture(mlx_t *mlx, t_game *img);
t_game	*load_collectable_texture(mlx_t *mlx, t_game *img);
t_game	*load_exit_texture(mlx_t *mlx, t_game *img);

// Move Functions

// Free and Errors
void	exit_error(char *str);
void	free_complete_map(char **map);

#endif