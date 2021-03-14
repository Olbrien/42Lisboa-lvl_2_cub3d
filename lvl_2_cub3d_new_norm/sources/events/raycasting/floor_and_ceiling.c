/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 02:08:10 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/12 20:09:57 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"
#include "raycasting.h"

static void	floor_and_ceiling3(t_floor_ceiling *fc)
{
	fc->cellX = (int)(fc->floorX);
	fc->cellY = (int)(fc->floorY);
	fc->tx = (int)(TEXWIDTH * (fc->floorX - fc->cellX)) & (TEXWIDTH - 1);
	fc->ty = (int)(TEXHEIGHT * (fc->floorY - fc->cellY)) & (TEXHEIGHT - 1);
	fc->floorX += fc->floorStepX;
	fc->floorY += fc->floorStepY;
	fc->checkerBoardPattern = (int)(fc->cellX + fc->cellY) & 1;
}

static void	floor_and_ceiling2(t_mlx *mlx, t_floor_ceiling *fc,
								t_f_c_aux *fc_aux)
{
	fc->rayDirX0 = mlx->dirX - mlx->planeX;
	fc->rayDirY0 = mlx->dirY - mlx->planeY;
	fc->rayDirX1 = mlx->dirX + mlx->planeX;
	fc->rayDirY1 = mlx->dirY + mlx->planeY;
	fc_aux->p = fc_aux->y - mlx->height / 2;
	fc->posZ = 0.5 * mlx->height;
	fc->rowDistance = fc->posZ / fc_aux->p;
	fc->floorStepX = fc->rowDistance * (fc->rayDirX1
			- fc->rayDirX0) / mlx->width;
	fc->floorStepY = fc->rowDistance * (fc->rayDirY1
			- fc->rayDirY0) / mlx->width;
	fc->floorX = mlx->posX + fc->rowDistance * fc->rayDirX0;
	fc->floorY = mlx->posY + fc->rowDistance * fc->rayDirY0;
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
			if (fc.checkerBoardPattern == 0)
				fc.floorTexture = 3;
			else
				fc.floorTexture = 4;
			fc.ceilingTexture = 6;
			fc.color = mlx->floor_color;
			mlx->buf[fc_aux.y][fc_aux.x] = fc.color;
			fc.color = mlx->ceiling_color;
			mlx->buf[mlx->height - fc_aux.y - 1][fc_aux.x] = fc.color;
			fc_aux.x++;
		}
		fc_aux.y++;
	}
}
