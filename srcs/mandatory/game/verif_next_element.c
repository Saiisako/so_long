/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_next_element.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:48:57 by skock             #+#    #+#             */
/*   Updated: 2025/01/25 00:13:43 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	is_next_coin(t_game *game, char element)
{
	if (element == 'C')
	{
		game->coin--;
		return ;
	}
}

int	is_next_exit(t_game *game, char element)
{
	if (element == 'E')
	{
		if (game->coin == 0)
		{
			close_game(game, END_WIN);
			return (1);
		}
	}
	return (0);
}
