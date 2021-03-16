/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:19:12 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/16 19:36:05 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_bonus.h"
#include "raycasting.h"

void	sprites_draw4(t_mlx *mlx, t_sprite *spr)
{
	spr->texx = (int)((256 * (spr->stripe - (-spr->spritewidth / 2
						+ spr->spritescreenx))
				* TEXWIDTH / spr->spritewidth) / 256);
	if (spr->transformy > 0 && spr->stripe > 0 && spr->stripe < mlx->width
		&& spr->transformy < mlx->zbuffer[spr->stripe])
	{
		spr->y = spr->drawstarty;
		while (spr->y < spr->drawendy)
		{
			spr->d = (spr->y - spr->vmovescreen) * 256 - mlx->height
				* 128 + spr->spriteheight * 128;
			spr->texy = ((spr->d * TEXHEIGHT) / spr->spriteheight) / 256;
			spr->color = mlx->texture[spr->spriteorder[spr->i]][TEXWIDTH
				* spr->texy + spr->texx];
			if ((spr->color & 0x00FFFFFF) != 0)
				mlx->buf[spr->y][spr->stripe] = spr->color;
			spr->y++;
		}
	}
	spr->stripe++;
}

void	sprites_draw3(t_mlx *mlx, t_sprite *spr)
{
	spr->spritex = mlx->sprite_x[spr->spriteorder[spr->i]] - mlx->posx;
	spr->spritey = mlx->sprite_y[spr->spriteorder[spr->i]] - mlx->posy;
	spr->invdet = 1.0 / (mlx->planex * mlx->diry - mlx->dirx * mlx->planey);
	spr->transformx = spr->invdet * (mlx->diry * spr->spritex
			- mlx->dirx * spr->spritey);
	spr->transformy = spr->invdet * (-mlx->planey * spr->spritex
			+ mlx->planex * spr->spritey);
	spr->spritescreenx = (int)((mlx->width / 2)
			* (1 + spr->transformx / spr->transformy));
	spr->vmovescreen = (int)(VMOVE / spr->transformy);
	spr->spriteheight = (int)fabs((mlx->height / spr->transformy) / VDIV);
	spr->drawstarty = -spr->spriteheight / 2 + mlx->height / 2
		+ spr->vmovescreen;
	if (spr->drawstarty < 0)
		spr->drawstarty = 0;
	spr->drawendy = spr->spriteheight / 2 + mlx->height / 2 + spr->vmovescreen;
	if (spr->drawendy >= mlx->height)
		spr->drawendy = mlx->height - 1;
	spr->spritewidth = (int)fabs((mlx->height / spr->transformy) / UDIV);
	spr->drawstartx = -spr->spritewidth / 2 + spr->spritescreenx;
	if (spr->drawstartx < 0)
		spr->drawstartx = 0;
	spr->drawendx = spr->spritewidth / 2 + spr->spritescreenx;
	if (spr->drawendx >= mlx->width)
		spr->drawendx = mlx->width - 1;
}

void	sprites_draw2(t_mlx *mlx, t_sprite *spr)
{
	spr->i = 0;
	spr->y = 0;
	spr->stripe = 0;
	while (spr->i < mlx->num_sprites + 1)
	{
		spr->spriteorder[spr->i] = spr->i;
		spr->spritedistance[spr->i] = ((mlx->posx - mlx->sprite_x[spr->i])
				* (mlx->posx - mlx->sprite_x[spr->i])
				+ (mlx->posy - mlx->sprite_y[spr->i])
				* (mlx->posy - mlx->sprite_y[spr->i]));
		spr->i++;
	}
	spr->i = 0;
}

void	sprites_draw(t_mlx *mlx)
{
	t_sprite	spr;

	spr.i = 0;
	sprites_draw2(mlx, &spr);
	sortsprites(spr.spriteorder, spr.spritedistance, mlx->num_sprites + 1);
	while (spr.i < mlx->num_sprites + 1)
	{
		sprites_draw3(mlx, &spr);
		spr.stripe = spr.drawstartx;
		while (spr.stripe < spr.drawendx)
		{
			sprites_draw4(mlx, &spr);
		}
		spr.i++;
	}
}
