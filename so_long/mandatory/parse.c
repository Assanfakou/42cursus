/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 01:27:04 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/08 18:07:00 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char *file_path)
{
	int		line_num;
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	line_num = 0;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		line_num++;
	}
	close(fd);
	return (line_num);
}

char	**alloc_map(int fd, int lines)
{
	char	**map;
	char	*line;
	int		i;

	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	fill_map(t_game *game, char *filepath)
{
	int				fd;
	char			**map;
	t_check_game	check;

	if (!ft_strnstr(filepath, ".ber", ft_strlen(filepath)))
    {
        ft_putendl_fd("Error", 2);
        ft_putendl_fd("the file name incorrect", 2);
        exit(EXIT_FAILURE);
    }
    ft_bzero(&check, sizeof(t_check_game));
	fd = open(filepath, O_RDONLY);
	game->hight = count_line(filepath);
	game->map = alloc_map(fd, game->hight);
	game->with = ft_strlen(game->map[0]);
	count_charachters(game, &check);
	check_erours(game, &check);
	close(fd);
}

void	count_charachters(t_game *game, t_check_game *check)
{
	int	y;
	int	x;
	int	hight;
	int	with;

	x = 0;
	while (x < game->hight)
	{
		y = 0;
		while (y < game->with)
		{
			if (game->map[x][y] == 'C')
				check->coin_check++;
			if (game->map[x][y] == 'P')
				check->player_check++;
			if (game->map[x][y] == '1')
				check->enimy_check++;
			if (game->map[x][y] == 'E')
				check->exit_check++;
			y++;
		}
		x++;
	}
}
