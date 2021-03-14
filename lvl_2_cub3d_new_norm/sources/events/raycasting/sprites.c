/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:19:12 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/12 20:49:00 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"
#include "raycasting.h"

void	sprites_draw4(t_mlx *mlx, t_sprite *spr)
{
	spr->texX = (int)((256 * (spr->stripe - (-spr->spriteWidth / 2
						+ spr->spriteScreenX))
				* TEXWIDTH / spr->spriteWidth) / 256);
	if (spr->transformY > 0 && spr->stripe > 0 && spr->stripe < mlx->width
		&& spr->transformY < mlx->zBuffer[spr->stripe])
	{
		spr->y = spr->drawStartY;
		while (spr->y < spr->drawEndY)
		{
			spr->d = (spr->y - spr->vMoveScreen) * 256 - mlx->height
				* 128 + spr->spriteHeight * 128;
			spr->texY = ((spr->d * TEXHEIGHT) / spr->spriteHeight) / 256;
			spr->color = mlx->texture[10][TEXWIDTH
				* spr->texY + spr->texX];
			if ((spr->color & 0x00FFFFFF) != 0)
				mlx->buf[spr->y][spr->stripe] = spr->color;
			spr->y++;
		}
	}
	spr->stripe++;
}

void	sprites_draw3(t_mlx *mlx, t_sprite *spr)
{
	spr->spriteX = mlx->sprite_x[spr->spriteOrder[spr->i]] - mlx->posX;
	spr->spriteY = mlx->sprite_y[spr->spriteOrder[spr->i]] - mlx->posY;
	spr->invDet = 1.0 / (mlx->planeX * mlx->dirY - mlx->dirX * mlx->planeY);
	spr->transformX = spr->invDet * (mlx->dirY * spr->spriteX
			- mlx->dirX * spr->spriteY);
	spr->transformY = spr->invDet * (-mlx->planeY * spr->spriteX
			+ mlx->planeX * spr->spriteY);
	spr->spriteScreenX = (int)((mlx->width / 2)
			* (1 + spr->transformX / spr->transformY));
	spr->vMoveScreen = (int)(VMOVE / spr->transformY);
	spr->spriteHeight = (int)fabs((mlx->height / spr->transformY) / VDIV);
	spr->drawStartY = -spr->spriteHeight / 2 + mlx->height / 2
		+ spr->vMoveScreen;
	if (spr->drawStartY < 0)
		spr->drawStartY = 0;
	spr->drawEndY = spr->spriteHeight / 2 + mlx->height / 2 + spr->vMoveScreen;
	if (spr->drawEndY >= mlx->height)
		spr->drawEndY = mlx->height - 1;
	spr->spriteWidth = (int)fabs((mlx->height / spr->transformY) / UDIV);
	spr->drawStartX = -spr->spriteWidth / 2 + spr->spriteScreenX;
	if (spr->drawStartX < 0)
		spr->drawStartX = 0;
	spr->drawEndX = spr->spriteWidth / 2 + spr->spriteScreenX;
	if (spr->drawEndX >= mlx->width)
		spr->drawEndX = mlx->width - 1;
}

void	sprites_draw2(t_mlx *mlx, t_sprite *spr)
{
	spr->i = 0;
	spr->y = 0;
	spr->stripe = 0;
	while (spr->i < mlx->num_sprites + 1)
	{
		spr->spriteOrder[spr->i] = spr->i;
		spr->spriteDistance[spr->i] = ((mlx->posX - mlx->sprite_x[spr->i])
				* (mlx->posX - mlx->sprite_x[spr->i])
				+ (mlx->posY - mlx->sprite_y[spr->i])
				* (mlx->posY - mlx->sprite_y[spr->i]));
		spr->i++;
	}
	spr->i = 0;
}

void	sprites_draw(t_mlx *mlx)
{
	t_sprite	spr;

	sprites_draw2(mlx, &spr);
	sortSprites(spr.spriteOrder, spr.spriteDistance, mlx->num_sprites + 1);
	while (spr.i < mlx->num_sprites + 1)
	{
		sprites_draw3(mlx, &spr);
		spr.stripe = spr.drawStartX;
		while (spr.stripe < spr.drawEndX)
		{
			sprites_draw4(mlx, &spr);
		}
		spr.i++;
	}
}
