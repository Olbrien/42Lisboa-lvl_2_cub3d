/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 02:26:23 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/14 20:27:38 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_bonus.h"
#include "raycasting.h"

void	draw(t_mlx *mlx)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (y < mlx->height)
	{
		x = 0;
		while (x < mlx->width)
		{
			mlx->img.data[y * mlx->width + x] = mlx->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	mlx_string_put(mlx->mlx, mlx->win, 20, 20, 0x12FF23,
		"Press <- and -> at same time for Quake Vision!");
	mlx_string_put(mlx->mlx, mlx->win, mlx->width / 2 - 49,
		mlx->height - 20, 0xFF1223, "LIFE [##################]");
}
