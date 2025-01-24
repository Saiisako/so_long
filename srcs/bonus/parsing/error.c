/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:04:41 by skock             #+#    #+#             */
/*   Updated: 2025/01/25 00:13:43 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	error_parsing(t_game *game, const char *str)
{
	if (game)
	{
		freemap(game->map->grid);
		if (game->map->grid_cpy)
			freemap(game->map->grid_cpy);
		free(game->map);
		free(game);
	}
	ft_printf("Error : %s\n", str);
	exit(EXIT_FAILURE);
}

void	error_fd(int fd)
{
	if (fd == -1)
	{
		perror("Error while trying to open the file.");
		exit(1);
	}
	return ;
}
