/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 02:08:10 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/03 02:20:47 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"
#include "raycasting.h"

void	floor_and_ceiling(t_mlx *mlx)
{
	t_floor_ceiling fc;
	int x;
	int y;
	int p;

	y = height / 2 + 1;
	p = y - height / 2;
	x = 0;

	while (y < height)
	{
		fc.rayDirX0 = mlx->dirX - mlx->planeX;
		fc.rayDirY0 = mlx->dirY - mlx->planeY;
		fc.rayDirX1 = mlx->dirX + mlx->planeX;
		fc.rayDirY1 = mlx->dirY + mlx->planeY;

		p = y - height / 2;

		fc.posZ = 0.5 * height;
		fc.rowDistance = fc.posZ / p;

		fc.floorStepX = fc.rowDistance * (fc.rayDirX1 - fc.rayDirX0) / width;
		fc.floorStepY = fc.rowDistance * (fc.rayDirY1 - fc.rayDirY0) / width;

		fc.floorX = mlx->posX + fc.rowDistance * fc.rayDirX0;
		fc.floorY = mlx->posY + fc.rowDistance * fc.rayDirY0;

		x = 0;
		while (x < width)
		{
			fc.cellX = (int)(fc.floorX);
			fc.cellY = (int)(fc.floorY);

			fc.tx = (int)(texWidth * (fc.floorX - fc.cellX)) & (texWidth - 1);
			fc.ty = (int)(texHeight * (fc.floorY - fc.cellY)) & (texHeight - 1);

			fc.floorX += fc.floorStepX;
			fc.floorY += fc.floorStepY;

			fc.checkerBoardPattern = (int)(fc.cellX + fc.cellY) & 1;

			if (fc.checkerBoardPattern == 0)
				fc.floorTexture = 3;
			else
				fc.floorTexture = 4;

			fc.ceilingTexture = 6;

			fc.color = mlx->texture[fc.floorTexture][texWidth * fc.ty + fc.tx];
			fc.color = (fc.color >> 1) & 8355711;
			mlx->buf[y][x] = fc.color;

			fc.color = mlx->texture[fc.ceilingTexture][texWidth * fc.ty + fc.tx];
			fc.color = (fc.color >> 1) & 8355711;
			mlx->buf[height - y - 1][x] = fc.color;
			x++;
		}
		y++;
	}
}
