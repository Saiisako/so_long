#include "../../so_long.h"

void	create_tab_blinky(t_game *game)
{
	char **blinky;

	blinky = malloc(sizeof(char *) * 3);
	blinky[0] = "ressources/blinky/blinky_down.xpm";
	blinky[1] = "ressources/blinky/blinky_down_2.xpm";
	blinky[2] = NULL;
	game->blinky.frame = 2;
	load_blinky_animation(game, blinky);
	free(blinky);
}

void	create_tab_exit(t_game *game)
{
	char	**exit;
	int		i;
	int		j;

	exit = malloc(sizeof(char *) * 24);
	exit[0] = "ressources/exit/exit_1.xpm";
	exit[1] = "ressources/exit/exit_2.xpm";
	exit[2] = "ressources/exit/exit_3.xpm";
	exit[3] = "ressources/exit/exit_4.xpm";
	exit[4] = "ressources/exit/exit_5.xpm";
	exit[5] = "ressources/exit/exit_6.xpm";
	exit[6] = "ressources/exit/exit_7.xpm";
	exit[7] = "ressources/exit/exit_8.xpm";
	exit[8] = "ressources/exit/exit_9.xpm";
	exit[9] = "ressources/exit/exit_10.xpm";
	exit[10] = "ressources/exit/exit_11.xpm";
	exit[11] = "ressources/exit/exit_12.xpm";
	i = 11;
	j = 11;
	while (j > 0)
		exit[++i] = exit[--j];
	exit[23] = NULL;
	game->exit.frame = 23;
	load_exit_animation(game, exit);
	free(exit);
}
