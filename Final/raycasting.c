/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:19:12 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/02 22:43:15 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

struct s_sprite	s_sprite[numSprites] =
{
	{20.5, 11.5, 10}, //green light in front of playerstart
	//green lights in every room
	{18.5,4.5, 10},
	{10.0,4.5, 10},
	{10.0,12.5,10},
	{3.5, 6.5, 10},
	{3.5, 20.5,10},
	{3.5, 14.5,10},
	{14.5,20.5,10},

	//row of pillars in front of wall: fisheye test
	{18.5, 10.5, 9},
	{18.5, 11.5, 9},
	{18.5, 12.5, 9},

	//some barrels around the map
	{21.5, 1.5, 8},
	{15.5, 1.5, 8},
	{16.0, 1.8, 8},
	{16.2, 1.2, 8},
	{3.5,  2.5, 8},
	{9.5, 15.5, 8},
	{10.0, 15.1,8},
	{10.5, 15.8,8},
};

static int	compare(const void *first, const void *second)
{
	if (*(int *)first > *(int *)second)
		return (1);
	else if (*(int *)first < *(int *)second)
		return (-1);
	else
		return (0);
}

void	sort_order(t_pair *orders, int amount)
{
	t_pair	tmp;
	int i;
	int j;

	i = 0;
	j = 0;

	while (i < amount)
	{
		j = 0;
		while (j < amount - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
			j++;
		}
		i++;
	}


}

void	sortSprites(int *order, double *dist, int amount)
{
	t_pair	*sprites;
	int i;

	i = 0;

	sprites = (t_pair*)malloc(sizeof(t_pair) * amount);
	if (sprites == NULL)
		return ;

	while (i < amount)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
		i++;
	}

	sort_order(sprites, amount);

	i = 0;

	while (i < amount)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
		i++;
	}
	free(sprites);
}


void	draw(t_mlx *info)
{
	int y;
	int x;

	x = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			info->img.data[y * width + x] = info->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}




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
			fc.floorTexture;

			if (fc.checkerBoardPattern == 0)
				fc.floorTexture = 3;
			else
				fc.floorTexture = 4;

			fc.ceilingTexture = 6;

			fc.color = mlx->texture[fc.floorTexture][texWidth * fc.ty + fc.tx];
			fc.color = (fc.color >> 1) & 8355711; //
			mlx->buf[y][x] = fc.color;

			fc.color = mlx->texture[fc.ceilingTexture][texWidth * fc.ty + fc.tx];
			fc.color = (fc.color >> 1) & 8355711; // make a bit darker
			mlx->buf[height - y - 1][x] = fc.color;
			x++;
		}
		y++;
	}
}


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


void	sprites_draw(t_mlx *mlx)
{
	t_sprite spr;
	int i;
	int y;
	int stripe;

	i = 0;
	y = 0;
	stripe = 0;

	while (i < numSprites)
	{
		spr.spriteOrder[i] = i;
		spr.spriteDistance[i] = ((mlx->posX - s_sprite[i].x) *
								(mlx->posX - s_sprite[i].x) + (mlx->posY - s_sprite[i].y)
								* (mlx->posY - s_sprite[i].y));
		i++;
	}

	i = 0;

	sortSprites(spr.spriteOrder, spr.spriteDistance, numSprites);


	while (i < numSprites)
	{
		spr.spriteX = s_sprite[spr.spriteOrder[i]].x - mlx->posX;
		spr.spriteY = s_sprite[spr.spriteOrder[i]].y - mlx->posY;

		spr.invDet = 1.0 / (mlx->planeX * mlx->dirY - mlx->dirX * mlx->planeY);

		spr.transformX = spr.invDet * (mlx->dirY * spr.spriteX - mlx->dirX * spr.spriteY);
		spr.transformY = spr.invDet * (-mlx->planeY * spr.spriteX + mlx->planeX * spr.spriteY);

		spr.spriteScreenX = (int)((width / 2) * (1 + spr.transformX / spr.transformY));

		spr.vMoveScreen = (int)(vMove / spr.transformY);

		spr.spriteHeight = (int)fabs((height / spr.transformY) / vDiv);

		spr.drawStartY = -spr.spriteHeight / 2 + height / 2 + spr.vMoveScreen;

		if(spr.drawStartY < 0)
			spr.drawStartY = 0;

		spr.drawEndY = spr.spriteHeight / 2 + height / 2 + spr.vMoveScreen;

		if(spr.drawEndY >= height)
			spr.drawEndY = height - 1;

		spr.spriteWidth = (int)fabs((height / spr.transformY) / uDiv);

		spr.drawStartX = -spr.spriteWidth / 2 + spr.spriteScreenX;

		if(spr.drawStartX < 0)
			spr.drawStartX = 0;

		spr.drawEndX = spr.spriteWidth / 2 + spr.spriteScreenX;

		if(spr.drawEndX >= width)
			spr.drawEndX = width - 1;

		stripe = spr.drawStartX;
		while (stripe < spr.drawEndX)
		{
			spr.texX = (int)((256 * (stripe - (-spr.spriteWidth / 2 + spr.spriteScreenX)) * texWidth / spr.spriteWidth) / 256);

			if(spr.transformY > 0 && stripe > 0 && stripe < width && spr.transformY < mlx->zBuffer[stripe])
			{
				y = spr.drawStartY;
				while (y < spr.drawEndY)
				{
					spr.d = (y-spr.vMoveScreen) * 256 - height * 128 + spr.spriteHeight * 128;
					spr.texY = ((spr.d * texHeight) / spr.spriteHeight) / 256;
					spr.color = mlx->texture[s_sprite[spr.spriteOrder[i]].texture][texWidth * spr.texY + spr.texX];
					if((spr.color & 0x00FFFFFF) != 0)
						mlx->buf[y][stripe] = spr.color;
					y++;
				}
			}
			stripe++;
		}
		i++;
	}
}
