/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:28:45 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/07 01:11:10 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void player_pos(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
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
void    rander_steps_counter(t_game *game, int steps)
{
	mlx_put_image_to_window(game->mlx, game->win, game->counter_num[(steps / 1000) % 10], 124, 7);
	mlx_put_image_to_window(game->mlx, game->win, game->counter_num[(steps / 100) % 10], 167, 7);
	mlx_put_image_to_window(game->mlx, game->win, game->counter_num[(steps / 10) % 10], 209, 7);
	mlx_put_image_to_window(game->mlx, game->win, game->counter_num[steps % 10], 252, 8);
}

void psaudo_clear(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            if (game->ma_p[y][x] == '0')
                image_to_window(game, game->floor, x, y);
            x++;
        }
        y++;
    }
}
void mv_player(int key_code, t_game *game)
{
    int pos_x = game->pos_play_x;
    int pos_y = game->pos_play_y;

    if ((key_code == UP || key_code == 'w') && game->ma_p[pos_y - 1][pos_x] != '1')
    {
        game->current_plyer = game->player_img[2];
        pos_y--;
        game->key_count++;
    }
    if ((key_code == DOWN || key_code == 's') && game->ma_p[pos_y + 1][pos_x] != '1')
    {
        game->current_plyer = game->player_img[1];    
        pos_y++;
        game->key_count++;
    }
    if ((key_code == RIGHT || key_code == 'd') && game->ma_p[pos_y][pos_x + 1] != '1')
    {
        game->current_plyer = game->player_img[4];
        pos_x++;
        game->key_count++;
    }
    if ((key_code == LEFT || key_code == 'a') && game->ma_p[pos_y][pos_x - 1] != '1')
    {
        game->current_plyer = game->player_img[3];
        pos_x--;
        game->key_count++;
    }
    if (game->ma_p[pos_y][pos_x] == 'C')
        game->counter_coin++;
    handler_of_plyer_win_lose(game, pos_y, pos_x);
    if ((game->ma_p[pos_y][pos_x] != '1' && game->ma_p[pos_y][pos_x] != 'E') && game->ma_p[pos_y][pos_x] != 'X')
    {
        game->ma_p[game->pos_play_y][game->pos_play_x] = '0';
        game->pos_play_x = pos_x;
        game->pos_play_y = pos_y;
        game->ma_p[game->pos_play_y][game->pos_play_x] = 'P';

        rander_steps_counter(game , game->key_count);
        draw_map(game);
        psaudo_clear(game);
        ft_printf("steps %d\n", game->key_count);
    }
}
void handler_of_plyer_win_lose(t_game *game, int y, int x)
{
    if (game->ma_p[y][x] == 'X')
    {
        ft_victory(0);
        mlx_free(game);
        mlx_destroy_window(game->mlx, game->win);
        mlx_destroy_display(game->mlx);
        free(game->mlx); 
        exit(EXIT_SUCCESS);
    }
    if (game->ma_p[y][x] == 'E' && game->total_coin == game->counter_coin)
    {
        ft_victory(1);
        mlx_free(game);
        mlx_destroy_window(game->mlx, game->win);
        mlx_destroy_display(game->mlx);
        free(game->mlx);
        exit(EXIT_SUCCESS);
    }
}

void	ft_victory(int check)
{
    if (check == 1)
            ft_printf(GREEN"\n\
    #################################################################\n\
    ##                                                              ##\n\
    ##  ###  ###  ######  ##    ##     ##      ## ## ##    ##   ##  ##\n\
    ##   ##  ##  ##    ## ##    ##     ##      ## ## ###   ##   ##  ##\n\
    ##    ####   #      # ##    ##     ##  ##  ## ## ## ## ##   ##  ##\n\
    ##     ##    ##    ## ##    ##     ## #### ## ## ##  ####       ##\n\
    ##     ##     ######    ####        ###  ###  ## ##   ###   ##  ##\n\
    ##                                                              ##\n\
    ##################################################################\n\n");
    else
        ft_printf(RED"\n\
    ##############################################################################\n\
    ##                                                                          ##\n\
    ##   ###    ###  #######  ##     ##    ##       #######   ######  #######   ##\n\
    ##    ###  ###  ##     ## ##     ##    ##      ##     ## ##    ## ##        ##\n\
    ##     ######   ##     ## ##     ##    ##      ##     ## ##       ##        ##\n\
    ##      ####    ##     ## ##     ##    ##      ##     ##  ######  ######    ##\n\
    ##      ####    ##     ## ##     ##    ##      ##     ##       ## ##        ##\n\
    ##      ####    ##     ## ##     ##    ##      ##     ## ##    ## ##        ##\n\
    ##      ####     #######   #######     ######## #######   ######  #######   ##\n\
    ##                                                                          ##\n\
    ##############################################################################\n\n");
}
