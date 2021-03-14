/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 02:19:38 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/14 03:07:31 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

typedef struct s_floor_ceiling
{
	float	rayDirX0;
	float	rayDirY0;
	float	rayDirX1;
	float	rayDirY1;
	float	posZ;
	float	rowDistance;
	float	floorStepX;
	float	floorStepY;
	float	floorX;
	float	floorY;
	int		cellX;
	int		cellY;
	int		tx;
	int		ty;
	int		checkerBoardPattern;
	int		floorTexture;
	int		ceilingTexture;
	int		color;
}				t_floor_ceiling;

typedef struct s_walls
{
	int		x;
	int		y;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		texNum;
	double	wallX;
	int		texX;
	double	step;
	double	texPos;
	int		texY;
	int		color;
}				t_walls;

struct s_sprite
{
	double	x;
	double	y;
	int		texture;
};

typedef struct s_sprite_two
{
	int		i;
	int		y;
	int		stripe;
	int		spriteOrder[100];
	double	spriteDistance[100];
	double	spriteX;
	double	spriteY;
	double	invDet;
	double	transformX;
	double	transformY;
	int		spriteScreenX;
	int		vMoveScreen;
	int		spriteHeight;
	int		drawStartY;
	int		drawEndY;
	int		spriteWidth;
	int		drawStartX;
	int		drawEndX;
	int		texX;
	int		d;
	int		texY;
	int		color;
}				t_sprite;

typedef struct s_pair
{
	double	first;
	int		second;
}					t_pair;

typedef struct s_f_c_aux
{
	int		x;
	int		y;
	int		p;
}					t_f_c_aux;

typedef struct s_bmp
{
	int				filesize;
	char			*img;
	unsigned char	fileheader[14];
	unsigned char	infoheader[40];
	unsigned char	pad[3];
	int				color;
	int				fd;
}					t_bmp;

void		sortSprites(int *order, double *dist, int amount);
void		sort_order(t_pair *orders, int amount);
void		walls6(t_mlx *mlx, t_walls *walls);
void		walls7(t_mlx *mlx, t_walls *walls);

#endif
