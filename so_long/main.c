#include <mlx.h>
#include <stdio.h>
#include "so_long.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

int main(void)
{
    t_game game;
    int tile_size = 40; // Size of each tile in pixels
    int map_width = 5;  // Width of the map
    int map_height = 5; // Height of the map

    char map[5][5] = {
        {'1', '0', 'P', '1', '1'},
        {'1', '0', '1', '0', '0'},
        {'1', '1', '1', '1', '1'},
        {'0', '0', '1', '0', '1'},
        {'1', '1', '1', '0', '1'}
    };
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, map_width * tile_size, map_height * tile_size, "so_long");

    // Load images
    game.wll_img = mlx_xpm_file_to_image(game.mlx, "123.xpm", &tile_size, &tile_size);

    int y = 0;
    while (y <= map_height)
    {
        int x = 0;
        while (x <= map_width)
        {
            if (map[y][x] == '1')
                mlx_put_image_to_window(game.mlx, game.win, game.wll_img, x * tile_size, y * tile_size);
            else if (map[y][x] == 'P')
                {
                // game.charachtr = mlx_xpm_file_to_image(game.mlx, "hetler.xpm", &tile_size, &tile_size);
                // mlx_put_image_to_window(game.mlx, game.win, game.charachtr, x * tile_size, y * tile_size);
                }
            x++;
        }
        y++;
    }
    mlx_loop(game.mlx);

    return (0);
}
