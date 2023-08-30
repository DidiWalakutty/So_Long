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

typedef struct s_images
{
	mlx_image_t		*floor;
	mlx_image_t		*wall;
	mlx_image_t		*player;
	mlx_image_t		*player_up;
	mlx_image_t		*player_down;
	mlx_image_t		*player_left;
	mlx_image_t		*player_right;
	mlx_image_t		*collectable;
	mlx_image_t		*enemy;
	mlx_image_t		*you_die;
	mlx_image_t		*exit;
	mlx_image_t		*print_string;
	mlx_image_t		*screen_moves;
}	t_image;

typedef struct s_game
{
	char			**data;
	char			**map_copy;
	int				width_x;
	int				height_y;
	int				count_p;
	int				count_c;
	int				count_e;
	int				player_x;
	int				player_y;
	int				steps;
	int				total_collect;
	int				death;
	mlx_t			*mlx;
	t_image			*img;
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
bool	check_walls(t_game *map);
void	check_chars(t_game *map);
void	find_player_position(t_game *map);
char	**duplicate_map(t_game *map);
char	**floodfill(char **copy_map, int y_pos, int x_pos);
bool	valid_path(char **checked);

// Create Window
bool	initialize_window(t_game *map);	
t_image	*load_images(mlx_t *mlx, t_game *map);
void	fill_map(t_game *map);
void	moves_to_screen(t_game *map);
void	print_moves(t_game *game);

// Image Functions
t_image	*load_wall_texture(mlx_t *mlx, t_image *img);
t_image	*load_floor_texture(mlx_t *mlx, t_image *img);
t_image	*load_player_texture(mlx_t *mlx, t_image *img);
t_image	*load_collectable_texture(mlx_t *mlx, t_image *img);
t_image	*load_exit_texture(mlx_t *mlx, t_image *img);
t_image	*load_player_up(mlx_t *mlx, t_image *img);
t_image	*load_player_down(mlx_t *mlx, t_image *img);
t_image	*load_player_left(mlx_t *mlx, t_image *img);
t_image	*load_player_right(mlx_t *mlx, t_image *img);
t_image *load_enemies(mlx_t *mlx, t_image *img);
t_image	*load_death(mlx_t *mlx, t_image *img);
bool	place_walls(t_game *map);
bool	place_player(t_game *map);
bool	place_collectables(t_game *map);
bool	place_exit(t_game *map);
bool	place_floor(t_game *map);
bool	place_enemy(t_game *map);

// Move Functions
void	keydata(mlx_key_data_t keys, void *data);
t_game	*move_up(t_game *game);
t_game	*move_down(t_game *game);
t_game	*move_left(t_game *game);
t_game	*move_right(t_game *game);
void	remove_collectable(t_game *game, int y, int x);
void	update_game(t_game *game);
void	end_game(t_game *game);

// Free, Errors and messages
void	exit_error(char *str);
void	free_complete_map(char **map);
void	free_image_resources(mlx_t *mlx, t_image *img);
void	not_enough_args(void);
void	winner_message(t_game *game);
void	death_message(void);
void	you_die(t_game *game);
void	start_game_message(void);

#endif
