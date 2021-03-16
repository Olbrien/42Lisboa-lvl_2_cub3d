/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 03:06:58 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/15 15:52:27 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"
#include "raycasting.h"

static void		set_header(unsigned char *header, int param)
{
	header[0] = (unsigned char)(param);
	header[1] = (unsigned char)(param >> 8);
	header[2] = (unsigned char)(param >> 16);
	header[3] = (unsigned char)(param >> 24);
}

static void		init_header(t_mlx *mlx, t_bmp *bmp)
{
	int	i;

	i = 0;
	while (i < 14)
		bmp->fileheader[i++] = 0;
	bmp->fileheader[0] = 'B';
	bmp->fileheader[1] = 'M';
	bmp->fileheader[10] = 54;
	i = 0;
	while (i < 40)
		bmp->infoheader[i++] = 0;
	bmp->infoheader[0] = 40;
	bmp->infoheader[12] = 1;
	bmp->infoheader[14] = 24;
	i = 0;
	while (i < 3)
		bmp->pad[i++] = 0;
	set_header(&bmp->fileheader[2], bmp->filesize);
	set_header(&bmp->infoheader[4], mlx->width);
	set_header(&bmp->infoheader[8], mlx->height);
	write(bmp->fd, bmp->fileheader, 14);
	write(bmp->fd, bmp->infoheader, 40);
}

static	void	draw_bmp(t_mlx *mlx, t_bmp *bmp)
{
	int	i;
	int	j;

	j = mlx->height;
	while (j >= 0)
	{
		i = mlx->width;
		while (i > 0)
		{
			write(bmp->fd, &mlx->buf[j][i], 3);
			i--;
		}
		j--;
	}
}

void			convert_bmp(t_mlx *mlx)
{
	t_bmp	bmp;

	bmp.filesize = 54 + 3 * mlx->width * mlx->height;
	bmp.img = malloc((sizeof(char) * 3 * mlx->width * mlx->height));
	ft_memset(bmp.img, 0, 3 * mlx->width * mlx->height);
	bmp.fd = open("img.bmp", O_CREAT | O_WRONLY, S_IRWXU);
	init_header(mlx, &bmp);
	draw_bmp(mlx, &bmp);
	free(bmp.img);
}
