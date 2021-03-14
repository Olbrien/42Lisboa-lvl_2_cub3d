/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 02:14:16 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/12 21:16:18 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"
#include "raycasting.h"

void	walls5(t_mlx *mlx, t_walls *walls)
{
	if (walls->side == 0)
		walls->perpWallDist = (walls->mapX - mlx->posX
				+ (1 - walls->stepX) / 2) / walls->rayDirX;
	else if (walls->side == 1)
		walls->perpWallDist = (walls->mapX - mlx->posX
				+ (1 - walls->stepX) / 2) / walls->rayDirX;
	else if (walls->side == -1)
		walls->perpWallDist = (walls->mapY - mlx->posY
				+ (1 - walls->stepY) / 2) / walls->rayDirY;
	else if (walls->side == -2)
		walls->perpWallDist = (walls->mapY - mlx->posY
				+ (1 - walls->stepY) / 2) / walls->rayDirY;
	walls->lineHeight = (int)(mlx->height / walls->perpWallDist);
	walls->drawStart = -walls->lineHeight / 2 + mlx->height / 2;
	if (walls->drawStart < 0)
		walls->drawStart = 0;
	walls->drawEnd = walls->lineHeight / 2 + mlx->height / 2;
	if (walls->drawEnd >= mlx->height)
		walls->drawEnd = mlx->height - 1;
	walls->texNum = mlx->worldMap[walls->mapX][walls->mapY] - 1;
}

void	walls4(t_mlx *mlx, t_walls *walls)
{
	if (walls->sideDistX < walls->sideDistY)
	{
		walls->sideDistX += walls->deltaDistX;
		walls->mapX += walls->stepX;
		if (walls->stepX > 0)
			walls->side = 0;
		else
			walls->side = 1;
	}
	else
	{
		walls->sideDistY += walls->deltaDistY;
		walls->mapY += walls->stepY;
		if (walls->stepY > 0)
			walls->side = -1;
		else
			walls->side = -2;
	}
	if (mlx->worldMap[walls->mapX][walls->mapY] > 0)
		walls->hit = 1;
}

void	walls3(t_mlx *mlx, t_walls *walls)
{
	if (walls->rayDirY < 0)
	{
		walls->stepY = -1;
		walls->sideDistY = (mlx->posY - walls->mapY) * walls->deltaDistY;
	}
	else
	{
		walls->stepY = 1;
		walls->sideDistY = (walls->mapY + 1.0 - mlx->posY) * walls->deltaDistY;
	}
}

void	walls2(t_mlx *mlx, t_walls *walls)
{
	walls->cameraX = 2 * walls->x / (double)mlx->width - 1;
	walls->rayDirX = mlx->dirX + mlx->planeX * walls->cameraX;
	walls->rayDirY = mlx->dirY + mlx->planeY * walls->cameraX;
	walls->mapX = (int)mlx->posX;
	walls->mapY = (int)mlx->posY;
	walls->deltaDistX = fabs(1 / walls->rayDirX);
	walls->deltaDistY = fabs(1 / walls->rayDirY);
	walls->hit = 0;
	if (walls->rayDirX < 0)
	{
		walls->stepX = -1;
		walls->sideDistX = (mlx->posX - walls->mapX) * walls->deltaDistX;
	}
	else
	{
		walls->stepX = 1;
		walls->sideDistX = (walls->mapX + 1.0 - mlx->posX) * walls->deltaDistX;
	}
}

void	walls(t_mlx *mlx)
{
	t_walls	walls;

	walls.x = 0;
	walls.y = 0;
	while (walls.x < mlx->width)
	{
		walls2(mlx, &walls);
		walls3(mlx, &walls);
		while (walls.hit == 0)
			walls4(mlx, &walls);
		walls5(mlx, &walls);
		walls6(mlx, &walls);
		while (walls.y < walls.drawEnd)
		{
			walls.texY = (int)walls.texPos & (TEXHEIGHT - 1);
			walls.texPos += walls.step;
			walls7(mlx, &walls);
			mlx->buf[walls.y][walls.x] = walls.color;
			walls.y++;
		}
		mlx->zBuffer[walls.x] = walls.perpWallDist;
		walls.x++;
	}
}
