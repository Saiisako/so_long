/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:01:25 by skock             #+#    #+#             */
/*   Updated: 2025/01/25 00:21:05 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	print_map(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		i++;
		ft_printf("\n");
	}
}

void	is_extension_valid(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	i--;
	if (file[i] == 'r' && file[i - 1] == 'e'
		&& file[i - 2] == 'b' && file[i - 3] == '.')
		return ;
	error_parsing(NULL, ERROR_EXTENSION);
}

int	main(int ac, char **av)
{
	int		fd;
	t_game	*game;

	if (ac == 2)
	{
		is_extension_valid(av[1]);
		fd = open(av[1], O_RDONLY);
		error_fd(fd);
		game = malloc(sizeof(t_game));
		game->map = malloc(sizeof(t_map));
		game->map = malloc_map(fd, av, game);
		close(fd);
		is_map_valid(game);
		launch_game(game);
	}
	return (0);
}
