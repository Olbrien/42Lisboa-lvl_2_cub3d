/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:36:27 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/17 02:10:24 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	load_image(t_mlx *info, int *texture, char *path, t_img *img)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width,
			&img->img_height);
	if (img->img == NULL)
		exit(error_message(37));
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l,
			&img->endian);
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
	return (1);
}

int	load_texture(t_mlx *mlx, t_parse *parse)
{
	t_img	img;

	if (!load_image(mlx, mlx->texture[0], parse->no, &img))
		return (0);
	if (!load_image(mlx, mlx->texture[1], parse->so, &img))
		return (0);
	if (!load_image(mlx, mlx->texture[2], parse->we, &img))
		return (0);
	if (!load_image(mlx, mlx->texture[3], parse->ea, &img))
		return (0);
	if (!load_image(mlx, mlx->texture[4], "textures/bluestone.xpm", &img))
		return (0);
	if (!load_image(mlx, mlx->texture[5], "textures/mossy.xpm", &img))
		return (0);
	if (!load_image(mlx, mlx->texture[6], "textures/wood.xpm", &img))
		return (0);
	if (!load_image(mlx, mlx->texture[7], "textures/colorstone.xpm", &img))
		return (0);
	if (!load_image(mlx, mlx->texture[8], "textures/barrel.xpm", &img))
		return (0);
	if (!load_image(mlx, mlx->texture[9], "textures/pillar.xpm", &img))
		return (0);
	if (!load_image(mlx, mlx->texture[10], parse->s, &img))
		return (0);
	return (1);
}

void	initialize_texture2(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 11)
	{
		j = 0;
		while (j < TEXHEIGHT * TEXWIDTH)
		{
			mlx->texture[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	initialize_texture(t_mlx *mlx)
{
	int	i;

	i = 0;
	mlx->texture = (int **)malloc(sizeof(int *) * 11);
	if (mlx->texture == NULL)
		return (0);
	while (i < 11)
	{
		mlx->texture[i] = (int *)malloc(sizeof(int) * (TEXHEIGHT * TEXWIDTH));
		if (mlx->texture[i] == NULL)
			return (0);
		i++;
	}
	initialize_texture2(mlx);
	return (1);
}
