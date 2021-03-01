/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:38:12 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/27 21:49:29 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	images(t_mlx *mlx, t_img *img)
{
	mlx->img = mlx_xpm_file_to_image(mlx->mlx, img->open_path, &img->width,
								&img->height);

	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 640/2, 400/2);

}
