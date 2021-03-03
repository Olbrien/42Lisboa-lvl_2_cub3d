/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:26:14 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/03 02:00:17 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	main_loop(t_mlx *mlx)
{
	floor_and_ceiling(mlx);
	walls(mlx);
	sprites_draw(mlx);

	draw(mlx);

	keys_wasd_1(mlx);
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
