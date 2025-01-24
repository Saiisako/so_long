/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:20:35 by skock             #+#    #+#             */
/*   Updated: 2025/01/25 00:13:43 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	verif_surrounded_exit(t_game *game)
{
	int		i;
	int		j;
	char	**map;
	i = 0;

	map = game->map->grid_cpy;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				if (map[i+1][j] == '1' && map[i-1][j] == '1'
					&& map[i][j-1] == '1' && map[i][j+1] == '1')
						error_parsing(game, ERROR_PATH);
			}
			j++;
		}
		i++;
	}
}
void	flood_fill(t_game *game, char fill, int y, int x)
{
	if (x < 0 || y < 0 || x > game->map->grid_length
		|| y > game->map->grid_height || game->map->grid_cpy[y][x] == '1'
		|| game->map->grid_cpy[y][x] == 'E'
		|| game->map->grid_cpy[y][x] == fill)
		return ;
	game->map->grid_cpy[y][x] = fill;
	flood_fill(game, fill, y, (x - 1));
	flood_fill(game, fill, y, (x + 1));
	flood_fill(game, fill, (y - 1), x);
	flood_fill(game, fill, (y + 1), x);
}

void	verif_cpy_elements(t_game *game)
{
	int		i;
	int		j;
	char	pos;

	i = 0;
	while (game->map->grid_cpy[i])
	{
		j = 0;
		while (game->map->grid_cpy[i][j])
		{
			pos = game->map->grid_cpy[i][j];
			if (pos == 'P' || pos == 'C')
				error_parsing(game, ERROR_PATH);
			j++;
		}
		i++;
	}

}

void	valid_path(t_game *game)
{
	int	i;
	int	j;

	tab_dup(game);
	i = 0;
	while (game->map->grid_cpy[i])
	{
		j = 0;
		while (game->map->grid_cpy[i][j])
		{
			if (game->map->grid_cpy[i][j] == 'P')
			{
				game->player_pos.x = j;
				game->player_pos.y = i;
				break ;
			}
			j++;
		}
		i++;
	}
	flood_fill(game, 'F', game->player_pos.y, game->player_pos.x);
	verif_surrounded_exit(game);
	verif_cpy_elements(game);
}
