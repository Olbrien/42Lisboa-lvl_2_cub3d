/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:16:06 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/12 21:16:21 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"
#include "raycasting.h"

void	walls7(t_mlx *mlx, t_walls *walls)
{
	if (walls->side == 0)
	{
		walls->color = mlx->texture[walls->texNum][TEXHEIGHT
			* walls->texY + walls->texX];
		walls->color = (walls->color >> 1) & 8355711;
	}
	else if (walls->side == 1)
	{
		walls->color = mlx->texture[walls->texNum + 1][TEXHEIGHT
			* walls->texY + walls->texX];
		walls->color = (walls->color >> 1) & 8355711;
	}
	else if (walls->side == -1)
	{
		walls->color = mlx->texture[walls->texNum + 2][TEXHEIGHT
			* walls->texY + walls->texX];
		walls->color = (walls->color >> 1) & 8355711;
	}
	else if (walls->side == -2)
	{
		walls->color = mlx->texture[walls->texNum + 3][TEXHEIGHT
			* walls->texY + walls->texX];
		walls->color = (walls->color >> 1) & 8355711;
	}
}

void	walls6(t_mlx *mlx, t_walls *walls)
{
	if (walls->side == 0)
		walls->wallX = mlx->posY + walls->perpWallDist * walls->rayDirY;
	else if (walls->side == 1)
		walls->wallX = mlx->posY + walls->perpWallDist * walls->rayDirY;
	else if (walls->side == -1)
		walls->wallX = mlx->posX + walls->perpWallDist * walls->rayDirX;
	else if (walls->side == -2)
		walls->wallX = mlx->posX + walls->perpWallDist * walls->rayDirX;
	walls->wallX -= floor((walls->wallX));
	walls->texX = (int)(walls->wallX * (double)TEXWIDTH);
	if (walls->side >= 0 && walls->rayDirX > 0)
		walls->texX = TEXWIDTH - walls->texX - 1;
	if (walls->side >= 0 && walls->rayDirX <= 0)
		walls->texX = TEXWIDTH - walls->texX - 1;
	if (walls->side < 0 && walls->rayDirY < 0)
		walls->texX = TEXWIDTH - walls->texX - 1;
	if (walls->side < 0 && walls->rayDirY >= 0)
		walls->texX = TEXWIDTH - walls->texX - 1;
	walls->step = 1.0 * TEXHEIGHT / walls->lineHeight;
	walls->texPos = (walls->drawStart - mlx->height / 2
			+ walls->lineHeight / 2) * walls->step;
	walls->y = walls->drawStart;
}
