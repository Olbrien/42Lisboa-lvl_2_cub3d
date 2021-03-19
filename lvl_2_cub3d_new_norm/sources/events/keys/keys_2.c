/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 01:54:13 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/19 14:56:38 by tisantos         ###   ########.fr       */
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

void	keys_arrows2(t_mlx *mlx, double olddirx, double oldplanex)
{
	if (mlx->key_left)
	{
		mlx->dirx = mlx->dirx * cos(mlx->rotspeed)
			- mlx->diry * sin(mlx->rotspeed);
		mlx->diry = olddirx * sin(mlx->rotspeed)
			+ mlx->diry * cos(mlx->rotspeed);
		mlx->planex = mlx->planex * cos(mlx->rotspeed)
			- mlx->planey * sin(mlx->rotspeed);
		mlx->planey = oldplanex * sin(mlx->rotspeed)
			+ mlx->planey * cos(mlx->rotspeed);
	}
}

void	keys_arrows(t_mlx *mlx)
{
	double	olddirx;
	double	oldplanex;

	olddirx = mlx->dirx;
	oldplanex = mlx->planex;
	if (mlx->key_right)
	{
		mlx->dirx = mlx->dirx * cos(-mlx->rotspeed)
			- mlx->diry * sin(-mlx->rotspeed);
		mlx->diry = olddirx * sin(-mlx->rotspeed)
			+ mlx->diry * cos(-mlx->rotspeed);
		mlx->planex = mlx->planex * cos(-mlx->rotspeed)
			- mlx->planey * sin(-mlx->rotspeed);
		mlx->planey = oldplanex * sin(-mlx->rotspeed)
			+ mlx->planey * cos(-mlx->rotspeed);
	}
	keys_arrows2(mlx, olddirx, oldplanex);
}
