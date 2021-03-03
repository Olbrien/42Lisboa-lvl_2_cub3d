/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:19:12 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/03 02:26:57 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"
#include "raycasting.h"

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
