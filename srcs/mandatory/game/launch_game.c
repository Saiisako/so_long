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

#include "../../../includes/so_long.h"

void	initialize_value(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->coin = 0;
	game->map->ennemy = 0;
	while(game->map->grid[i])
	{
		j = 0;
		while(game->map->grid[i][j])
		{
			if (game->map->grid[i][j] == 'C')
				game->coin++;
			j++;
		}
		i++;
	}
	game->move_count = 0;
}

void	free_map_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player_img);
	mlx_destroy_image(game->mlx, game->coin_img);
	mlx_destroy_image(game->mlx, game->floor_img);
	mlx_destroy_image(game->mlx, game->wall_img);
	mlx_destroy_image(game->mlx, game->exit_img);
}

int	close_game(t_game *game, char *str)
{
	freemap(game->map->grid);
	freemap(game->map->grid_cpy);
	free(game->character);
	free_map_img(game);
	free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	printf("%s\n", str);
	exit (EXIT_SUCCESS);
	return (0) ;
}

int	keycode(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_game(game, END_ESC);
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
	return (0);
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
	game->exit_img = mlx_xpm_file_to_image(game->mlx, PACMAN_EXIT,
	&img_width, &img_height);
	game->coin_img = mlx_xpm_file_to_image(game->mlx, PACMAN_COIN,
	&img_width, &img_height);
	display_map(game);
}

void *get_image(t_game *game, char element)
{
	if (element == '1')
		return (game->wall_img);
	if (element == '0')
		return (game->floor_img);
	if (element == 'P')
		return (game->player_img);
	if (element == 'E')
		return (game->exit_img);
	if (element == 'C')
		return (game->coin_img);
	return NULL;
}

void put_image(t_game *game, char element, int y, int x)
{
	void *img = get_image(game, element);
	int	img_width;
	int	img_height;

	img_height = 59;
	img_width = 57;
	if (img)
		mlx_put_image_to_window(game->mlx, game->win, img, x * img_width, y * img_height);
}

void	display_img(t_game *game, char element, int y, int x)
{
	if (element == '1')
			put_image(game, element, y, x);
	else if (element == '0')
			put_image(game, element, y, x);
	else if (element == 'P')
			put_image(game, element, y, x);
	else if (element == 'E')
			put_image(game, element, y, x);
	else if (element == 'C')
			put_image(game, element, y, x);
}

void	display_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->grid[i])
	{
		j = 0;
		while(game->map->grid[i][j])
		{
			put_image(game, game->map->grid[i][j], i, j);
			j++;
		}
		i++;
	}
	printf("move count = %i\n", game->move_count++);
}


void	launch_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map->grid_length*57, game->map->grid_height*59, "so_long");
	// game->player_img = malloc(sizeof(t_data));
	// game->ennemy_img = malloc(sizeof(t_data));
	// game->coin_img = malloc(sizeof(t_data));
	// game->exit_img = malloc(sizeof(t_data));
	// game->floor_img = malloc(sizeof(t_data));
	// game->wall_img = malloc(sizeof(t_data));
	game->character = malloc(sizeof(t_character));
	initialize_value(game);
	initialize_image(game);
	// display_map(game);
	mlx_hook(game->win, KeyPress, KeyPressMask, keycode, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, close_game, game);
	mlx_loop(game->mlx);
}