#include "../../so_long.h"

double	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec + time.tv_usec / 1000000.0);
}

int	get_each_second(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec + time.tv_usec / 1000000);
}

void	find_ennemy_position(t_game *game)
{
	int i;
	int	j;

	i = 0;
	while (game->map->grid[i])
	{
		j = 0;
		while (game->map->grid[i][j])
		{
			if (game->map->grid[i][j] == 'V')
			{
				game->ennemy_pos.x = j;
				game->ennemy_pos.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}
