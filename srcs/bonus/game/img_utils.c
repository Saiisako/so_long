/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:49:46 by skock             #+#    #+#             */
/*   Updated: 2025/01/25 00:13:43 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"
void	*get_image(t_game *game, char element)
{
	if (element == '1')
		return (game->wall_img);
	if (element == '0')
		return (game->floor_img);
	if (element == 'P')
		return (game->player_img);
	if (element == 'E')
		return (exit_anim(game));
	if (element == 'C')
		return (game->coin_img);
	if (element == 'V')
		return (blinky_anim(game));
	return (NULL);
}

void	put_image(t_game *game, char element, int y, int x)
{
	void	*img;
	int		width;
	int		height;

	height = 59;
	width = 57;
	img = get_image(game, element);
	if (img)
		mlx_put_image_to_window(game->mlx, game->win,
			img, x * width, y * height);
}

// void	load_pac_img(t_game *game, int width, int height, char *str)
// {
// 	game->player_img = mlx_xpm_file_to_image(game->mlx, str, &width, &height);
// 	if (game->character->player.rotation == 'U')
// 	{
// 		str = "ressources/pacman/pacman_up.xpm";
// 		game->player_img = mlx_xpm_file_to_image(game->mlx, str,
// 				&width, &height);
// 	}
// 	else if (game->character->player.rotation == 'L')
// 	{
// 		str = "ressources/pacman/pacman_left.xpm";
// 		game->player_img = mlx_xpm_file_to_image(game->mlx, str,
// 				&width, &height);
// 	}
// 	else if (game->character->player.rotation == 'D')
// 	{
// 		str = "ressources/pacman/pacman_down.xpm";
// 		game->player_img = mlx_xpm_file_to_image(game->mlx, str,
// 				&width, &height);
// 	}
// 	else if (game->character->player.rotation == 'R')
// 	{
// 		str = "ressources/pacman/pacman_right.xpm";
// 		game->player_img = mlx_xpm_file_to_image(game->mlx, str,
// 				&width, &height);
// 	}
// }