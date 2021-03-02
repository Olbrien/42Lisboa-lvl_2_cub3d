/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:26:14 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/02 22:41:07 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	keys_escape(t_mlx *mlx)
{
	if (mlx->key_esc)
	{
		// falta adicionar os free's e etc. Tens já na outra pasta é copy pasta.
		exit(0);
	}
}

void	keys_arrows(t_mlx *mlx)
{
	if (mlx->key_right)
	{
		double oldDirX = mlx->dirX;
		mlx->dirX = mlx->dirX * cos(-mlx->rotSpeed) - mlx->dirY * sin(-mlx->rotSpeed);
		mlx->dirY = oldDirX * sin(-mlx->rotSpeed) + mlx->dirY * cos(-mlx->rotSpeed);
		double oldPlaneX = mlx->planeX;
		mlx->planeX = mlx->planeX * cos(-mlx->rotSpeed) - mlx->planeY * sin(-mlx->rotSpeed);
		mlx->planeY = oldPlaneX * sin(-mlx->rotSpeed) + mlx->planeY * cos(-mlx->rotSpeed);
	}
	if (mlx->key_left)
	{
		double oldDirX = mlx->dirX;
		mlx->dirX = mlx->dirX * cos(mlx->rotSpeed) - mlx->dirY * sin(mlx->rotSpeed);
		mlx->dirY = oldDirX * sin(mlx->rotSpeed) + mlx->dirY * cos(mlx->rotSpeed);
		double oldPlaneX = mlx->planeX;
		mlx->planeX = mlx->planeX * cos(mlx->rotSpeed) - mlx->planeY * sin(mlx->rotSpeed);
		mlx->planeY = oldPlaneX * sin(mlx->rotSpeed) + mlx->planeY * cos(mlx->rotSpeed);
	}
}

void	keys_wasd(t_mlx *mlx)
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


int	main_loop(t_mlx *mlx)
{
	floor_and_ceiling(mlx);
	walls(mlx);
	sprites_draw(mlx);

	draw(mlx);

	keys_wasd(mlx);
	keys_arrows(mlx);
	keys_escape(mlx);
	return (0);
}


void	events(t_mlx *mlx)
{
	mlx_loop_hook(mlx->mlx, &main_loop, mlx);
	mlx_hook(mlx->win, KeyPress, KeyPressMask, &key_press, mlx);
	mlx_hook(mlx->win, KeyRelease, KeyReleaseMask, &key_release, mlx);
}
