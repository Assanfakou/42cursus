#include <stdio.h>
#include "so_long.h"

void draw_map(t_game *game);
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
   
    if (key_code == UP)
        pos_y--;
    if (key_code == DOWN)
        pos_y++;
    if (key_code == RIGHT)
        pos_x++;
    if (key_code == LEFT)
        pos_x--;
        printf("x = %d, y = %d\n", game->pos_play_x, game->pos_play_y);
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
int handle_keypress(int keycode, void *game)
{
    mv_player(keycode, game);
    if (keycode == UP)
        printf("tap UP\n");
    else if (keycode == RIGHT)
        printf("tap RIGHT\n");
    else if (keycode == LEFT)
        printf("tap LEFT\n");
    else if (keycode == DOWN)
        printf("tap DOWN\n");
    else if (keycode == ESC || keycode == 113)
    {
        mlx_destroy_window(((t_game *)game)->mlx, ((t_game *)game)->win);
        printf("tap ESC\n");
        exit(0);
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
        {'1', '0', '1', '1', '0', '0', '1', '0', '1'},
        {'1', '0', '1', '0', '0', '1', '1', '0', '1'},
        {'1', '0', '0', '0', '1', '1', '1', '0', '1'},
        {'1', '0', '0', '1', '1', '1', '1', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1'}
    };

    y = 0;
    while (y < 9)
    {
        x = 0;
        while (x < 9)
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
    while (y < 9)
    {
        x = 0;
        while (x < 9)
        {
            if (game->ma_p[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->ma_p[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->player_img, x * TILE_SIZE, y * TILE_SIZE);
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

    // initializing the stuct's map
    fill_map_struct(&game);
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, WIDTH * TILE_SIZE, HEIGHT * TILE_SIZE, "so_long");

    game.wall_img = mlx_xpm_file_to_image(game.mlx, "123.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
    game.player_img = mlx_xpm_file_to_image(game.mlx, "pngs/p1.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});

    // y = 0;
    // while (y < 9)
    // {
    //     x = 0;
    //     while (x < 9)
    //     {
    //         if (game.ma_p[y][x] == '1')
    //             mlx_put_image_to_window(game.mlx, game.win, game.wall_img, x * TILE_SIZE, y * TILE_SIZE);
    //         else if (game.ma_p[y][x] == 'P')
    //             mlx_put_image_to_window(game.mlx, game.win, game.player_img, x * TILE_SIZE, y * TILE_SIZE);
    //         x++;
    //     }
    //     y++;
    // }
    // printf("im here");
    draw_map(&game);
    printf("x = %d, y = %d\n", game.pos_play_x, game.pos_play_y);
    mlx_key_hook(game.win, handle_keypress, &game);
    mlx_loop(game.mlx);
    return (0);
}
