/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:35:50 by skock             #+#    #+#             */
/*   Updated: 2025/01/25 00:13:43 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	verif_side(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->grid[i])
	{
		if (game->map->grid[i][0] != '1')
			error_parsing(game, ERROR_WALL);
		i++;
	}
	i = 0;
	while (game->map->grid[i])
	{
		j = 0;
		while (game->map->grid[i][j])
			j++;
		j--;
		if (game->map->grid[i][j] != '1')
			error_parsing(game, ERROR_WALL);
		i++;
	}
}

void	valid_map_wall(t_game *game)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (game->map->grid[0][j])
	{
		if (game->map->grid[0][j] != '1')
			error_parsing(game, ERROR_WALL);
		j++;
	}
	j = 0;
	while (game->map->grid[i + 1])
		i++;
	while (game->map->grid[i][j])
	{
		if (game->map->grid[i][j] != '1')
			error_parsing(game, ERROR_WALL);
		j++;
	}
	verif_side(game);
}

void	verif_last_symbol(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	i--;
	if (line[i] != '1')
		error_parsing(game, ERROR_WALL);
}
