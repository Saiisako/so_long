NAME = so_long
CC = cc
FLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address
RM = rm -rf
LIBFT = library/libft/libft.a
MLX_FLAGS = -L./minilibx-linux -lmlx -lbsd -lXext -lX11 -lm
LIBFT_FLAGS = -L./library/libft -lft
DEPENDANCES = so_long_dependances

SRCS =	so_long.c error.c free.c print.c\
		$(DEPENDANCES)/parsing/malloc_fill_map.c\
		$(DEPENDANCES)/parsing/parsing_map.c\
		$(DEPENDANCES)/parsing/parsing_path.c\
		$(DEPENDANCES)/parsing/parsing_wall.c\
		$(DEPENDANCES)/game/launch_game.c\
		$(DEPENDANCES)/game/player_movement.c\
		$(DEPENDANCES)/game/verif_next_element.c\
		$(DEPENDANCES)/game/player_movement_verif.c\
		$(DEPENDANCES)/game/img_utils.c\
		$(DEPENDANCES)/game/camera_utils.c\
		$(DEPENDANCES)/game/init_count.c\
		$(DEPENDANCES)/game/anim.c\
		$(DEPENDANCES)/game/create_tab.c\
		$(DEPENDANCES)/game/enemy_movement.c\
		$(DEPENDANCES)/game/enemy_patrol.c\
		$(DEPENDANCES)/game/load_img.c\
		$(DEPENDANCES)/game/get_value.c\


OBJS = $(SRCS:.c=.o)

TARGET = $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS)

$(LIBFT):
	make -C library/libft

minilibx :
	@git clone "https://github.com/42Paris/minilibx-linux.git"
	cd minilibx-linux && make

.c.o:
	$(CC) $(FLAGS) -c -o $@ $<

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@$(RM) library/libft/libft.a
	@find library -name "*.o" -delete
	@echo "files erased successfully"

fclean: clean
	@$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re
