/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 01:36:10 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/13 05:11:19 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_fire(t_game *game)
{
	if (game->current_frame == 0)
		game->curent_fire = game->fire[0];
	if (game->current_frame == 1)
		game->curent_fire = game->fire[1];
	if (game->current_frame == 3)
		game->curent_fire = game->fire[2];
	if (game->current_frame == 4)
		game->curent_fire = game->fire[3];
}

void	update_animation(t_game *game)
{
	game->current_frame++;
	if (game->current_frame >= game->frame_delay)
		game->current_frame = 0;
}

void	render_the_animation(t_game *game)
{
	if (game->current_frame == 0)
		game->current_anim = game->coin_img[0];
	if (game->current_frame == 1)
		game->current_anim = game->coin_img[1];
	if (game->current_frame == 0)
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

int	loop_rendering(t_game *game)
{
	update_animation(game);
	draw_map(game);
	usleep(100000);
	return (0);
}
