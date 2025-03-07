/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:50:34 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/07 01:12:10 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void fill_map_struct(t_game *game)
{
    int x;
    int y;

    char map[HEIGHT][WIDTH] = {
    { '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    { '1', '0', '0', '0', '0', '0', 'C', 'C', 'C', '0', '0', '0', '0', '0', 'P', '0', '0', '0', 'E', '1'},
    { '1', '0', 'X', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1'},
    { '1', 'E', '1', '0', '0', '0', '0', 'E', '0', '0', 'X', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
    { '1', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1'},
    { '1', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', 'E', '1', '0', '1'},
    { '1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'E', '0', '0', '1', '0', '1'},
    { '1', 'E', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1'},
    { '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
    { '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
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

int handle_keypress(int keycode, t_game *game)
{   
    if (keycode == ESC)
    {
        ft_printf("tap ESC\n");
        mlx_free(game);
        mlx_destroy_window(game->mlx, game->win);
        mlx_destroy_display(game->mlx);
        free(game->mlx);
        exit(EXIT_SUCCESS);
    }
    else
        mv_player(keycode, game);
    return (0);
}
void image_to_window(t_game *game, void *image, int x, int y)
{
    mlx_put_image_to_window(game->mlx, game->win, image, x * SUB_PEX, y * SUB_PEX + 60);
}

void mlx_free(t_game *game)
{
    int i;

    i = 0;
    while (i < 4)
    {
        mlx_destroy_image(game->mlx, game->exit_img_green[i]);
        mlx_destroy_image(game->mlx, game->exit_img_red[i]);
        mlx_destroy_image(game->mlx, game->player_img[i]);
        mlx_destroy_image(game->mlx, game->fire[i]);
        i++;
    }
    mlx_destroy_image(game->mlx, game->player_img[4]);
    mlx_destroy_image(game->mlx, game->fire[4]);
    i = 0;
    while (i < 10)
        mlx_destroy_image(game->mlx, game->counter_num[i++]);
    mlx_destroy_image(game->mlx, game->wall_img);
    mlx_destroy_image(game->mlx, game->counter_bar);
    mlx_destroy_image(game->mlx, game->floor);
    mlx_destroy_image(game->mlx, game->coin_img[0]);
    mlx_destroy_image(game->mlx, game->coin_img[1]);
}
void file_to_image(t_game *game)
{
    game->wall_img = mlx_xpm_file_to_image(game->mlx, "pngs/123.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->player_img[0] = mlx_xpm_file_to_image(game->mlx, "peter/straight.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->player_img[1] = mlx_xpm_file_to_image(game->mlx, "peter/front.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->player_img[2] = mlx_xpm_file_to_image(game->mlx, "peter/back.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->player_img[3] = mlx_xpm_file_to_image(game->mlx, "peter/left.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->player_img[4] = mlx_xpm_file_to_image(game->mlx, "peter/right.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->coin_img[0] = mlx_xpm_file_to_image(game->mlx, "coin_pngs/coin1.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->coin_img[1] = mlx_xpm_file_to_image(game->mlx, "coin_pngs/coin2.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->current_plyer = game->player_img[0];
    game->exit_img_green[0] = mlx_xpm_file_to_image(game->mlx, "gate/green_ex/1.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->exit_img_green[1] = mlx_xpm_file_to_image(game->mlx, "gate/green_ex/2.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->exit_img_green[2] = mlx_xpm_file_to_image(game->mlx, "gate/green_ex/3.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->exit_img_green[3] = mlx_xpm_file_to_image(game->mlx, "gate/green_ex/4.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->exit_img_red[0] = mlx_xpm_file_to_image(game->mlx, "gate/red_ex/1.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->exit_img_red[1] = mlx_xpm_file_to_image(game->mlx, "gate/red_ex/2.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->exit_img_red[2] = mlx_xpm_file_to_image(game->mlx, "gate/red_ex/3.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->exit_img_red[3] = mlx_xpm_file_to_image(game->mlx, "gate/red_ex/4.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->fire[0] = mlx_xpm_file_to_image(game->mlx, "enimy/1.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->fire[1] = mlx_xpm_file_to_image(game->mlx, "enimy/2.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->fire[2] = mlx_xpm_file_to_image(game->mlx, "enimy/3.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->fire[3] = mlx_xpm_file_to_image(game->mlx, "enimy/4.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->fire[4] = mlx_xpm_file_to_image(game->mlx, "enimy/5.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->floor = mlx_xpm_file_to_image(game->mlx, "pngs/floor.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    counter_bar_fto_img(game);
}
void counter_bar_fto_img(t_game *game)
{
    game->counter_bar = mlx_xpm_file_to_image(game->mlx, "counter/str1.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->counter_num[0] = mlx_xpm_file_to_image(game->mlx, "counter/1.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->counter_num[1] = mlx_xpm_file_to_image(game->mlx, "counter/2.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->counter_num[2] = mlx_xpm_file_to_image(game->mlx, "counter/3.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->counter_num[3] = mlx_xpm_file_to_image(game->mlx, "counter/4.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->counter_num[4] = mlx_xpm_file_to_image(game->mlx, "counter/5.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->counter_num[5] = mlx_xpm_file_to_image(game->mlx, "counter/6.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->counter_num[6] = mlx_xpm_file_to_image(game->mlx, "counter/7.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->counter_num[7] = mlx_xpm_file_to_image(game->mlx, "counter/8.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->counter_num[8] = mlx_xpm_file_to_image(game->mlx, "counter/9.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
    game->counter_num[9] = mlx_xpm_file_to_image(game->mlx, "counter/10.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
}
