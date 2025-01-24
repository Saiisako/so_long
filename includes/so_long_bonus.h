/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:49:55 by skock             #+#    #+#             */
/*   Updated: 2025/01/25 00:14:45 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../library/libft/libft.h"
# include <stdbool.h>
# include <sys/time.h>
# include <time.h>

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "define.h"

typedef struct s_end
{
	bool	end_game_over;
	bool	end_win;
	bool	end_killer;
}			t_end;

typedef struct s_camera
{
	int	x;
	int	y;
	int	width;
	int	height;
}		t_camera;

typedef struct s_stat
{
	int		life;
	int		attack;
	char	rotation;
}			t_stat;

typedef struct s_character
{
	t_stat	blinky;
	t_stat	player;
}			t_character;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct s_pos
{
	int	x;
	int	y;
}			t_pos;

typedef struct s_map
{
	char	**grid;
	char	**grid_cpy;
	int		height;
	int		lenght;
	int		item;
	int		ennemy;
}			t_map;

typedef struct s_anim
{
	bool	start;
	int		frame;
	double	time_start;
}			t_anim;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			coin;
	int			move_count;
	int			i;
	int			j;
	int			last_second;
	t_anim		exit;
	t_anim		blinky;
	t_pos		player_pos;
	t_pos		ennemy_pos;
	t_map		*map;
	t_data		*floor_img;
	t_data		*player_img;
	t_data		*ennemy_img;
	t_data		*wall_img;
	t_data		*coin_img;
	t_data		*blinky_animated;
	t_data		*exit_animated;
	t_data		*img;
	t_character	*character;
	t_camera	*camera;
	t_end		*end;
}			t_game;

//	MAP_MALLOC
t_map	*malloc_map(int fd, char **av, t_game *game);
t_map	*fill_map(t_game *game, char **av, int fd);
t_game	*tab_dup(t_game *game);
//	MAP_PARSING
void	verif_last_symbol(char *line, t_game *game);
void	verif_cpy_elements(t_game *game);
void	verif_map_elements(t_game *game);
void	valid_map_symbols(t_game *game);
void	valid_map_wall(t_game *game);
void	is_map_valid(t_game *game);
void	verif_side(t_game *game);
void	valid_path(t_game *game);
int		is_map_symbols(char *line);
//	GAME
int		keycode(int keycode, t_game *game);
void	launch_game(t_game *game);
// IMG
void	load_pac_img(t_game *game, int width, int height, char *str);
void	display_img(t_game *game, char element, int y, int x);
void	put_image(t_game *game, char element, int y, int x);
void	*get_image(t_game *game, char element);
void	create_tab_exit(t_game *game);
void	load_exit_animation(t_game *game, char **tab);
void	*exit_anim(t_game *game);
// CAMERA
void	find_player_position(t_game *game);
void	find_ennemy_position(t_game *game);
void	update_camera(t_game *game);
void	display_map(t_game *game);
// ENNEMY_MOVEMENT
void	ennemy_move_down(t_game *game);
void	ennemy_move_left(t_game *game);
void	ennemy_move_right(t_game *game);
void	ennemy_move_up(t_game *game);
// PLAYER_MOVEMENT
void	move_character(t_game *game, int keycode);
void	move_right(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_up(t_game *game);
// VERIF_MOVEMENT_PLAYER
void	move_right_verif(t_game *game);
void	move_down_verif(t_game *game);
void	move_left_verif(t_game *game);
void	move_up_verif(t_game *game);
// VERIF_NEXT
int		is_next_exit(t_game *game, char element);
void	is_next_coin(t_game *game, char element);
//	ERROR
void	error_parsing(t_game *game, const char *str);
void	error_fd(int fd);
//	FREE
int		close_game(t_game *game);
void	free_map_img(t_game *game);
void	freemap(char **map);
//	PRINT
void	print_map(char **map);
void	print_end_str(t_game *game);
// INITIALIZE
void	initialize_value(t_game *game);
void	initialize_image(t_game *game);
void	initialize_end(t_game *game);
// COUNTING
void	count_ennemy(t_game *game);
// EVIL_FUNCTION
double	get_current_time(void);
int		get_each_second(void);
void	*blinky_anim(t_game *game);
void	*exit_anim(t_game *game);
void	create_tab_blinky(t_game *game);
void	create_tab_exit(t_game *game);
void	redirect_enemy_movement(t_game *game);
void	ennemy_move_down(t_game *game);
void	ennemy_move_left(t_game *game);
void	ennemy_move_right(t_game *game);
void	ennemy_move_up(t_game *game);
void	algo_random_patrol(t_game *game);
void	move_ennemy_patrol(t_game *game);
void	load_exit_animation(t_game *game, char **tab);
void	load_blinky_animation(t_game *game, char **blinky);
void	find_ennemy_position(t_game *game);
int		loop(t_game *game);


#endif
