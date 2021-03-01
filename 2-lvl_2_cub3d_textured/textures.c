/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:30:25 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/01 18:06:28 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_texture(t_mlx *mlx)
{
	int x;
	int y;
	int xorcolor;
	int ycolor;
	int xycolor;

	x = 0;
	y = 0;

	while (x < 8)
	{
		y = 0;
		while (y < TEX_HEIGHT * TEX_WIDTH)
		{
			mlx->texture[x][y] = 0;
			y++;
		}
		x++;
	}

	x = 0;
	y = 0;

	while (x < TEX_WIDTH)
	{
		y = 0;
		while (y < TEX_HEIGHT)
		{
			xorcolor = (x * 256 / TEX_WIDTH) ^ (y * 256 / TEX_HEIGHT);
			ycolor = y * 256 / TEX_HEIGHT;
			xycolor = y * 128 / TEX_HEIGHT + x * 128 / TEX_WIDTH;

			mlx->texture[0][TEX_WIDTH * y + x] = 65536 * 254 * (x != y && x != TEX_WIDTH - y); //flat red texture with black cross
			mlx->texture[1][TEX_WIDTH * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
			mlx->texture[2][TEX_WIDTH * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
			mlx->texture[3][TEX_WIDTH * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
			mlx->texture[4][TEX_WIDTH * y + x] = 256 * xorcolor; //xor green
			mlx->texture[5][TEX_WIDTH * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
			mlx->texture[6][TEX_WIDTH * y + x] = 65536 * ycolor; //red gradient
			mlx->texture[7][TEX_WIDTH * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture

			y++;
		}
		x++;
	}
}



void	initialize_buf(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	j = 0;
	mlx->buf = (int **)malloc(sizeof(int *) * WINDOW_HEIGHT);
	if (mlx->buf == NULL)
		return ;

	while (i < WINDOW_HEIGHT)
	{
		mlx->buf[i] = (int *)malloc(sizeof(int) * WINDOW_WIDTH);
		if (mlx->buf[i] == NULL)
			return ;
		i++;
	}
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			mlx->buf[i][j] = 0;
			j++;
		}
		i++;
	}




}
