/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 01:54:13 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/14 18:29:49 by tisantos         ###   ########.fr       */
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
		mlx->planex = mlx->planex * cos(mlx->rotSpeed)
			- mlx->planey * sin(mlx->rotSpeed);
		mlx->planey = oldPlaneX * sin(mlx->rotSpeed)
			+ mlx->planey * cos(mlx->rotSpeed);
	}
}

void	keys_arrows(t_mlx *mlx)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = mlx->dirX;
	oldPlaneX = mlx->planex;
	if (mlx->key_right)
	{
		mlx->dirX = mlx->dirX * cos(-mlx->rotSpeed)
			- mlx->dirY * sin(-mlx->rotSpeed);
		mlx->dirY = oldDirX * sin(-mlx->rotSpeed)
			+ mlx->dirY * cos(-mlx->rotSpeed);
		mlx->planex = mlx->planex * cos(-mlx->rotSpeed)
			- mlx->planey * sin(-mlx->rotSpeed);
		mlx->planey = oldPlaneX * sin(-mlx->rotSpeed)
			+ mlx->planey * cos(-mlx->rotSpeed);
	}
	keys_arrows2(mlx, oldDirX, oldPlaneX);
}
