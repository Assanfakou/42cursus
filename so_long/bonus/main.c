/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:25:52 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/08 17:29:26 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw_map(t_game *game)
{
    int y;
    int x;

    player_pos(game);
    y = 0;
    while (y < game->hight)
    {
        x = 0;
        while (x < game->with)
        {
            if (game->map[y][x] == '1')
                image_to_window(game, game->wall_img, x, y);
            else if (game->map[y][x] == 'E')
            {
                if (game->total_coin == game->counter_coin)
                    render_the_animation(game);
                else
                    render_the_animation(game);
                image_to_window(game, game->current_exit_img, x, y);
            }
            else if (game->map[y][x] == 'P')
                    image_to_window(game, game->current_plyer, x, y);
            else if (game->map[y][x] == 'C')
            {
                render_the_animation(game);
                image_to_window(game, game->current_anim, x, y);
            }
            else if (game->map[y][x] == 'X')
            {
                render_fire(game);
                image_to_window(game, game->curent_fire, x, y);
            }
            x++;
        }
        y++;
    }
}

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

void update_animation(t_game *game)
{
    game->current_frame++;
    if (game->current_frame >= game->frame_delay)
        game->current_frame = 0;
}

void render_the_animation(t_game *game)
{
    if (game->current_frame == 0)
        game->current_anim = game->coin_img[0];
    if (game->current_frame == 1)
        game->current_anim = game->coin_img[1];
    if (game->current_frame == 0 )
        game->current_exit_img = game->exit_img_green[0];
    if (game->current_frame == 1)
        game->current_exit_img = game->exit_img_green[1];
    if (game->current_frame == 2)
        game->current_exit_img = game->exit_img_green[2];
    if (game->current_frame == 3)
        game->current_exit_img = game->exit_img_green[3];
    if (game->current_frame == 0 && (game->total_coin != game->counter_coin))
        game->current_exit_img = game->exit_img_red[0];
    if (game->current_frame == 1 && (game->total_coin != game->counter_coin))
        game->current_exit_img = game->exit_img_red[1];
    if (game->current_frame == 2 && (game->total_coin != game->counter_coin))
        game->current_exit_img = game->exit_img_red[2];
    if (game->current_frame == 3 && (game->total_coin != game->counter_coin))
        game->current_exit_img = game->exit_img_red[3];
}

void loop_rendering(t_game *game)
{
    update_animation(game);
    draw_map(game);
    usleep(100000);
}

int main(int ac, char **av)
{
    t_game game;

    fill_map(&game, av[1]);
    game.total_coin = 0;
    game.counter_coin = 0;
    game.key_count = 0;
    coins_num(&game);
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, game.with * SUB_PEX, game.hight * SUB_PEX + 60, "so_long");

    file_to_image(&game);
    game.current_frame = 0;
    game.frame_delay = 6;
    draw_map(&game);
    mlx_put_image_to_window(game.mlx, game.win, game.counter_bar, 0 * SUB_PEX, 0 * SUB_PEX);
    ft_printf("total ;%d", game.total_coin);
    mlx_loop_hook(game.mlx, (int (*)(void *))loop_rendering, &game);
    mlx_key_hook(game.win, handle_keypress, &game);
    mlx_loop(game.mlx);
}
