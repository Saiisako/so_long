/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:49:55 by skock             #+#    #+#             */
/*   Updated: 2025/01/25 00:14:31 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../library/libft/libft.h"
# include <stdbool.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "define.h"

typedef struct s_stat
{
	int		life;
	int		attack;
	char	rotation;
}			t_stat;

typedef struct s_character
{
	t_stat	player;
}			t_character;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_pos
{
	int	x;
	int	y;
}			t_pos;

typedef struct s_map
{
	char	**grid;
	char	**grid_cpy;
	int		grid_height;
	int		grid_length;
	int		item;
	int		ennemy;
}			t_map;

typedef struct s_game
{
	t_map		*map;
	t_pos		player_pos;
	void		*mlx;
	void		*win;
	int			coin;
	int			move_count;
	t_data		*floor_img;
	t_data		*player_img;
	t_data		*wall_img;
	t_data		*coin_img;
	t_data		*exit_img;
	t_data		*img;
	t_character	*character;
}			t_game;

//	MAP_MALLOC
t_map	*malloc_map(int fd, char **av, t_game *game);
t_map	*fill_map(t_game *game, char **av, int fd);
t_game	*tab_dup(t_game *game);
//	MAP_PARSING
int		is_map_symbols(char *line);
void	valid_map_symbols(t_game *game);
void	verif_side(t_game *game);
void	valid_map_wall(t_game *game);
void	verif_last_symbol(char *line, t_game *game);
void	verif_map_elements(t_game *game);
void	valid_path(t_game *game);
void	is_map_valid(t_game *game);
void	verif_cpy_elements(t_game *game);
//	GAME
void	launch_game(t_game *game);
int		keycode(int keycode, t_game *game);
void	display_map(t_game *game);
int		close_game(t_game *game, char *str);
// PLAYER_MOVEMENT
void	move_up(t_game *game);
void	move_left(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_character(t_game *game, int keycode);
void	is_next_coin(t_game *game, char element);
int		is_next_exit(t_game *game, char element);
void	free_map_img(t_game *game);
//	ERROR
void	error_parsing(t_game *game, const char *str);
void	error_fd(int fd);
//	FREE
void	freemap(char **map);
//	PRINT
void	print_map(char **map);

#endif
