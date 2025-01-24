#include "../../../includes/so_long_bonus.h"
void	*exit_anim(t_game *game)
{
	int		current_frame;
	double	elapsed_time;


	if (game->exit.start == false)
		return (game->exit_animated[0].img);
	elapsed_time = get_current_time() - game->exit.time_start;
	if (elapsed_time < 0)
		elapsed_time = 0;
	current_frame = (int)(elapsed_time / 0.1);
	if (current_frame >= game->exit.frame)
	{
		game->exit.time_start = get_current_time();
		current_frame = (game->exit.frame - 1);
	}
	return (game->exit_animated[current_frame].img);
}

void	*blinky_anim(t_game *game)
{
	int		current_frame;
	double	elapsed_time;

	elapsed_time = get_current_time() - game->blinky.time_start;
	if (elapsed_time < 0)
		elapsed_time = 0;
	current_frame = (int)(elapsed_time / 0.3);
	if (current_frame >= game->blinky.frame)
	{
		game->blinky.time_start = get_current_time();
		current_frame = game->blinky.frame - 1;
	}
	return (game->blinky_animated[current_frame].img);
}
