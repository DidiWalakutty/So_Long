/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyboard_and_messages.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 17:17:40 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/09/12 19:19:17 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	keydata(mlx_key_data_t keys, void *data)
{
	t_game	*game;

	game = (t_game *) data;
	game->img->player->instances[0].enabled = false;
	if (game->death == false)
	{
		if (keys.action == MLX_PRESS)
		{
			if (keys.key == MLX_KEY_ESCAPE)
				mlx_close_window(game->mlx);
			if (keys.key == MLX_KEY_W || keys.key == MLX_KEY_UP)
				move_up(game);
			if (keys.key == MLX_KEY_S || keys.key == MLX_KEY_DOWN)
				move_down(game);
			if (keys.key == MLX_KEY_A || keys.key == MLX_KEY_LEFT)
				move_left(game);
			if (keys.key == MLX_KEY_D || keys.key == MLX_KEY_RIGHT)
				move_right(game);
		}
	}
	else if (game->death == true && keys.action == MLX_PRESS)
	{
		if (keys.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
	}
}

void	start_game_message(void)
{
	ft_printf("\nUh-oh! Looks like you've had a not-so-friendly encounter with");
	ft_printf(" a sneaky tick!\n\nThese little critters can carry Lyme disease ");
	ft_printf("and other nasty co-infections.\nPrepare for a wild ride of ");
	ft_printf("symptoms, like: pain and loss of feelings in your limbs,\n ");
	ft_printf("a never-ending fever feeling, extreme fatigue\n");
	ft_printf("and possible heart problems.\nEven the gentlest ray of light ");
	ft_printf("can feel like a fiery dragon's breath!\n\nNow, let's prevent ");
	ft_printf("this with a trusty dose of antibiotics!\nBut, don't forget: ");
	ft_printf("we need 2 kinds of antibiotics to truly kick it to the curb!\n");
}

void	not_enough_args(void)
{
	ft_printf("We can't play this tragic game with \n");
	ft_printf("this amount of arguments.\n");
}

void	winner_message(t_game *game)
{
	ft_printf("%i moves\n\n", game->steps);
	ft_printf("CONGRATULATIONS!\nYou're going to be Lyme free ");
	ft_printf("with these antibiotics.\nNo brainfog, herxheimer");
	ft_printf(", pain or other symptoms for you!\n");
	ft_printf("\n");
}

void	death_message(void)
{
	ft_printf("That's another tick bite, but this time it has a bullseye!\n");
	ft_printf("You're infected with Lyme disease and its co-infections.\n");
	ft_printf("Get ready for awful symptoms like brainfog, herxheimers");
	ft_printf(" and lots of pain and meds to fight this off.\n");
	ft_printf("RIP. You're only half alive and fully housebound :(\n");
}
