/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:16:06 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/16 19:35:54 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"
#include "raycasting.h"

void	walls7(t_mlx *mlx, t_walls *walls)
{
	if (walls->side == 0)
	{
		walls->color = mlx->texture[walls->texnum][TEXHEIGHT
			* walls->texy + walls->texx];
		walls->color = (walls->color >> 1) & 8355711;
	}
	else if (walls->side == 1)
	{
		walls->color = mlx->texture[walls->texnum + 1][TEXHEIGHT
			* walls->texy + walls->texx];
		walls->color = (walls->color >> 1) & 8355711;
	}
	else if (walls->side == -1)
	{
		walls->color = mlx->texture[walls->texnum + 2][TEXHEIGHT
			* walls->texy + walls->texx];
		walls->color = (walls->color >> 1) & 8355711;
	}
	else if (walls->side == -2)
	{
		walls->color = mlx->texture[walls->texnum + 3][TEXHEIGHT
			* walls->texy + walls->texx];
		walls->color = (walls->color >> 1) & 8355711;
	}
}

void	walls6(t_mlx *mlx, t_walls *walls)
{
	if (walls->side == 0)
		walls->wallx = mlx->posy + walls->perpwalldist * walls->raydiry;
	else if (walls->side == 1)
		walls->wallx = mlx->posy + walls->perpwalldist * walls->raydiry;
	else if (walls->side == -1)
		walls->wallx = mlx->posx + walls->perpwalldist * walls->raydirx;
	else if (walls->side == -2)
		walls->wallx = mlx->posx + walls->perpwalldist * walls->raydirx;
	walls->wallx -= floor((walls->wallx));
	walls->texx = (int)(walls->wallx * (double)TEXWIDTH);
	if (walls->side >= 0 && walls->raydirx > 0)
		walls->texx = TEXWIDTH - walls->texx - 1;
	if (walls->side >= 0 && walls->raydirx <= 0)
		walls->texx = TEXWIDTH - walls->texx - 1;
	if (walls->side < 0 && walls->raydiry < 0)
		walls->texx = TEXWIDTH - walls->texx - 1;
	if (walls->side < 0 && walls->raydiry >= 0)
		walls->texx = TEXWIDTH - walls->texx - 1;
	walls->step = 1.0 * TEXHEIGHT / walls->lineheight;
	walls->texpos = (walls->drawstart - mlx->height / 2
			+ walls->lineheight / 2) * walls->step;
	walls->y = walls->drawstart;
}
