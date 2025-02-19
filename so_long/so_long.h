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

typedef struct s_game
{
    void *win;
    void *mlx;

    char **map;
    int hight_img;
    int withe_with;

    void *wll_img;
    void *charachtr;
}       t_game;

# endif
