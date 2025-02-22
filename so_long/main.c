/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:25:52 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/23 00:18:04 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"


int handle_keypress(int keycode, t_game *game)
{
    int coin = 0;
    
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
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    {'1', '0', 'C', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'P', '1'},
    {'1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    {'1', 'C', '1', '0', '0', '0', '0', '0', '0', '0', '0', 'C', '0', '0', '0', '0', '0', '0', '0', '1'},
    {'1', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1'},
    {'1', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', 'E', '1', '0', '1'},
    {'1', '0', '1', '0', '0', '0', '0', '0', 'C', '0', '0', '0', '0', '0', 'C', '0', '0', '1', '0', '1'},
    {'1', 'C', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1'},
    {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
    };

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
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
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            if (game->ma_p[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->ma_p[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->exit_img_close, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->ma_p[y][x] == 'P')
                    mlx_put_image_to_window(game->mlx, game->win, game->player_img_1, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->ma_p[y][x] == 'C')
            {
                render_the_animation(game);
                mlx_put_image_to_window(game->mlx, game->win, game->current_anim, x * TILE_SIZE, y * TILE_SIZE);
            }
            // else if (game->ma_p[y][x] == '0')
                // mlx_put_image_to_window(game->mlx, game->win, game->floor, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}   

void update_animation(t_game *game)
{
    game->current_frame++;
    if (game->current_frame >= game->frame_delay)
        game->current_frame = 0;
}
void render_the_animation(t_game *game)
{
    if (game->current_frame == 0)
        game->current_anim = game->coin_img_1;
    else if (game->current_frame == 1)
        game->current_anim = game->coin_img_2;
}
int loop_rendering(t_game *game)
{
    update_animation(game);
    mlx_clear_window(game->mlx, game->win);
    draw_map(game);
    usleep(100000);
    return (0);
}
void file_to_image(t_game *game)
{
    game->wall_img = mlx_xpm_file_to_image(game->mlx, "pngs/123.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
    game->player_img_1 = mlx_xpm_file_to_image(game->mlx, "pngs/peter.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
    game->player_img_2 = mlx_xpm_file_to_image(game->mlx, "pngs/Run.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
    game->coin_img_1 = mlx_xpm_file_to_image(game->mlx, "coin_pngs/coin2.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
    game->coin_img_2 = mlx_xpm_file_to_image(game->mlx, "coin_pngs/coin1.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
    game->exit_img_close = mlx_xpm_file_to_image(game->mlx, "pngs/door.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
    game->floor = mlx_xpm_file_to_image(game->mlx, "pngs/floor.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
}
int main(void)
{
    t_game game;

    fill_map_struct(&game);
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, WIDTH * TILE_SIZE, HEIGHT * TILE_SIZE, "so_long");
    file_to_image(&game);
    game.current_frame = 0;
    game.frame_delay = 4;
    draw_map(&game);
    // printf("x = %d, y = %d\n", game.pos_play_x, game.pos_play_y);    
    mlx_loop_hook(game.mlx, (int (*)(void *))loop_rendering, &game);
    mlx_key_hook(game.win, handle_keypress, &game);
    // mlx_string_put(game.mlx, game.win, 105, 105, 0x000000FF, "hello world");
    mlx_loop(game.mlx);
}
