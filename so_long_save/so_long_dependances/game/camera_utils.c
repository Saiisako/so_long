/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:48:07 by skock             #+#    #+#             */
/*   Updated: 2025/01/23 17:07:18 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	update_camera(t_game *game)
{
	char	str[50];

	printf("Move count = %i\n", game->move_count++);
	find_player_position(game);
	mlx_clear_window(game->mlx, game->win);
	display_map(game);
	sprintf(str, "move count : %d", game->move_count);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, str);
}

void	find_player_position(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map->grid[++i])
	{
		j = -1;
		while (game->map->grid[i][++j])
		{
			if (game->map->grid[i][j] == 'P')
			{
				game->camera->x = j - (game->camera->width / 2);
				game->camera->y = i - (game->camera->height / 2);
				if (game->camera->x < 0)
					game->camera->x = 0;
				if (game->camera->y < 0)
					game->camera->y = 0;
				if (game->camera->x > game->map->lenght - game->camera->width)
					game->camera->x = game->map->lenght - game->camera->width;
				if (game->camera->y > game->map->height - game->camera->height)
					game->camera->y = game->map->height - game->camera->height;
				return ;
			}
		}
	}
}

void	display_map(t_game *game)
{
	int	i;
	int	j;
	int	x_view;
	int	y_view;

	i = game->camera->y;
	while (i < game->camera->y + game->camera->height
		&& i < game->map->height && game->map->grid[i])
	{
		j = game->camera->x;
		while (j < game->camera->x + game->camera->width
			&& j < game->map->lenght && game->map->grid[i][j])
		{
			x_view = (j - game->camera->x) * 57;
			y_view = (i - game->camera->y) * 59;
			if (x_view >= 0 && y_view >= 0
				&& x_view < game->camera->width * 57
				&& y_view < game->camera->height * 59)
				put_image(game, game->map->grid[i][j],
					y_view / 59, x_view / 57);
			j++;
		}
		i++;
	}
}
