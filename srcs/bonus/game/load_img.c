#include "../../../includes/so_long_bonus.h"
void	load_exit_animation(t_game *game, char **tab)
{
	int i;
	int	widht;
	int	height;

	widht = 57;
	height = 59;
	i = 0;
	game->exit_animated = malloc(sizeof(t_data) * game->exit.frame);
	if (!game->exit_animated)
		return ;
	while (i < game->exit.frame)
	{
		game->exit_animated[i].img = mlx_xpm_file_to_image(game->mlx, tab[i], &widht, &height);
		i++;
	}
}

void	load_blinky_animation(t_game *game, char **blinky)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	width = 57;
	height = 59;
	game->blinky_animated = malloc(sizeof(t_data) * game->blinky.frame);
	if (!game->blinky_animated)
		return ;
	while (i < game->blinky.frame)
	{
		game->blinky_animated[i].img = mlx_xpm_file_to_image(game->mlx, blinky[i], &width, &height);
		i++;
	}
}