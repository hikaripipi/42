/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:45:00 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/28 17:40:14 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	player_move_up(t_game *game)
{
	int	new_y;

	new_y = game->map.player_y - 1;
	return (move_player_direction(game, game->map.player_x, new_y));
}

int	player_move_down(t_game *game)
{
	int	new_y;

	new_y = game->map.player_y + 1;
	return (move_player_direction(game, game->map.player_x, new_y));
}

int	player_move_left(t_game *game)
{
	int	new_x;

	new_x = game->map.player_x - 1;
	return (move_player_direction(game, new_x, game->map.player_y));
}

int	player_move_right(t_game *game)
{
	int	new_x;

	new_x = game->map.player_x + 1;
	return (move_player_direction(game, new_x, game->map.player_y));
}
