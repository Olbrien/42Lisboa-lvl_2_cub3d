/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:32:34 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/01 18:51:10 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	structs_init(t_mlx *mlx, t_img *img)
{
	mlx->mouse_hide = 0;

	mlx->pos_x = 22.0;
	mlx->pos_y = 11.5;
	mlx->dir_x = -1.0;
	mlx->dir_y = 0.0;
	mlx->plane_x = 0.0;
	mlx->plane_y = 0.66;

	mlx->move_speed = 0.05;
	mlx->rot_speed = 0.05;


	img->open_path = "./images/open.xpm";
	img->open24_path = "./images/open24.xpm";
	img->open30_path = "./images/open30.xpm";
}

int	main(int argc, char *argv[])
{
	t_mlx mlx;
	t_img img;

	structs_init(&mlx, &img);

	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		return (error_message(0));

	initialize_buf(&mlx);
	initialize_texture(&mlx);

	mlx.win = mlx_new_window(mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "IMPERIAL DOOM!");
	if (mlx.win == NULL)
		return (error_message_free(0, &mlx));

	mlx.img = mlx_new_image(mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.data = (int *)mlx_get_data_addr(mlx.img, &mlx._img.bits_per_pixel, &mlx._img.size_line, &mlx._img.endian);


	events(&mlx, &img);
	//images(&mlx, &img);

	mlx_loop(mlx.mlx);
}
