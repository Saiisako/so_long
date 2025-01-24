/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:08:18 by skock             #+#    #+#             */
/*   Updated: 2025/01/23 13:46:51 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	valid_map_symbols(t_game *game)
{
	int		i;

	i = 0;
	while (game->map->grid[i])
	{
		if (is_map_symbols(game->map->grid[i]) == 0)
			error_parsing(game, ERROR_SYMBOL);
		i++;
	}
}

int	is_map_symbols(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C'
			&& line[i] != 'E' && line[i] != 'P' && line[i] != 'V')
			return (0);
		i++;
	}
	return (1);
}

void	valid_map_rectangle(t_game *game)
{
	int		i;
	int		j;

	if (game->map->height == game->map->lenght)
		error_parsing(game, ERROR_SHAPE2);
	i = 0;
	while (game->map->grid[i])
	{
		j = 0;
		while (game->map->grid[i][j])
		{
			j++;
		}
		if (j != game->map->lenght)
			error_parsing(game, ERROR_SHAPE);
		i++;
	}
	if (i != game->map->height)
		error_parsing(game, ERROR_SHAPE);
}

void	verif_map_elements(t_game *game)
{
	int	player;
	int	exit;
	int	i;
	int	j;

	i = -1;
	player = 0;
	game->map->item = 0;
	exit = 0;
	while (game->map->grid[++i])
	{
		j = -1;
		while (game->map->grid[i][++j])
		{
			if (game->map->grid[i][j] == 'P')
				player++;
			else if (game->map->grid[i][j] == 'E')
				exit++;
			else if (game->map->grid[i][j] == 'C')
				game->map->item++;
		}
	}
	if (player > 1 || player < 1 || exit > 1 || exit < 1 || game->map->item < 1)
		error_parsing(game, ERROR_ELEM);
}

void	is_map_valid(t_game *game)
{
	game->map->grid_cpy = NULL;
	valid_map_rectangle(game);
	verif_map_elements(game);
	valid_map_symbols(game);
	valid_map_wall(game);
	valid_path(game);
}
