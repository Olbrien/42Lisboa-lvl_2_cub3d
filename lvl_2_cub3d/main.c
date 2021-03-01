/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:32:34 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/01 00:05:14 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	structs_init(t_mlx *mlx, t_img *img)
{
	mlx->mouse_hide = 0;

	mlx->pos_x = 12;
	mlx->pos_y = 5;
	mlx->dir_x = -1;
	mlx->dir_y = 0;
	mlx->plane_x = 0;
	mlx->plane_y = 0.66;
	mlx->time = 0;
	mlx->oldTime = 0;
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

	mlx.win = mlx_new_window(mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "IMPERIAL DOOM!");
	if (mlx.win == NULL)
		return (error_message_free(0, &mlx));

	events(&mlx, &img);
	//images(&mlx, &img);

	mlx_loop(mlx.mlx);
}
