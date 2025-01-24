/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:05:09 by skock             #+#    #+#             */
/*   Updated: 2025/01/25 00:15:41 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	freemap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_map_img(t_game *game)
{
	int	i;

	i = 0;
	mlx_destroy_image(game->mlx, game->player_img);
	mlx_destroy_image(game->mlx, game->coin_img);
	mlx_destroy_image(game->mlx, game->floor_img);
	mlx_destroy_image(game->mlx, game->wall_img);
	while (i < game->exit.frame)
	{
		mlx_destroy_image(game->mlx, game->exit_animated[i].img);
		i++;
	}
	i = 0;
	while (i < game->blinky.frame)
	{
		mlx_destroy_image(game->mlx, game->blinky_animated[i].img);
		i++;
	}
}

int	close_game(t_game *game)
{
	print_end_str(game);
	freemap(game->map->grid);
	freemap(game->map->grid_cpy);
	free(game->character);
	free_map_img(game);
	free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game->blinky_animated);
	free(game->camera);
	free(game->end);
	free(game->exit_animated);
	free(game);
	exit (EXIT_SUCCESS);
	return (0);
}
