/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:25:52 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/05 21:42:02 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int handle_keypress(int keycode, t_game *game)
{   
    mv_player(keycode, game);
    if (keycode == UP || keycode == 'w')
        printf("tap UP\n");
    else if (keycode == RIGHT || keycode == 'd')
        printf("tap RIGHT\n");
    else if (keycode == LEFT || keycode == 'a')
        printf("tap LEFT\n");
    else if (keycode == DOWN || keycode == 's')
        printf("tap DOWN\n");
    else if (keycode == ESC || keycode == 113)
    {
        if (keycode == 113)
            printf("tap Q\n");
        else
            printf("tap ESC\n");
        mlx_free(game);
        mlx_destroy_window(game->mlx, game->win);
        mlx_destroy_display(game->mlx);
        exit(EXIT_SUCCESS);
    }
    return (0);
}
void fill_map_struct(t_game *game)
{
    int x;
    int y;

    char map[HEIGHT][WIDTH] = {
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    {'1', '0', '0', '0', '0', '0', 'C', 'C', 'C', '0', '0', '0', '0', '0', 'P', '0', '0', '0', 'E', '1'},
    {'1', '0', 'X', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1'},
    {'1', 'E', '1', '0', '0', '0', '0', 'E', '0', '0', 'X', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
    {'1', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1'},
    {'1', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', 'E', '1', '0', '1'},
    {'1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'E', '0', '0', '1', '0', '1'},
    {'1', 'E', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1'},
    {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
    };

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            if (map[y][x] == 'C')
                game->total_coin++;
            game->map[y][x] = map[y][x];
            x++;
        }
        y++;
    }
}

void draw_map(t_game *game)
{
    int y;
    int x;

    player_pos(game);
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            if (game->map[y][x] == '1')
                image_to_window(game, game->wall_img, x, y);
            else if (game->map[y][x] == 'E')
                image_to_window(game, game->exit_img_green, x, y);
            else if (game->map[y][x] == 'P')
                    image_to_window(game, game->current_plyer, x, y);
            else if (game->map[y][x] == 'C')
                image_to_window(game, game->coin_img, x, y);
            else if (game->map[y][x] == '0')
                image_to_window(game, game->floor, x, y);
            x++;
        }
        y++;
    }
}

int main(void)
{
    t_game game;

    game.total_coin = 0;
    game.counter_coin = 0;

    fill_map_struct(&game);
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, WIDTH * SUB_PEX, HEIGHT * SUB_PEX, "so_long");
    file_to_image(&game);
    game.current_frame = 0;
    game.frame_delay = 4;
    draw_map(&game);
    printf("total ;%d", game.total_coin);
    // printf("coin ;%d", game.counter_coin);
    // printf("x = %d, y = %d\n", game.pos_play_x, game.pos_play_y);    
    // mlx_loop_hook(game.mlx, (int (*)(void *))loop_rendering, &game);
    mlx_key_hook(game.win, handle_keypress, &game);
    // mlx_string_put(game.mlx, game.win, 105, 105, 0x000000FF, "hello world");
    mlx_loop(game.mlx);
}
