/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:50:35 by skock             #+#    #+#             */
/*   Updated: 2025/01/24 21:59:44 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	initialize_value(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->coin = 0;
	game->map->ennemy = 0;
	while (game->map->grid[i])
	{
		j = 0;
		while (game->map->grid[i][j])
		{
			if (game->map->grid[i][j] == 'C')
				game->coin++;
			if (game->map->grid[i][j] == 'V')
				game->map->ennemy++;
			j++;
		}
		i++;
	}
	game->character->blinky.attack = 1;
	game->character->player.attack = 0;
	game->move_count = 0;
	find_ennemy_position(game);
}

void	initialize_image(t_game *game)
{
	int	img_width;
	int	img_height;

	img_height = 59;
	img_width = 57;
	game->wall_img = mlx_xpm_file_to_image(game->mlx, PACMAN_WALL,
			&img_width, &img_height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, PACMAN_FLOOR,
			&img_width, &img_height);
	game->player_img = mlx_xpm_file_to_image(game->mlx, PACMAN,
			&img_width, &img_height);
	create_tab_exit(game);
	game->coin_img = mlx_xpm_file_to_image(game->mlx, PACMAN_COIN,
			&img_width, &img_height);
	create_tab_blinky(game);
	display_map(game);
}

void	initialize_end(t_game *game)
{
	game->end->end_game_over = false;
	game->end->end_killer = false;
	game->end->end_win = false;
}

void	count_ennemy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->map->ennemy = 0;
	while (game->map->grid[i])
	{
		j = 0;
		while (game->map->grid[i][j])
		{
			if (game->map->grid[i][j] == 'V')
				game->map->ennemy++;
			j++;
		}
		i++;
	}
}
