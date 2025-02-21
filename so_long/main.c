/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:25:52 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/22 00:18:53 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

void player_pos(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < 9)
    {
        x = 0;
        while (x < 9)
        {
            if (game->ma_p[y][x] == 'P')
            {
                game->pos_play_x = x;
                game->pos_play_y = y;
            }
            x++;
        }
        y++;
    }
}

int mv_player(int key_code, t_game *game)
{
    int pos_x = game->pos_play_x;
    int pos_y = game->pos_play_y;

    if (key_code == UP || key_code == 'w')
        pos_y--;
    if (key_code == DOWN || key_code == 's')
        pos_y++;
    if (key_code == RIGHT || key_code == 'd')
        pos_x++;
    if (key_code == LEFT || key_code == 'a')
        pos_x--;
        // printf("x = %d, y = %d\n", game->pos_play_x, game->pos_play_y);
        if (game->ma_p[pos_y][pos_x] != '1')
        {
            game->ma_p[game->pos_play_y][game->pos_play_x] = '0';
            game->pos_play_x = pos_x;
            game->pos_play_y = pos_y;
            game->ma_p[game->pos_play_y][game->pos_play_x] = 'P';
            mlx_clear_window(game->mlx, game->win);
            draw_map(game);
        }
    return (0);
}
int handle_keypress(int keycode, t_game *game)
{
       int coin = 0;
    mv_player(keycode, game);
    // if (game->ma_p[game->pos_play_y][game->pos_play_x] == 'C')
    //                     coin++; // doesn't work
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
        printf("coins %d\n", coin);
        if (keycode == 113)
            printf("tap Q\n");
        else
            printf("tap ESC\n");
        mlx_destroy_window(game->mlx, game->win);
        exit(EXIT_SUCCESS);
    }
    return (0);
}
void fill_map_struct(t_game *game)
{
    int x;
    int y;
    char map[HEIGHT][WIDTH] = {
        {'1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', 'E', '1', '1', '1', '1', '1', 'P', '1'},
        {'1', '0', '1', '1', '1', '0', '0', '0', '1'},
        {'1', 'C', '1', '1', '0', 'C', '1', '0', '1'},
        {'1', '0', '1', '0', '0', '1', '1', '0', '1'},
        {'1', '0', '0', '0', '1', '1', '1', '0', '1'},
        {'1', '1', 'C', '1', '1', '1', '1', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1'}
    };

    y = 0;
    while (y < WIDTH)
    {
        x = 0;
        while (x < HEIGHT)
        {
            game->ma_p[y][x] = map[y][x];
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
    while (y < WIDTH)
    {
        x = 0;
        while (x < HEIGHT)
        {
            if (game->ma_p[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->ma_p[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->player_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->ma_p[y][x] == 'C')
            {
                    // mlx_put_image_to_window(game->mlx, game->win, game->coin_img_1, x * TILE_SIZE, y * TILE_SIZE);
                // while ('P' != 'C')
                // {
                    mlx_put_image_to_window(game->mlx, game->win, game->coin_img_2, x * TILE_SIZE, y * TILE_SIZE);
                // }
            }
            else if (game->ma_p[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}
int main(void)
{
    t_game game;
    int y;
    int x;

    //fill map func to initializ the map
    fill_map_struct(&game);

    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, WIDTH * TILE_SIZE, HEIGHT * TILE_SIZE, "so_long");

    game.wall_img = mlx_xpm_file_to_image(game.mlx, "pngs/123.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
    game.player_img = mlx_xpm_file_to_image(game.mlx, "pngs/Run.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
    game.coin_img_1 = mlx_xpm_file_to_image(game.mlx, "coin_pngs/AnyConv.com__coin2.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
    game.coin_img_2 = mlx_xpm_file_to_image(game.mlx, "coin_pngs/AnyConv.com__coin6.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
    game.exit_img = mlx_xpm_file_to_image(game.mlx, "pngs/Door.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});

    // draw_map(&game);
    // printf("x = %d, y = %d\n", game.pos_play_x, game.pos_play_y);
    // mlx_key_hook(game.win, handle_keypress, &game);
    mlx_string_put(game.mlx, game.win, 105, 105, 0x000000FF, "hello    world");
    mlx_loop(game.mlx);
    return (0);
}
