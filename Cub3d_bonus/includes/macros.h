/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:06:23 by iantar            #+#    #+#             */
/*   Updated: 2023/08/30 21:01:06 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H
/*
enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};
*/
# define PI 3.1415926535
# define ON_DESTROY 17
# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define LEFT_ARR 65361
# define RIGHT_ARR 65363
# define X_TEX 0
# define Y_TEX 1
# define MOUSEMOVE  6
//utils
# define NO 11
# define SO 112
# define EA 13
# define WE 14


//colors
# define RED 0x00FF0000
# define BLACK 0x00000000
# define WITE 0x00FFFFFF
# define BLUE 0x000000FF 
# define YELLOW 0x00FFFF00
# define TIFFANY_BLUE 0x00A0E7E5
# define TEAL 0x0029A0B1
# define BRWON 0x00FFD898 //ground
# define CYAN 0x0000FFFF //sky
# define GRAY 0x00848482 //wall
# define NEON_GREEN 0x0014E114

# define SPEED 0.05
# define PLAYER_DIM 5

# define MAPWIDTH 12
# define MAPHEIGHT 10
# define SCREEN_HEIGHT 900
# define SCREEN_WIDTH 1500
//0x0029A0B1
# define GRID 64
# define MINI_GRID 10

# define DOOR_OPEND 1
# define DOOR_CLOSED 0
#endif
