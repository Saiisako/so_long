/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_verif.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:32:00 by skock             #+#    #+#             */
/*   Updated: 2025/01/25 00:13:43 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"
int	verif_next_close(t_game *game, char element)
{
	if (element == 'V'
		&& game->character->player.attack == 0)
	{
		game->end->end_game_over = true;
		close_game(game);
	}
	if (element == 'E' && game->coin != 0)
		return (1);
	if (element == 'E' && game->map->ennemy == 0
		&& game->map->ennemy == 0)
	{
		game->end->end_killer = true;
		close_game(game);
	}
	if (element == 'E' && game->coin == 0)
	{
		game->end->end_win = true;
		close_game(game);
	}
	return (0);
}

void	move_up_verif(t_game *game)
{
	int		i;
	int		j;
	char	element;

	i = game->i;
	j = game->j;
	element = game->map->grid[i - 1][j];
	if (verif_next_close(game, element) == 1)
		return ;
	is_next_coin(game, element);
	game->map->grid[i - 1][j] = 'P';
	game->map->grid[i][j] = '0';
	update_camera(game);
}

void	move_left_verif(t_game *game)
{
	int		i;
	int		j;
	char	element;

	i = game->i;
	j = game->j;
	element = game->map->grid[i][j - 1];
	if (verif_next_close(game, element) == 1)
		return ;
	is_next_coin(game, game->map->grid[i][j - 1]);
	game->map->grid[i][j - 1] = 'P';
	game->map->grid[i][j] = '0';
	update_camera(game);
}

void	move_down_verif(t_game *game)
{
	int		i;
	int		j;
	char	element;

	i = game->i;
	j = game->j;
	element = game->map->grid[i + 1][j];
	if (verif_next_close(game, element) == 1)
		return ;
	is_next_coin(game, game->map->grid[i + 1][j]);
	game->map->grid[i + 1][j] = 'P';
	game->map->grid[i][j] = '0';
	update_camera(game);
}

void	move_right_verif(t_game *game)
{
	int		i;
	int		j;
	char	element;

	i = game->i;
	j = game->j;
	element = game->map->grid[i][j + 1];
	if (verif_next_close(game, element) == 1)
		return ;
	is_next_coin(game, game->map->grid[i][j + 1]);
	game->map->grid[i][j + 1] = 'P';
	game->map->grid[i][j] = '0';
	update_camera(game);
}
