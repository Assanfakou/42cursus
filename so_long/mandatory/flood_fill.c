/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 02:51:22 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/09 03:31:28 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **secondary_map(t_game *game)
{
    char **second_map;
    int y;
    int x;

    second_map = malloc(sizeof(char *) * (game->hight + 1));
    if (second_map)
        return (NULL);
    y = 0;
    while (y < game->hight)
    {
        x = 0;
        while (x < game->with)
        {
            second_map[y][x] = game->map[y][x];
            x++;
        }
        y++;
    }
    second_map[y] = NULL;
    return (second_map);
}
void finding_player(char **map, t_game *game)
{
    int y;
    int x;

    y = 0;
    while (y < game->hight)
    {
        x = 0;
        while (x < game->with)
        {
            if (map[y][x] == 'P')
                break;
            x++;
        }
        y++;
    }

}
void flood_fill(char **map, int y, int x)
{
    if (map[y][x] == '1' || map[y][x] == 'Z')
        return ;
    flood_fill(map, y + 1, x);
    flood_fill(map, y - 1, x);
    flood_fill(map, y, x + 1);
    flood_fill(map, y, x - 1);
}
