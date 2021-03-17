/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 01:49:19 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/17 02:25:01 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_bonus.h"

void	keys_wasd_2(t_mlx *mlx)
{
	if (mlx->key_a)
	{
		if (!mlx->worldmap[(int)(mlx->posx)][(int)(mlx->posy
				+ mlx->dirx * mlx->movespeed)])
			mlx->posx -= mlx->diry * mlx->movespeed;
		if (!mlx->worldmap[(int)(mlx->posx - mlx->diry
				* mlx->movespeed)][(int)(mlx->posy)])
			mlx->posy += mlx->dirx * mlx->movespeed;
	}
	if (mlx->key_d)
	{
		if (!mlx->worldmap[(int)(mlx->posx + mlx->diry
				* mlx->movespeed)][(int)(mlx->posy)])
			mlx->posy -= mlx->dirx * mlx->movespeed;
		if (!mlx->worldmap[(int)(mlx->posx)][(int)(mlx->posy
				- mlx->dirx * mlx->movespeed)])
			mlx->posx += mlx->diry * mlx->movespeed;
	}
}

void	keys_wasd_1(t_mlx *mlx)
{
	if (mlx->key_w)
	{
		if (!mlx->worldmap[(int)(mlx->posx + mlx->dirx
				* mlx->movespeed)][(int)(mlx->posy)])
			mlx->posx += mlx->dirx * mlx->movespeed;
		if (!mlx->worldmap[(int)(mlx->posx)][(int)(mlx->posy
				+ mlx->diry * mlx->movespeed)])
			mlx->posy += mlx->diry * mlx->movespeed;
	}
	if (mlx->key_s)
	{
		if (!mlx->worldmap[(int)(mlx->posx
				- mlx->dirx * mlx->movespeed)][(int)(mlx->posy)])
			mlx->posx -= mlx->dirx * mlx->movespeed;
		if (!mlx->worldmap[(int)(mlx->posx)][(int)(mlx->posy
				- mlx->diry * mlx->movespeed)])
			mlx->posy -= mlx->diry * mlx->movespeed;
	}
	keys_wasd_2(mlx);
}

int	key_press(int key, t_mlx *mlx)
{
	if (key == 53)
		mlx->key_esc = 1;
	else if (key == 13)
		mlx->key_w = 1;
	else if (key == 0)
		mlx->key_a = 1;
	else if (key == 1)
		mlx->key_s = 1;
	else if (key == 2)
		mlx->key_d = 1;
	else if (key == 123)
		mlx->key_left = 1;
	else if (key == 124)
		mlx->key_right = 1;
	return (0);
}

int	key_release(int key, t_mlx *mlx)
{
	if (key == 53)
		mlx->key_esc = 0;
	else if (key == 13)
		mlx->key_w = 0;
	else if (key == 0)
		mlx->key_a = 0;
	else if (key == 1)
		mlx->key_s = 0;
	else if (key == 2)
		mlx->key_d = 0;
	else if (key == 123)
		mlx->key_left = 0;
	else if (key == 124)
		mlx->key_right = 0;
	return (0);
}
