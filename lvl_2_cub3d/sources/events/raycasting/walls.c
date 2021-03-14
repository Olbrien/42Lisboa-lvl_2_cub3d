/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 02:14:16 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/14 18:42:45 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"
#include "raycasting.h"

void	walls5(t_mlx *mlx, t_walls *walls)
{
	if (walls->side == 0)
		walls->perpwalldist = (walls->mapx - mlx->posX
				+ (1 - walls->stepx) / 2) / walls->raydirx;
	else if (walls->side == 1)
		walls->perpwalldist = (walls->mapx - mlx->posX
				+ (1 - walls->stepx) / 2) / walls->raydirx;
	else if (walls->side == -1)
		walls->perpwalldist = (walls->mapy - mlx->posY
				+ (1 - walls->stepy) / 2) / walls->raydiry;
	else if (walls->side == -2)
		walls->perpwalldist = (walls->mapy - mlx->posY
				+ (1 - walls->stepy) / 2) / walls->raydiry;
	walls->lineheight = (int)(mlx->height / walls->perpwalldist);
	walls->drawstart = -walls->lineheight / 2 + mlx->height / 2;
	if (walls->drawstart < 0)
		walls->drawstart = 0;
	walls->drawend = walls->lineheight / 2 + mlx->height / 2;
	if (walls->drawend >= mlx->height)
		walls->drawend = mlx->height - 1;
	walls->texnum = mlx->worldmap[walls->mapx][walls->mapy] - 1;
}

void	walls4(t_mlx *mlx, t_walls *walls)
{
	if (walls->sidedistx < walls->sidedisty)
	{
		walls->sidedistx += walls->deltadistx;
		walls->mapx += walls->stepx;
		if (walls->stepx > 0)
			walls->side = 0;
		else
			walls->side = 1;
	}
	else
	{
		walls->sidedisty += walls->deltadisty;
		walls->mapy += walls->stepy;
		if (walls->stepy > 0)
			walls->side = -1;
		else
			walls->side = -2;
	}
	if (mlx->worldmap[walls->mapx][walls->mapy] > 0)
		walls->hit = 1;
}

void	walls3(t_mlx *mlx, t_walls *walls)
{
	if (walls->raydiry < 0)
	{
		walls->stepy = -1;
		walls->sidedisty = (mlx->posY - walls->mapy) * walls->deltadisty;
	}
	else
	{
		walls->stepy = 1;
		walls->sidedisty = (walls->mapy + 1.0 - mlx->posY) * walls->deltadisty;
	}
}

void	walls2(t_mlx *mlx, t_walls *walls)
{
	walls->camerax = 2 * walls->x / (double)mlx->width - 1;
	walls->raydirx = mlx->dirX + mlx->planex * walls->camerax;
	walls->raydiry = mlx->dirY + mlx->planey * walls->camerax;
	walls->mapx = (int)mlx->posX;
	walls->mapy = (int)mlx->posY;
	walls->deltadistx = fabs(1 / walls->raydirx);
	walls->deltadisty = fabs(1 / walls->raydiry);
	walls->hit = 0;
	if (walls->raydirx < 0)
	{
		walls->stepx = -1;
		walls->sidedistx = (mlx->posX - walls->mapx) * walls->deltadistx;
	}
	else
	{
		walls->stepx = 1;
		walls->sidedistx = (walls->mapx + 1.0 - mlx->posX) * walls->deltadistx;
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
		while (walls.y < walls.drawend)
		{
			walls.texy = (int)walls.texpos & (TEXHEIGHT - 1);
			walls.texpos += walls.step;
			walls7(mlx, &walls);
			mlx->buf[walls.y][walls.x] = walls.color;
			walls.y++;
		}
		mlx->zbuffer[walls.x] = walls.perpwalldist;
		walls.x++;
	}
}
