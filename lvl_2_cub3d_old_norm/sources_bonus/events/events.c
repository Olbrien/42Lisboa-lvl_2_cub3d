/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:26:14 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/16 20:45:10 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

int		main_loop(t_mlx *mlx)
{
	floor_and_ceiling(mlx);
	walls(mlx);
	sprites_draw(mlx);
	draw(mlx);
	if (mlx->save_bmp)
	{
		convert_bmp(mlx);
		free_exit(mlx);
		exit(0);
	}
	keys_wasd_1(mlx);
	keys_arrows(mlx);
	keys_escape(mlx);
	return (0);
}

void	events(t_mlx *mlx)
{
	mlx_loop_hook(mlx->mlx, &main_loop, mlx);
	if (mlx->is_linux == 0)
	{
		mlx_hook(mlx->win, KEYPRESS, KEYPRESSMASK, &key_press, mlx);
		mlx_hook(mlx->win, KEYRELEASE, KEYRELEASEMASK, &key_release, mlx);
		mlx_hook(mlx->win, 17, 0, &destroy_window, mlx);
	}
	else
	{
		mlx_hook(mlx->win, KEYPRESS, KEYPRESSMASK, &key_press_linux, mlx);
		mlx_hook(mlx->win, KEYRELEASE, KEYRELEASEMASK, &key_release_linux, mlx);
		mlx_hook(mlx->win, CLIENTMESSAGE, 0, &destroy_window, mlx);
	}
}
