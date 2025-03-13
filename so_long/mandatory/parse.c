/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 01:27:04 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/13 05:04:04 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char *file_path)
{
	int		line_num;
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Error : No such file or directory", 2);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	line_num = 0;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		line_num++;
	}
	if (line_num == 0)
	{
		ft_putendl_fd("Error : The file is empty", 2);
		exit(EXIT_FAILURE);
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
		exit(EXIT_FAILURE);
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
	t_check_game	check;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Error : No such file or directory", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_strlen(filepath) < 4 || ft_strncmp(filepath + (ft_strlen(filepath)
				- 4), ".ber", 4) != 0)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("the file name incorrect", 2);
		exit(EXIT_FAILURE);
	}
	ft_bzero(&check, sizeof(t_check_game));
	game->hight = count_line(filepath);
	game->map = alloc_map(fd, game->hight);
	game->with = ft_strlen(game->map[0]);
	if (check_rectangular(game) == 0)
		handle_error_exit(game, "The map must be rectangular");
	check_erours(game, &check);
	check_valid_path(game);
	close(fd);
}

void	count_charachters(t_game *game, t_check_game *check)
{
	int	y;
	int	x;

	x = 0;
	while (x < game->hight)
	{
		y = 0;
		while (y < game->with)
		{
			if (game->map[x][y] == 'C')
				check->coin_check++;
			else if (game->map[x][y] == 'P')
				check->player_check++;
			else if (game->map[x][y] == '1')
				check->wall_check++;
			else if (game->map[x][y] == 'E')
				check->exit_check++;
			else if (game->map[x][y] != '0')
				handle_error_exit(game, "There is an anonyme charachter");
			y++;
		}
		x++;
	}
}
