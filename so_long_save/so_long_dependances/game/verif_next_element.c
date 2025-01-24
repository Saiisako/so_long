/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_next_element.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:48:57 by skock             #+#    #+#             */
/*   Updated: 2025/01/24 01:06:08 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	is_next_coin(t_game *game, char element)
{
	if (element == 'C')
	{
		game->coin--;
		if (game->coin == 0)
			{
				game->exit.start = true;
				game->exit.time_start = get_current_time();
			}
		return ;
	}
}

int	is_next_exit(t_game *game, char element)
{
	if (element == 'E')
	{
		if (game->coin == 0)
		{
			game->end->end_win = true;
			close_game(game);
			return (1);
		}
	}
	return (0);
}
