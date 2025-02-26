/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 02:33:00 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/25 23:08:49 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
#define SO_LONG

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define GREEN				"\033[0;32m"
# define RED 				"\033[91m"
# ifndef WINDOW	
# define WINDOW 1000
# endif
# ifndef SUB_PEX
# define SUB_PEX 43
# endif

# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define ESC 65307

# ifndef WIDTH
# define WIDTH 22// 3
# endif
# define HEIGHT 12 // T

typedef struct s_game
{
	void	*win;
	void	*mlx;

	void	*wall_img;

	char	ma_p[HEIGHT][WIDTH];
	int		hight_img;
	int		withe_with;
	void	*floor;

	// pos payer
	int		pos_play_x;
	int		pos_play_y;


	void	*player_img[5];
	void	*current_plyer;

	void	*coin_img[2];
	int		coin_pos_y;
	int		coin_pos_x;
	void	*current_anim;

	//coins calcul
	int total_coin;
	int counter_coin;

	int		current_frame;
	int		frame_delay;
	int		frame_countdown;

	void	*exit_img_green[4];
	void	*exit_img_red[4];
	void	*current_exit_img;

	void	*fire[5];
	void	*curent_fire;

	void 	*header;
}			t_game;

void		draw_map(t_game *game);
void		mv_player(int key_code, t_game *game);
int			handle_keypress(int keycode, t_game *game);
void		fill_map_struct(t_game *game);
void		render_the_animation_coin(t_game *game);
void		player_pos(t_game *game);

void		image_to_window(t_game *game, void *image, int x, int y);
void		render_the_door_anima(t_game *game, void *curren, void **arr);
void 		render_fire(t_game *game);
void 		handler_of_player_win(t_game *game, int y, int x);
void 		handler_of_palyer_lose(t_game *game, int y, int x);
void		ft_victory(int check);
void mlx_free(t_game *game);

#endif
