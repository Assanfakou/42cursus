/* ************************************************************************** */
    /*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 02:33:00 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/17 20:56:52 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../../minlibx/mlx.h"

# define WINDOW 369
# define TILE_SIZE 45

# define LEFT 65361
# define UP 65362 
# define RIGHT 65363
# define DOWN 65364
# define ESC 65307

# define WIDTH 9
# define HEIGHT 9

typedef struct s_game
{
    void *win;
    void *mlx;

    char ma_p[9][9];
    int hight_img;
    int withe_with;

    //pos payer
    int pos_play_x;
    int pos_play_y;

    void *wall_img;
    void *player_img;
    void *coin_img_1;
    void *coin_img_2;
    void *exit_img;
}       t_game;

void draw_map(t_game *game);
int mv_player(int key_code, t_game *game);
int handle_keypress(int keycode, t_game *game);
void fill_map_struct(t_game *game);

# endif
