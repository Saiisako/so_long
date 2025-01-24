/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:39:57 by skock             #+#    #+#             */
/*   Updated: 2025/01/23 21:40:04 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	move_up(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->grid[i])
	{
		j = 0;
		while (game->map->grid[i][j])
		{
			if (game->map->grid[i][j] == 'P')
			{
				if (game->map->grid[i - 1][j] == '1')
					break ;
				game->i = i;
				game->j = j;
				move_up_verif(game);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_left(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->grid[i])
	{
		j = 0;
		while (game->map->grid[i][j])
		{
			if (game->map->grid[i][j] == 'P')
			{
				if (game->map->grid[i][j - 1] == '1')
					break ;
				game->i = i;
				game->j = j;
				move_left_verif(game);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_down(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->grid[i])
	{
		j = 0;
		while (game->map->grid[i][j])
		{
			if (game->map->grid[i][j] == 'P')
			{
				if (game->map->grid[i + 1][j] == '1')
					break ;
				game->i = i;
				game->j = j;
				move_down_verif(game);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_right(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->grid[i])
	{
		j = 0;
		while (game->map->grid[i][j])
		{
			if (game->map->grid[i][j] == 'P')
			{
				if (game->map->grid[i][j + 1] == '1')
					break ;
				game->i = i;
				game->j = j;
				move_right_verif(game);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_character(t_game *game, int keycode)
{
	count_ennemy(game);
	if (keycode == W)
		move_up(game);
	else if (keycode == A)
		move_left(game);
	else if (keycode == D)
		move_right(game);
	else if (keycode == S)
		move_down(game);
}
