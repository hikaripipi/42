/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:38:26 by hikarimac         #+#    #+#             */
/*   Updated: 2025/08/28 17:42:55 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	handle_collectible(t_game *game, int new_x, int new_y)
{
	ft_printf("Collectible found!\n");
	game->map.grid[new_y][new_x] = EMPTY;
	game->map.collectibles--;
}

static void	handle_exit(t_game *game)
{
	if (!has_collectibles(game))
	{
		ft_printf("You won! Total moves: %d\n", game->moves + 1);
		close_game(game);
	}
}

static void	update_player_position(t_game *game, int new_x, int new_y,
		char target)
{
	char	old_tile;

	old_tile = game->map.grid[game->map.player_y][game->map.player_x];
	if (old_tile == PLAYER)
		game->map.grid[game->map.player_y][game->map.player_x] = EMPTY;
	game->map.player_x = new_x;
	game->map.player_y = new_y;
	if (target != EXIT)
		game->map.grid[new_y][new_x] = PLAYER;
}

static int	handle_move_to_position(t_game *game, int new_x, int new_y)
{
	char	target;

	target = game->map.grid[new_y][new_x];
	if (target == WALL)
		return (0);
	if (target == COLLECTIBLE)
		handle_collectible(game, new_x, new_y);
	if (target == EXIT)
		handle_exit(game);
	update_player_position(game, new_x, new_y, target);
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	render_game(game);
	return (1);
}

int	move_player_direction(t_game *game, int new_x, int new_y)
{
	if (new_x >= 0 && new_x < game->map.width && new_y >= 0
		&& new_y < game->map.height)
		handle_move_to_position(game, new_x, new_y);
	return (0);
}
