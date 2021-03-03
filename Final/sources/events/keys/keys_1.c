/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 01:49:19 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/03 02:04:38 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"

void	keys_arrows(t_mlx *mlx)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = mlx->dirX;
	oldPlaneX = mlx->planeX;
	if (mlx->key_right)
	{
		mlx->dirX = mlx->dirX * cos(-mlx->rotSpeed) - mlx->dirY * sin(-mlx->rotSpeed);
		mlx->dirY = oldDirX * sin(-mlx->rotSpeed) + mlx->dirY * cos(-mlx->rotSpeed);
		mlx->planeX = mlx->planeX * cos(-mlx->rotSpeed) - mlx->planeY * sin(-mlx->rotSpeed);
		mlx->planeY = oldPlaneX * sin(-mlx->rotSpeed) + mlx->planeY * cos(-mlx->rotSpeed);
	}
	if (mlx->key_left)
	{
		mlx->dirX = mlx->dirX * cos(mlx->rotSpeed) - mlx->dirY * sin(mlx->rotSpeed);
		mlx->dirY = oldDirX * sin(mlx->rotSpeed) + mlx->dirY * cos(mlx->rotSpeed);
		mlx->planeX = mlx->planeX * cos(mlx->rotSpeed) - mlx->planeY * sin(mlx->rotSpeed);
		mlx->planeY = oldPlaneX * sin(mlx->rotSpeed) + mlx->planeY * cos(mlx->rotSpeed);
	}
}

void	keys_wasd_2(t_mlx *mlx)
{
	if (mlx->key_a)
	{
		if (!worldMap[(int)(mlx->posY + mlx->dirX * mlx->moveSpeed)][(int)(mlx->posX)])
			mlx->posY -= -mlx->dirX * mlx->moveSpeed;
		if (!worldMap[(int)(mlx->posY)][(int)(mlx->posX - mlx->dirY * mlx->moveSpeed)])
			mlx->posX -= mlx->dirY * mlx->moveSpeed;
	}
	if (mlx->key_d)
	{
		if (!worldMap[(int)(mlx->posY - mlx->dirX * mlx->moveSpeed)][(int)(mlx->posX)])
			mlx->posY += -mlx->dirX * mlx->moveSpeed;
		if (!worldMap[(int)(mlx->posY)][(int)(mlx->posX + mlx->dirY * mlx->moveSpeed)])
			mlx->posX += mlx->dirY * mlx->moveSpeed;
	}
}

void	keys_wasd_1(t_mlx *mlx)
{
	if (mlx->key_w)
	{
		if (!worldMap[(int)(mlx->posX + mlx->dirX * mlx->moveSpeed)][(int)(mlx->posY)])
			mlx->posX += mlx->dirX * mlx->moveSpeed;
		if (!worldMap[(int)(mlx->posX)][(int)(mlx->posY + mlx->dirY * mlx->moveSpeed)])
			mlx->posY += mlx->dirY * mlx->moveSpeed;
	}
	if (mlx->key_s)
	{
		if (!worldMap[(int)(mlx->posX - mlx->dirX * mlx->moveSpeed)][(int)(mlx->posY)])
			mlx->posX -= mlx->dirX * mlx->moveSpeed;
		if (!worldMap[(int)(mlx->posX)][(int)(mlx->posY - mlx->dirY * mlx->moveSpeed)])
			mlx->posY -= mlx->dirY * mlx->moveSpeed;
	}
	keys_wasd_2(mlx);
}

int		key_press(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
		mlx->key_esc = 1;
	else if (key == XK_w)
		mlx->key_w = 1;
	else if (key == XK_a)
		mlx->key_a = 1;
	else if (key == XK_s)
		mlx->key_s = 1;
	else if (key == XK_d)
		mlx->key_d = 1;
	else if (key == XK_Left)
		mlx->key_left = 1;
	else if (key == XK_Right)
		mlx->key_right = 1;
	return (0);
}

int		key_release(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
		mlx->key_esc = 0;
	else if (key == XK_w)
		mlx->key_w = 0;
	else if (key == XK_a)
		mlx->key_a = 0;
	else if (key == XK_s)
		mlx->key_s = 0;
	else if (key == XK_d)
		mlx->key_d = 0;
	else if (key == XK_Left)
		mlx->key_left = 0;
	else if (key == XK_Right)
		mlx->key_right = 0;
	return (0);
}
