/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 02:19:38 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/16 19:33:54 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

typedef struct	s_floor_ceiling
{
	float	raydirx0;
	float	raydiry0;
	float	raydirx1;
	float	raydiry1;
	float	posz;
	float	rowdistance;
	float	floorstepx;
	float	floorstepy;
	float	floorx;
	float	floory;
	int		cellx;
	int		celly;
	int		tx;
	int		ty;
	int		checkerboardpattern;
	int		floortexture;
	int		ceilingtexture;
	int		color;
}				t_floor_ceiling;

typedef struct	s_walls
{
	int		x;
	int		y;
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		texnum;
	double	wallx;
	int		texx;
	double	step;
	double	texpos;
	int		texy;
	int		color;
}				t_walls;

struct			s_sprite
{
	double	x;
	double	y;
	int		texture;
};

typedef struct	s_sprite_two
{
	int		i;
	int		y;
	int		stripe;
	int		spriteorder[100];
	double	spritedistance[100];
	double	spritex;
	double	spritey;
	double	invdet;
	double	transformx;
	double	transformy;
	int		spritescreenx;
	int		vmovescreen;
	int		spriteheight;
	int		drawstarty;
	int		drawendy;
	int		spritewidth;
	int		drawstartx;
	int		drawendx;
	int		texx;
	int		d;
	int		texy;
	int		color;
}				t_sprite;

typedef struct	s_pair
{
	double	first;
	int		second;
}				t_pair;

typedef struct	s_f_c_aux
{
	int		x;
	int		y;
	int		p;
}				t_f_c_aux;

typedef struct	s_bmp
{
	int				filesize;
	char			*img;
	unsigned char	fileheader[14];
	unsigned char	infoheader[40];
	unsigned char	pad[3];
	int				color;
	int				fd;
}				t_bmp;

void			sortsprites(int *order, double *dist, int amount);
void			sort_order(t_pair *orders, int amount);
void			walls6(t_mlx *mlx, t_walls *walls);
void			walls7(t_mlx *mlx, t_walls *walls);

#endif
