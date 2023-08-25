/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyboard.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 17:17:40 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/25 19:35:30 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// while or if death = false
void	keydata(mlx_key_data_t keys, void *data)
{
	t_game	*game;

	game = (t_game *) data;
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

void	winner_message(t_game *game)
{
	ft_printf("%i moves\n\n", game->steps);
	ft_printf("CONGRATULATIONS!\nYou're going to be Lyme free ");
	ft_printf("with these antibiotics.\nNo brainfog, herxheimer");
	ft_printf(", pain or loss of feeling in your limbs for you!\n");
}

void	death_message(void)
{
	ft_printf("That's another tick bite, but there's a bullseye!\n");
	ft_printf("You're infected with Lyme disease and its co-infections.\n");
	ft_printf("Get ready for brainfog, herxheimers, lots of meds");
	ft_printf(", loss of feeling in your limbs, pain and desperation...\n");
	ft_printf("RIP. You're only sort of alive and fully housebound :(\n");
}
