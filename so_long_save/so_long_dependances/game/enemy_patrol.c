#include "../../so_long.h"

void	algo_random_patrol(t_game *game)
{
	int	r;

	r = rand() % 4;
	find_ennemy_position(game);
	if (game->map->ennemy > 0)
	{
		if (r == 0)
			ennemy_move_up(game);
		else if (r == 1)
			ennemy_move_left(game);
		else if (r == 2)
			ennemy_move_down(game);
		else if (r == 3)
			ennemy_move_right(game);
	}
}

void	move_ennemy_patrol(t_game *game)
{
	int	second;

	second = get_each_second();
	if (second != game->last_second)
		algo_random_patrol(game);
	game->last_second = second;
}
