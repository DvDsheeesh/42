/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:54:20 by melshata          #+#    #+#             */
/*   Updated: 2026/01/07 11:54:40 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_game
{
    void    *mlx;
    void    *win;
    char    **map_grid;
    void    *wall_img;
    void    *floor_img;
    void    *player_img;
    int     player_x; 
    int     player_y; 
} t_game;