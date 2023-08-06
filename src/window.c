/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/05 15:18:54 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/06 11:58:12 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	initialize_window(t_map *map, t_game *game)
{
	map->mlx = mlx_init(map->width_x * PIXELS, map->height_y * PIXELS, \
				"so_long", false);
	if (!map->mlx)
	{
		exit_error("Couldn't initialize game window");
		return (false);
	}
	return (true);
}

t_game	*load_images(mlx_t *mlx)
{
	t_game	*bag;

	bag = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!bag)
		exit_error("Couldn't calloc space for images");
	if (!load_wall_texture(mlx, bag) || \
		!load_floor_texture(mlx, bag) || \
		!load_player_texture(mlx, bag) || \
		!load_collectable_texture(mlx, bag) || \
		!load_exit_texture(mlx, bag))
	{
		free_image_resources(bag);
		exit_error("Couldn't load all textures");
	}
	return (bag);
}

// For images:
// mlx_load_png:	mlx_texture_t* mlx_load_png(const char* path)
// text_to_image:	mlx_image_t* mlx_texture_to_image(mlx_t* mlx, 
//					mlx_texture_t* texture)
// image_to_wind:	int32_t mlx_image_to_window(mlx_t* mlx, 
//					mlx_image_t* img, int32_t x, int32_t y)

// mlx_load_png loads a PNG to a MLX texture struct.
// It takes a string (path to picture) to find the file you want to load. 
// It returns a pointer to an mlx_texture_t struct.

// texture_to_image converts the pixel data into a format that can be rendered.
// this struct contains information about format of the transformed image data, 
// such as its width, height, and other details, along with a pointer to the 
// actual transformed pixel data. To create this struct, we use the 
// mlx_texture_to_image function, which takes a pointer to our currently 
// running window and a pointer to our texture data. 
// This function initializes the image struct so that the graphics library 
// can work with our texture.

// image_to_window renders the game  It allows us to display an image on the 
// screen by taking a pointer to the specific mlx_image_t, a pointer to our 
// current graphics window, and the coordinates where the image should be 
// displayed in the window. However, while we can iterate 
// over our 2D array that stores our ASCII map by just moving 1 index for 
// a new location, the same is not true for our window and image placement.