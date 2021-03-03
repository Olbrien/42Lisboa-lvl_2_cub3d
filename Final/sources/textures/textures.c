/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:36:27 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/03 01:39:26 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	load_image(t_mlx *info, int *texture, char *path, t_img *img)
{
	int	y;
	int	x;

	y = 0;
	x = 0;

	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);

	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_mlx *mlx)
{
	t_img	img;

	// Tu aqui tens 11 textures. Como tens 11 lá em baixo.

	load_image(mlx, mlx->texture[0], "textures/eagle.xpm", &img);
	load_image(mlx, mlx->texture[1], "textures/redbrick.xpm", &img);
	load_image(mlx, mlx->texture[2], "textures/purplestone.xpm", &img);
	load_image(mlx, mlx->texture[3], "textures/greystone.xpm", &img);
	load_image(mlx, mlx->texture[4], "textures/bluestone.xpm", &img);
	load_image(mlx, mlx->texture[5], "textures/mossy.xpm", &img);
	load_image(mlx, mlx->texture[6], "textures/wood.xpm", &img);
	load_image(mlx, mlx->texture[7], "textures/colorstone.xpm", &img);
	load_image(mlx, mlx->texture[8], "textures/barrel.xpm", &img);
	load_image(mlx, mlx->texture[9], "textures/pillar.xpm", &img);
	load_image(mlx, mlx->texture[10], "textures/greenlight.xpm", &img);
}

int		initialize_texture(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	j = 0;

	mlx->texture = (int **)malloc(sizeof(int *) * 11);
	if (mlx->texture == NULL)
		return (-1);

	while (i < 11)
	{
		mlx->texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth));
		if (mlx->texture[i] == NULL)
			return (-1);
		i++;
	}

	i = 0;

	while (i < 11)
	{
		j = 0;
		while (j < texHeight * texWidth)
		{
			mlx->texture[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}
