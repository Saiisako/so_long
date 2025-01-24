/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:29:39 by skock             #+#    #+#             */
/*   Updated: 2025/01/25 00:13:43 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	print_end_str(t_game *game)
{
	if (game->end->end_killer == true)
		ft_printf("%s\n", END_KILLER);
	else if (game->end->end_game_over == true)
		ft_printf("%s\n", END_GAME_OVER);
	else if (game->end->end_win == true)
		ft_printf("%s\n", END_WIN);
}

void	print_map(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		i++;
		ft_printf("\n");
	}
}
