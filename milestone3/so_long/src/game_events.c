/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:15:00 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/28 18:37:21 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	has_collectibles(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == COLLECTIBLE)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	ft_printf("Key pressed: %d\n", keycode);
	if (keycode == 53)
		close_game(game);
	if (keycode == 13)
		player_move_up(game);
	else if (keycode == 1)
		player_move_down(game);
	else if (keycode == 0)
		player_move_left(game);
	else if (keycode == 2)
		player_move_right(game);
	return (0);
}

int	close_game(t_game *game)
{
	ft_printf("Closing game...\n");
	cleanup_game(game);
	exit(0);
}
