/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:33:10 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/03 02:22:49 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//#include "events.h"
//#include "keys.h"

#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#define texWidth 64
#define texHeight 64

#define mapWidth 24
#define mapHeight 24

#define width 640
#define height 480

#define numSprites 19

#define uDiv 1
#define vDiv 1
#define vMove 0.0

#define	RED_PIXEL 0xFF0000
#define	GREEN_PIXEL 0x00FF00
#define	BLUE_PIXEL 0x0000FF
#define WHITE_PIXEL 0xFFFFFF
#define YELLOW_PIXEL 0xFFFF00
#define PINK_PIXEL 0xFFC0CB


typedef struct	s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;

	t_img	img;

	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;

	int		key_a;
	int		key_w;
	int		key_s;
	int		key_d;
	int		key_left;
	int		key_right;
	int		key_esc;

	int		buf[height][width];

	double	zBuffer[width];

	int		**texture;

	double	moveSpeed;
	double	rotSpeed;
}				t_mlx;

int		worldMap[mapWidth][mapHeight];

int		error_message(int ret);
int		error_message_free(int ret, t_mlx *mlx);

int		initialize_texture(t_mlx *mlx);
void	load_texture(t_mlx *mlx);

void	events(t_mlx *mlx);
int		key_release(int key, t_mlx *mlx);
int		key_press(int key, t_mlx *mlx);

void	floor_and_ceiling(t_mlx *mlx);
void	walls(t_mlx *mlx);

void	sprites_draw(t_mlx *mlx);

void	draw(t_mlx *info);

void	keys_wasd_1(t_mlx *mlx);
void	keys_arrows(t_mlx *mlx);
void	keys_escape(t_mlx *mlx);

#endif
