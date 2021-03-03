/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:38:36 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/02 19:38:38 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void initialize_mlx(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	j = 0;

	mlx->posX = 22.0;
	mlx->posY = 11.5;
	mlx->dirX = -1.0;
	mlx->dirY = 0.0;
	mlx->planeX = 0.0;
	mlx->planeY = 0.66;

	mlx->key_a = 0;
	mlx->key_w = 0;
	mlx->key_s = 0;
	mlx->key_d = 0;
	mlx->key_left = 0;
	mlx->key_right = 0;
	mlx->key_esc = 0;

	mlx->moveSpeed = 0.05;
	mlx->rotSpeed = 0.05;

	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			mlx->buf[i][j] = 0;
			j++;
		}
		i++;
	}
}


int	main(void)
{
	t_mlx mlx;


	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		return (error_message(0));

	initialize_mlx(&mlx);
	if (initialize_texture(&mlx) == -1)
		return (error_message(0));

	load_texture(&mlx);

	mlx.win = mlx_new_window(mlx.mlx, width, height, "IMPERIAL DOOM!!");

	mlx.img.img = mlx_new_image(mlx.mlx, width, height);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img, &mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);

	events(&mlx);

	mlx_loop(mlx.mlx);
}
