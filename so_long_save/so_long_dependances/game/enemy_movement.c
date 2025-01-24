
#include "../../so_long.h"

void	redirect_enemy_movement(t_game *game)
{
	int	x;
	int	y;

	x = game->ennemy_pos.x;
	y = game->ennemy_pos.y;
	if (game->map->grid[y][x + 1] == '0'
		|| (game->character->player.attack == 0
		&& game->map->grid[y][x + 1] == 'P'))
		ennemy_move_right(game);
	else if (game->map->grid[y][x - 1] == '0'
		|| (game->character->player.attack == 0
		&& game->map->grid[y][x - 1] == 'P'))
		ennemy_move_left(game);
	else if (game->map->grid[y - 1][x] == '0'
		|| (game->character->player.attack == 0
		&& game->map->grid[y - 1][x] == 'P'))
		ennemy_move_up(game);
	else if (game->map->grid[y + 1][x] == '0'
		|| (game->character->player.attack == 0
		&& game->map->grid[y + 1][x] == 'P'))
		ennemy_move_down(game);
}

void	ennemy_move_down(t_game *game)
{
	int x = game->ennemy_pos.x;
	int y = game->ennemy_pos.y;
	char next_tile;

	next_tile = game->map->grid[y + 1][x];
	if (y + 1 >= game->map->height)
		redirect_enemy_movement(game);
	if (next_tile == '1')
		redirect_enemy_movement(game);
	if (next_tile == '0')
	{
		game->map->grid[y + 1][x] = 'V';
		game->map->grid[y][x] = '0';
		return ;
	}
	if (next_tile == 'E' || next_tile == 'C')
		redirect_enemy_movement(game);
	if (next_tile == 'P' && game->character->player.attack == 0)
		close_game(game);
}

void	ennemy_move_left(t_game *game)
{
	int x = game->ennemy_pos.x;
	int y = game->ennemy_pos.y;
	char next_tile;

	next_tile = game->map->grid[y][x - 1];
	if (x - 1 < 0)
		redirect_enemy_movement(game);
	if (next_tile == '1')
		redirect_enemy_movement(game);
	if (next_tile == '0')
	{
		game->map->grid[y][x - 1] = 'V';
		game->map->grid[y][x] = '0';
		return ;
	}
	if (next_tile == 'E' || next_tile == 'C')
		redirect_enemy_movement(game);
	if (next_tile == 'P' && game->character->player.attack == 0)
	{
		close_game(game);
	}
}

void	ennemy_move_right(t_game *game)
{
	int x = game->ennemy_pos.x;
	int y = game->ennemy_pos.y;
	char next_tile;

	next_tile = game->map->grid[y][x + 1];
	if (x + 1 >= game->map->lenght)
		redirect_enemy_movement(game);
	if (next_tile == '1')
		redirect_enemy_movement(game);
	if (next_tile == '0')
	{
		game->map->grid[y][x + 1] = 'V';
		game->map->grid[y][x] = '0';
		return ;
	}
	if (next_tile == 'E' || next_tile == 'C')
		redirect_enemy_movement(game);
	if (next_tile == 'P' && game->character->player.attack == 0)
	{
		close_game(game);
	}
}

void	ennemy_move_up(t_game *game)
{
	int x = game->ennemy_pos.x;
	int y = game->ennemy_pos.y;
	char next_tile;

	next_tile = game->map->grid[y - 1][x];
	if (y - 1 < 0)
		redirect_enemy_movement(game);
	if (next_tile == '1')
		redirect_enemy_movement(game);
	if (next_tile == '0')
	{
		game->map->grid[y - 1][x] = 'V';
		game->map->grid[y][x] = '0';
		return ;
	}
	if (next_tile == 'E' || next_tile == 'C')
		redirect_enemy_movement(game);
	if (next_tile == 'P' && game->character->player.attack == 0)
	{
		close_game(game);
	}
}
