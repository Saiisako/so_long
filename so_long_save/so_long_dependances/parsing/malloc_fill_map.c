/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_fill_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:15:12 by skock             #+#    #+#             */
/*   Updated: 2025/01/23 13:46:51 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_map	*fill_map(t_game *game, char **av, int fd)
{
	char	*line;
	int		line_char;

	fd = open(av[1], O_RDONLY);
	error_fd(fd);
	line_char = 0;
	line = get_next_line(fd);
	while (line)
	{
		game->map->grid[line_char] = ft_calloc(sizeof(char),
				(ft_strnlen(line, '\n')) + 1);
		if (!game->map->grid[line_char])
			return (NULL);
		ft_strlcpy(game->map->grid[line_char], line, ft_strnlen(line, '\n'));
		line_char++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (game->map);
}

t_map	*malloc_map(int fd, char **av, t_game *game)
{
	char	*line;

	game->map->lenght = 0;
	game->map->height = 0;
	line = get_next_line(fd);
	game->map->lenght = ft_strnlen(line, '\n') - 1;
	while (line)
	{
		game->map->height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	game->map->grid = ft_calloc(sizeof(char *), (game->map->height + 1));
	if (!game->map->grid)
		return (NULL);
	close(fd);
	fill_map(game, av, fd);
	return (game->map);
}

t_game	*tab_dup(t_game *game)
{
	char	**tab;
	int		i;

	tab = ft_calloc(sizeof(char *), (size_t)(game->map->height + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < game->map->height)
	{
		tab[i] = ft_strdup(game->map->grid[i]);
		i++;
	}
	game->map->grid_cpy = tab;
	return (game);
}
