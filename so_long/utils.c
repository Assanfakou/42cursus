#include "so_long.h"

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
void image_to_window(t_game *game, void *image, int x, int y)
{
    mlx_put_image_to_window(game->mlx, game->win, image, x * SUB_PEX, y * SUB_PEX);
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
