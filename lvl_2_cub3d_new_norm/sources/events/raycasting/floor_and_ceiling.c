/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 02:08:10 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/17 02:18:36 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"
#include "raycasting.h"

static void	floor_and_ceiling3(t_floor_ceiling *fc)
{
	fc->cellx = (int)(fc->floorx);
	fc->celly = (int)(fc->floory);
	fc->tx = (int)(TEXWIDTH * (fc->floorx - fc->cellx)) & (TEXWIDTH - 1);
	fc->ty = (int)(TEXHEIGHT * (fc->floory - fc->celly)) & (TEXHEIGHT - 1);
	fc->floorx += fc->floorstepx;
	fc->floory += fc->floorstepy;
	fc->checkerboardpattern = (int)(fc->cellx + fc->celly) & 1;
}

static void	floor_and_ceiling2(t_mlx *mlx, t_floor_ceiling *fc,
								t_f_c_aux *fc_aux)
{
	fc->raydirx0 = mlx->dirx - mlx->planex;
	fc->raydiry0 = mlx->diry - mlx->planey;
	fc->raydirx1 = mlx->dirx + mlx->planex;
	fc->raydiry1 = mlx->diry + mlx->planey;
	fc_aux->p = fc_aux->y - mlx->height / 2;
	fc->posz = 0.5 * mlx->height;
	fc->rowdistance = fc->posz / fc_aux->p;
	fc->floorstepx = fc->rowdistance * (fc->raydirx1
			- fc->raydirx0) / mlx->width;
	fc->floorstepy = fc->rowdistance * (fc->raydiry1
			- fc->raydiry0) / mlx->width;
	fc->floorx = mlx->posx + fc->rowdistance * fc->raydirx0;
	fc->floory = mlx->posy + fc->rowdistance * fc->raydiry0;
	fc_aux->x = 0;
}

void	floor_and_ceiling(t_mlx *mlx)
{
	t_floor_ceiling	fc;
	t_f_c_aux		fc_aux;

	fc_aux.y = mlx->height / 2 + 1;
	fc_aux.p = fc_aux.y - mlx->height / 2;
	fc_aux.x = 0;
	while (fc_aux.y < mlx->height)
	{
		floor_and_ceiling2(mlx, &fc, &fc_aux);
		while (fc_aux.x < mlx->width)
		{
			floor_and_ceiling3(&fc);
			if (fc.checkerboardpattern == 0)
				fc.floortexture = 3;
			else
				fc.floortexture = 4;
			fc.ceilingtexture = 6;
			fc.color = mlx->floor_color;
			mlx->buf[fc_aux.y][fc_aux.x] = fc.color;
			fc.color = mlx->ceiling_color;
			mlx->buf[mlx->height - fc_aux.y - 1][fc_aux.x] = fc.color;
			fc_aux.x++;
		}
		fc_aux.y++;
	}
}
