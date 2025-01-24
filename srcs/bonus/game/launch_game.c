/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:30:25 by skock             #+#    #+#             */
/*   Updated: 2025/01/25 00:13:43 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"
int	keycode(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_game(game);
	else if (keycode == W)
	{
		game->character->player.rotation = 'U';
		move_character(game, W);
	}
	else if (keycode == A)
	{
		game->character->player.rotation = 'L';
		move_character(game, A);
	}
	else if (keycode == S)
	{
		game->character->player.rotation = 'D';
		move_character(game, S);
	}
	else if (keycode == D)
	{
		game->character->player.rotation = 'R';
		move_character(game, D);
	}
	if (game->coin == 0)
		game->character->player.attack = 1;
	count_ennemy(game);
	return (0);
}

int	loop(t_game *game)
{
	char str[50];

	display_map(game);
	if (game->map->ennemy > 0)
		move_ennemy_patrol(game);
	sprintf(str, "Move Count : %d", game->move_count);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, str);

	return (1);
}

void	launch_game(t_game *game)
{
	game->mlx = mlx_init();
	game->character = malloc(sizeof(t_character));
	game->camera = malloc(sizeof(t_camera));
	game->end = malloc(sizeof(t_end));
	game->last_second = 0;
	initialize_value(game);
	game->camera->width = game->map->lenght - 1;
	game->camera->height = game->map->height - 1;
	find_player_position(game);
	game->win = mlx_new_window(game->mlx,
			game->camera->width * 57,
			game->camera->height * 59,
			"so_long");
	game->exit.start = false;
	game->blinky.time_start = get_current_time();
	initialize_image(game);
	initialize_end(game);
	mlx_hook(game->win, KeyPress, KeyPressMask, keycode, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, close_game, game);
	mlx_loop_hook(game->mlx, loop, game);
	mlx_loop(game->mlx);
}
