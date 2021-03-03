/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 02:14:16 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/03 02:20:51 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"
#include "raycasting.h"

void	walls(t_mlx *mlx)
{
	t_walls walls;
	int x;
	int y;

	x = 0;
	y = 0;

	while (x < width)
	{
		walls.cameraX = 2 * x / (double)width - 1;
		walls.rayDirX = mlx->dirX + mlx->planeX * walls.cameraX;
		walls.rayDirY = mlx->dirY + mlx->planeY * walls.cameraX;

		walls.mapX = (int)mlx->posX;
		walls.mapY = (int)mlx->posY;

		walls.deltaDistX = fabs(1 / walls.rayDirX);
		walls.deltaDistY = fabs(1 / walls.rayDirY);

		walls.hit = 0;

		if(walls.rayDirX < 0)
		{
			walls.stepX = -1;
			walls.sideDistX = (mlx->posX - walls.mapX) * walls.deltaDistX;
		}
		else
		{
			walls.stepX = 1;
			walls.sideDistX = (walls.mapX + 1.0 - mlx->posX) * walls.deltaDistX;
		}
		if(walls.rayDirY < 0)
		{
			walls.stepY = -1;
			walls.sideDistY = (mlx->posY - walls.mapY) * walls.deltaDistY;
		}
		else
		{
			walls.stepY = 1;
			walls.sideDistY = (walls.mapY + 1.0 - mlx->posY) * walls.deltaDistY;
		}

		while (walls.hit == 0)
		{
			if(walls.sideDistX < walls.sideDistY)
			{
				walls.sideDistX += walls.deltaDistX;
				walls.mapX += walls.stepX;
				walls.side = 0;
			}
			else
			{
				walls.sideDistY += walls.deltaDistY;
				walls.mapY += walls.stepY;
				walls.side = 1;
			}
			if(worldMap[walls.mapX][walls.mapY] > 0)
				walls.hit = 1;
		}

		if(walls.side == 0)
			walls.perpWallDist = (walls.mapX - mlx->posX + (1 - walls.stepX) / 2) / walls.rayDirX;
		else
			walls.perpWallDist = (walls.mapY - mlx->posY + (1 - walls.stepY) / 2) / walls.rayDirY;

		walls.lineHeight = (int)(height / walls.perpWallDist);

		walls.drawStart = -walls.lineHeight / 2 + height / 2;
		if(walls.drawStart < 0)
			walls.drawStart = 0;
		walls.drawEnd = walls.lineHeight / 2 + height / 2;
		if(walls.drawEnd >= height)
			walls.drawEnd = height - 1;

		walls.texNum = worldMap[walls.mapX][walls.mapY] - 1;

		if (walls.side == 0)
			walls.wallX = mlx->posY + walls.perpWallDist * walls.rayDirY;
		else
			walls.wallX = mlx->posX + walls.perpWallDist * walls.rayDirX;
		walls.wallX -= floor((walls.wallX));

		walls.texX = (int)(walls.wallX * (double)texWidth);

		if(walls.side == 0 && walls.rayDirX > 0)
			walls.texX = texWidth - walls.texX - 1;
		if(walls.side == 1 && walls.rayDirY < 0)
			walls.texX = texWidth - walls.texX - 1;

		walls.step = 1.0 * texHeight / walls.lineHeight;
		walls.texPos = (walls.drawStart - height / 2 + walls.lineHeight / 2) * walls.step;

		y = walls.drawStart;

		while (y < walls.drawEnd)
		{
			walls.texY = (int)walls.texPos & (texHeight - 1);
			walls.texPos += walls.step;
			walls.color = mlx->texture[walls.texNum][texHeight * walls.texY + walls.texX];

			if(walls.side == 1)
				walls.color = (walls.color >> 1) & 8355711;
			mlx->buf[y][x] = walls.color;
			y++;
		}
		mlx->zBuffer[x] = walls.perpWallDist;
		x++;
	}
}
