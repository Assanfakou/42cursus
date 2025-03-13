/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 02:33:00 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/13 05:12:48 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef WINDOW_HIGHT
#  define WINDOW_HIGHT 1800
# endif

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 3200
# endif

# ifndef GREEN
#  define GREEN "\033[6m"
# endif

# ifndef RED
#  define RED "\033[91m"
# endif

# ifndef WINDOW
#  define WINDOW 10
# endif

# ifndef SUB_PEX
#  define SUB_PEX 43
# endif

# ifndef ESC
#  define ESC 65307
# endif

typedef struct s_game
{
	void	*win;
	void	*mlx;

	void	*wall_img;

	char	**map;
	int		hight_img;
	int		withe_with;
	void	*floor;

	int		pos_x;
	int		pos_y;
	int		with;
	int		hight;

	// pos payer
	int		pos_play_x;
	int		pos_play_y;

	int		exit_pos_x;
	int		exit_pos_y;

	void	*player_img[5];
	void	*current_plyer;

	void	*coin_img;

	void	*current_anim;

	int		counter_steps;

	// coins calcul
	int		total_coin;
	int		counter_coin;

	int		current_frame;
	int		frame_delay;
	int		frame_countdown;

	void	*exit_img_green;
	void	*current_exit_img;

	void	*fire;
}			t_game;

typedef struct l_check_game
{
	int		player_check;
	int		coin_check;
	int		exit_check;
	int		wall_check;
}			t_check_game;

void		draw_map(t_game *game);
void		mv_player(int key_code, t_game *game);
int			handle_keypress(int keycode, t_game *game);
void		coins_num(t_game *game);
void		render_the_animation_coin(t_game *game);
void		player_pos(t_game *game);

void		image_to_window(t_game *game, void *image, int x, int y);
void		render_the_door_anima(t_game *game, void *curren, void **arr);
void		render_fire(t_game *game);
void		handler_of_player_win_lose(t_game *game, int y, int x);
void		ft_victory(int check);
void		mlx_free(t_game *game);
void		file_to_image(t_game *game);
void		clear_way(t_game *game);

int			check_rectangular(t_game *game);
void		check_erours(t_game *game, t_check_game *check);
void		count_charachters(t_game *game, t_check_game *check);
void		fill_map(t_game *game, char *filepath);
void		handle_error_exit(t_game *game, char *error);
char		**alloc_map(int fd, int lines);
int			count_line(char *file_path);
void		free_map(t_game *game, char **map);
void		arounded_by_walls(t_game *game);
int			decide_player(int key_code, t_game *game);

void		flood_fill(char **map, int y, int x);
void		check_valid_path(t_game *game);
void		finding_player(t_game *game, int *y, int *x);
char		**secondary_map(t_game *game);

#endif
