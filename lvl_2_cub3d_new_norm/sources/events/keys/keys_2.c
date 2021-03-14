/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 01:54:13 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/12 06:22:19 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"

int	destroy_window(t_mlx *mlx)
{
	free_exit(mlx);
	exit(0);
}

void	keys_escape(t_mlx *mlx)
{
	if (mlx->key_esc)
	{
		free_exit(mlx);
		exit(0);
	}
}

void	keys_arrows2(t_mlx *mlx, double oldDirX, double oldPlaneX)
{
	if (mlx->key_left)
	{
		mlx->dirX = mlx->dirX * cos(mlx->rotSpeed)
			- mlx->dirY * sin(mlx->rotSpeed);
		mlx->dirY = oldDirX * sin(mlx->rotSpeed)
			+ mlx->dirY * cos(mlx->rotSpeed);
		mlx->planeX = mlx->planeX * cos(mlx->rotSpeed)
			- mlx->planeY * sin(mlx->rotSpeed);
		mlx->planeY = oldPlaneX * sin(mlx->rotSpeed)
			+ mlx->planeY * cos(mlx->rotSpeed);
	}
}

void	keys_arrows(t_mlx *mlx)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = mlx->dirX;
	oldPlaneX = mlx->planeX;
	if (mlx->key_right)
	{
		mlx->dirX = mlx->dirX * cos(-mlx->rotSpeed)
			- mlx->dirY * sin(-mlx->rotSpeed);
		mlx->dirY = oldDirX * sin(-mlx->rotSpeed)
			+ mlx->dirY * cos(-mlx->rotSpeed);
		mlx->planeX = mlx->planeX * cos(-mlx->rotSpeed)
			- mlx->planeY * sin(-mlx->rotSpeed);
		mlx->planeY = oldPlaneX * sin(-mlx->rotSpeed)
			+ mlx->planeY * cos(-mlx->rotSpeed);
	}
	keys_arrows2(mlx, oldDirX, oldPlaneX);
}
