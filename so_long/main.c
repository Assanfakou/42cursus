/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:25:52 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/25 23:59:07 by hfakou           ###   ########.fr       */
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
    {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
    {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
    {'W', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', 'W'},
    {'W', '1', '0', '0', '0', '0', '0', 'C', 'C', 'C', '0', '0', '0', '0', '0', 'P', '0', '0', '0', 'E', '1', 'W'},
    {'W', '1', '0', 'X', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', 'W'},
    {'W', '1', 'E', '1', '0', '0', '0', '0', 'E', '0', '0', 'X', '0', '0', '0', '0', '0', '0', '0', '0', '1', 'W'},
    {'W', '1', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', 'W'},
    {'W', '1', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', 'E', '1', '0', '1', 'W'},
    {'W', '1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'E', '0', '0', '1', '0', '1', 'W'},
    {'W', '1', 'E', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', 'W'},
    {'W', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', 'W'},
    {'W', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', 'W'}
    };

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            if (map[y][x] == 'C')
                game->total_coin++;
            game->ma_p[y][x] = map[y][x];
            x++;
        }
        y++;
    }
}
void image_to_window(t_game *game, void *image, int x, int y)
{
    mlx_put_image_to_window(game->mlx, game->win, image, x * SUB_PEX, y * SUB_PEX);
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
                image_to_window(game, game->wall_img, x, y);
            else if (game->ma_p[y][x] == 'E')
            {
                if (game->total_coin == game->counter_coin)
                    render_the_animation_coin(game);
                else
                    render_the_animation_coin(game);
                image_to_window(game, game->current_exit_img, x, y);
            }
            else if (game->ma_p[y][x] == 'P')
                    image_to_window(game, game->current_plyer, x, y);
            else if (game->ma_p[y][x] == 'C')
            {
                render_the_animation_coin(game);
                image_to_window(game, game->current_anim, x, y);
            }
            else if (game->ma_p[y][x] == 'X' || game->ma_p[y][x] == 'W')
            {
                render_fire(game);
                image_to_window(game, game->curent_fire, x, y);
            }
            else if (game->ma_p[y][x] == '0')
                image_to_window(game, game->floor, x, y);
            // else if (game->ma_p[y][x] == 'W')
            //     image_to_window(game, game->header, x, y);
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
// void render_the_door_anima(t_game *game, void *current, void **arr)
// {
//     if (game->current_frame == 0)
//         game->current_exit_img = game->exit_img_green[0];
//     else if (game->current_frame == 1)
//         game->current_exit_img = game->exit_img_green[1];
//      else if (game->current_frame == 3)
//         game->current_exit_img = game->exit_img_green[2];
//     else if (game->current_frame == 4)
//         game->current_exit_img = game->exit_img_green[3];
// }
void render_fire(t_game *game)
{
     if (game->current_frame == 0 )
        game->curent_fire = game->fire[0];
    if (game->current_frame == 1)
        game->curent_fire = game->fire[1];
    if (game->current_frame == 3)
        game->curent_fire = game->fire[2];
    if (game->current_frame == 4)
        game->curent_fire = game->fire[3];
}
void render_the_animation_coin(t_game *game)
{
    if (game->current_frame == 0)
        game->current_anim = game->coin_img[0];
    if (game->current_frame == 1)
        game->current_anim = game->coin_img[1];
    if (game->current_frame == 0 )
        game->current_exit_img = game->exit_img_green[0];
    if (game->current_frame == 1)
        game->current_exit_img = game->exit_img_green[1];
    if (game->current_frame == 3)
        game->current_exit_img = game->exit_img_green[2];
    if (game->current_frame == 4)
        game->current_exit_img = game->exit_img_green[3];
    if (game->current_frame == 0 && game->total_coin != game->counter_coin)
        game->current_exit_img = game->exit_img_red[0];
    if (game->current_frame == 1 && game->total_coin != game->counter_coin)
        game->current_exit_img = game->exit_img_red[1];
    if (game->current_frame == 3 && game->total_coin != game->counter_coin)
        game->current_exit_img = game->exit_img_red[2];
    if (game->current_frame == 4 && game->total_coin != game->counter_coin)
        game->current_exit_img = game->exit_img_red[3];
}
void loop_rendering(t_game *game)
{

    update_animation(game);
    mlx_clear_window(game->mlx, game->win);
    draw_map(game);
    usleep(100800);
    // mlx_free(game);
}
void file_to_image(t_game *game)
{
    game->wall_img = mlx_xpm_file_to_image(game->mlx, "pngs/123.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
// player images
    game->player_img[0] = mlx_xpm_file_to_image(game->mlx, "peter/straight.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->player_img[1] = mlx_xpm_file_to_image(game->mlx, "peter/front.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->player_img[2] = mlx_xpm_file_to_image(game->mlx, "peter/back.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->player_img[3] = mlx_xpm_file_to_image(game->mlx, "peter/left.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->player_img[4] = mlx_xpm_file_to_image(game->mlx, "peter/right.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    // game->player_img[5] = mlx_xpm_file_to_image(game->mlx, "peter/6.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    // game->player_img[6] = mlx_xpm_file_to_image(game->mlx, "peter/7.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    // game->player_img[7] = mlx_xpm_file_to_image(game->mlx, "peter/8.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    // game->player_img[8] = mlx_xpm_file_to_image(game->mlx, "peter/9.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
// coin images 
    game->coin_img[0] = mlx_xpm_file_to_image(game->mlx, "coin_pngs/coin1.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->coin_img[1] = mlx_xpm_file_to_image(game->mlx, "coin_pngs/coin2.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});

    game->current_plyer = game->player_img[0];
// green images
    game->exit_img_green[0] = mlx_xpm_file_to_image(game->mlx, "gate/green_ex/1.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->exit_img_green[1] = mlx_xpm_file_to_image(game->mlx, "gate/green_ex/2.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->exit_img_green[2] = mlx_xpm_file_to_image(game->mlx, "gate/green_ex/3.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->exit_img_green[3] = mlx_xpm_file_to_image(game->mlx, "gate/green_ex/4.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
// red doors
    game->exit_img_red[0] = mlx_xpm_file_to_image(game->mlx, "gate/red_ex/1.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->exit_img_red[1] = mlx_xpm_file_to_image(game->mlx, "gate/red_ex/2.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->exit_img_red[2] = mlx_xpm_file_to_image(game->mlx, "gate/red_ex/3.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->exit_img_red[3] = mlx_xpm_file_to_image(game->mlx, "gate/red_ex/4.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
// floor
    game->floor = mlx_xpm_file_to_image(game->mlx, "pngs/floor.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
// fire   
    game->fire[0] = mlx_xpm_file_to_image(game->mlx, "enimy/1.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->fire[1] = mlx_xpm_file_to_image(game->mlx, "enimy/2.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->fire[2] = mlx_xpm_file_to_image(game->mlx, "enimy/3.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->fire[3] = mlx_xpm_file_to_image(game->mlx, "enimy/4.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->fire[4] = mlx_xpm_file_to_image(game->mlx, "enimy/5.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
// header
    game->header = mlx_xpm_file_to_image(game->mlx, "enimy/5.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
}
void mlx_free(t_game *game)
{
    mlx_destroy_image(game->mlx, game->wall_img);
    mlx_destroy_image(game->mlx, game->player_img[0]);
    mlx_destroy_image(game->mlx, game->player_img[1]);
    mlx_destroy_image(game->mlx, game->player_img[2]);
    mlx_destroy_image(game->mlx, game->player_img[3]);
    mlx_destroy_image(game->mlx, game->player_img[4]);
    mlx_destroy_image(game->mlx, game->coin_img[0]);
    mlx_destroy_image(game->mlx, game->coin_img[1]);
    // mlx_destroy_image(game->mlx, game->current_plyer);
    mlx_destroy_image(game->mlx, game->exit_img_green[0]);
    mlx_destroy_image(game->mlx, game->exit_img_green[1]);
    mlx_destroy_image(game->mlx, game->exit_img_green[2]);
    mlx_destroy_image(game->mlx, game->exit_img_green[3]);
    mlx_destroy_image(game->mlx, game->exit_img_red[0]);
    mlx_destroy_image(game->mlx, game->exit_img_red[1]);
    mlx_destroy_image(game->mlx, game->exit_img_red[2]);
    mlx_destroy_image(game->mlx, game->exit_img_red[3]);
    mlx_destroy_image(game->mlx, game->floor);
    mlx_destroy_image(game->mlx, game->fire[0]);
    mlx_destroy_image(game->mlx, game->fire[1]);
    mlx_destroy_image(game->mlx, game->fire[2]);
    mlx_destroy_image(game->mlx, game->fire[3]);
    mlx_destroy_image(game->mlx, game->fire[4]);
    mlx_destroy_image(game->mlx, game->header);
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
    mlx_loop_hook(game.mlx, (int (*)(void *))loop_rendering, &game);
    mlx_key_hook(game.win, handle_keypress, &game);
    // mlx_string_put(game.mlx, game.win, 105, 105, 0x000000FF, "hello world");
    mlx_loop(game.mlx);
}
