NAME = so_long
NAME_BONUS = so_long_bonus
CC = cc
FLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address
RM = rm -rf
LIBFT = library/libft/libft.a
MLX_FLAGS = -L./minilibx-linux -lmlx -lbsd -lXext -lX11 -lm
LIBFT_FLAGS = -L./library/libft -lft

SRCS		=	srcs/mandatory/game/free.c\
				srcs/mandatory/game/launch_game.c\
				srcs/mandatory/game/player_movement.c\
				srcs/mandatory/game/so_long.c\
				srcs/mandatory/game/verif_next_element.c\
				srcs/mandatory/parsing/error.c\
				srcs/mandatory/parsing/malloc_fill_map.c\
				srcs/mandatory/parsing/parsing_map.c\
				srcs/mandatory/parsing/parsing_path.c\
				srcs/mandatory/parsing/parsing_wall.c\

SRCS_BONUS	=	srcs/bonus/parsing/error.c\
				srcs/bonus/parsing/malloc_fill_map.c\
				srcs/bonus/parsing/parsing_map.c\
				srcs/bonus/parsing/parsing_path.c\
				srcs/bonus/parsing/parsing_wall.c\
				srcs/bonus/game/so_long.c\
				srcs/bonus/game/free.c\
				srcs/bonus/game/print.c\
				srcs/bonus/game/launch_game.c\
				srcs/bonus/game/player_movement.c\
				srcs/bonus/game/verif_next_element.c\
				srcs/bonus/game/player_movement_verif.c\
				srcs/bonus/game/img_utils.c\
				srcs/bonus/game/camera_utils.c\
				srcs/bonus/game/init_count.c\
				srcs/bonus/game/anim.c\
				srcs/bonus/game/create_tab.c\
				srcs/bonus/game/enemy_movement.c\
				srcs/bonus/game/enemy_patrol.c\
				srcs/bonus/game/load_img.c\
				srcs/bonus/game/get_value.c\

OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJS = $(SRCS:.c=.o)

TARGET = $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS)

$(NAME_BONUS): $(LIBFT) $(OBJS_BONUS)
	@$(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(MLX_FLAGS) $(LIBFT_FLAGS)

$(LIBFT):
	make -C library/libft

bonus : $(NAME_BONUS)

minilibx :
	@git clone "https://github.com/42Paris/minilibx-linux.git"
	cd minilibx-linux && make

.c.o:
	$(CC) $(FLAGS) -c -o $@ $<

all: $(NAME)

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@make -s -C library/libft clean
	@echo "files erased successfully"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@make -s -C library/libft fclean

re: fclean all

.PHONY: all clean fclean re bonus minilibx
