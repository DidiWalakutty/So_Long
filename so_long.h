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

# define PIXELS 32

typedef struct s_game
{
	char			**data;
	char			**map_copy;
	int				width_x;
	int				height_y;
	int				count_p;
	int				count_c;
	int				count_e;
	mlx_t			*mlx;
	mlx_image_t		*wall;
	mlx_texture_t	*wall_t;
	mlx_image_t		*player;
	mlx_texture_t	*player_t;
	mlx_image_t		*player_up;
	mlx_texture_t	*player_up_t;
	mlx_image_t		*player_down;
	mlx_texture_t	*player_down_t;
	mlx_image_t		*player_left;
	mlx_texture_t	*player_left_t;
	mlx_image_t		*player_right;
	mlx_texture_t	*player_right_t;
	mlx_image_t		*collectable;
	mlx_texture_t	*collectable_t;
	mlx_image_t		*gameover;
	mlx_texture_t	*gameover_t;
	mlx_image_t		*exit;
	mlx_texture_t	*exit_t;
	mlx_image_t		*floor;
	mlx_texture_t	*floor_t;
	int				exit_open;
	int				steps;
	int				player_x;
	int				player_y;
	int				death;	
	int				total_collect;
}	t_game;

// Base
int		main(int argc, char **argv); 

// Map Functions
int		receive_map(int argc, char **argv);
char	**process_map(int fd);
void	initialize_map(t_game *map);

// Map Validation
bool	validate_map(t_game *map);
bool	check_rectangle(t_game *map);
bool	check_horizontal_walls(t_game *map);
bool	check_vertical_walls(t_game *map);
void	check_chars(t_game *map);
void	find_player_position(t_game *map);
char	**duplicate_map(t_game *map);
char	**floodfill(char **copy_map, int y_pos, int x_pos);
bool	valid_path(char **checked);

// Create Window
bool	initialize_window(t_game *map);	
t_game	*load_images(mlx_t *mlx, t_game *map);
void	fill_map(t_game *map, t_game *bag);

// Image Functions
t_game	*load_wall_texture(mlx_t *mlx, t_game *img);
t_game	*load_floor_texture(mlx_t *mlx, t_game *img);
t_game	*load_player_texture(mlx_t *mlx, t_game *img);
t_game	*load_collectable_texture(mlx_t *mlx, t_game *img);
t_game	*load_exit_texture(mlx_t *mlx, t_game *img);
t_game	*load_player_up(mlx_t *mlx, t_game *img);
t_game	*load_player_down(mlx_t *mlx, t_game *img);
t_game	*load_player_left(mlx_t *mlx, t_game *img);
t_game	*load_player_right(mlx_t *mlx, t_game *img);
t_game	*load_gameover(mlx_t *mlx, t_game *img);
bool	place_walls(t_game *map, t_game *bag);
bool	place_player(t_game *map, t_game *bag);
bool	place_collectables(t_game *map, t_game *bag);
bool	place_exit(t_game *map, t_game *bag);
bool	place_floor(t_game *map, t_game *bag);

// Move Functions
void	keydata(mlx_key_data_t keys, void *data);
t_game	*move_up(t_game *game);
t_game	*move_down(t_game *game);
t_game	*move_left(t_game *game);
t_game	*move_right(t_game *game);
void	remove_collectable(t_game *game, int x, int y);
void	update_game(t_game *game);
void	end_game(t_game *game);

// Free and Errors
void	exit_error(char *str);
void	free_complete_map(char **map);
void	free_image_resources(mlx_t *mlx, t_game *game);

#endif
