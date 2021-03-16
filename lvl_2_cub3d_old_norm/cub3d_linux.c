/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_linux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:38:36 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/16 20:23:16 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		add_from_file_to_game2(t_mlx *mlx, t_parse *parse)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	mlx->map_width = parse->max_strlen;
	mlx->map_height = parse->size_of_map_y;
	while (y < 300)
	{
		x = 0;
		while (x < 300)
		{
			mlx->worldmap[y][x] = 1;
			x++;
		}
		y++;
	}
}

static void		add_from_file_to_game(t_mlx *mlx, t_parse *parse)
{
	mlx->num_sprites = 0;
	mlx->floor_color = create_trgb(0, parse->f_r, parse->f_g, parse->f_b);
	mlx->ceiling_color = create_trgb(0, parse->c_r, parse->c_g, parse->c_b);
	mlx->width = parse->r_width;
	mlx->height = parse->r_height;
	if (parse->r_width < 50)
		mlx->width = 50;
	else if (parse->r_width > 1920)
		mlx->width = 1920;
	if (parse->r_height < 50)
		mlx->height = 50;
	else if (parse->r_height > 1080)
		mlx->height = 1080;
	add_from_file_to_game2(mlx, parse);
	add_map_to_game(parse, mlx, 1, 0);
	mlx->posx = parse->temp_pos_x;
	mlx->posy = parse->temp_pos_y;
	mlx->dirx = parse->temp_dir_x;
	mlx->diry = parse->temp_dir_y;
	mlx->planex = parse->temp_plane_x;
	mlx->planey = parse->temp_plane_y;
}

void			initialize_values(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx->key_a = 0;
	mlx->key_w = 0;
	mlx->key_s = 0;
	mlx->key_d = 0;
	mlx->key_left = 0;
	mlx->key_right = 0;
	mlx->key_esc = 0;
	mlx->movespeed = 0.080;
	mlx->rotspeed = 0.080;
	while (i < mlx->height)
	{
		j = 0;
		while (j < mlx->width)
		{
			mlx->buf[i][j] = 0;
			j++;
		}
		i++;
	}
}

int				main2(int argc, char *argv[], t_mlx *mlx, t_parse *parse)
{
	mlx->save_bmp = 0;
	if (argc <= 1 || argc >= 4)
		return (0);
	if (argc == 2)
	{
		if (!check_file_name(argv[1]))
			return (0);
		parse->fd = open(argv[1], O_RDONLY);
		if (parse->fd == -1)
			return (0);
	}
	else if (argc == 3)
	{
		if (ft_strlen(argv[2]) != 6)
			return (0);
		if (ft_strncmp(argv[2], "--save", 6))
			return (0);
		mlx->save_bmp = 1;
		if (!check_file_name(argv[1]))
			return (0);
		parse->fd = open(argv[1], O_RDONLY);
		if (parse->fd == -1)
			return (0);
	}
	return (1);
}

int				main(int argc, char *argv[])
{
	t_mlx	mlx;
	t_parse	parse;

	mlx.is_linux = 1;
	if (!main2(argc, argv, &mlx, &parse))
		return (error_message(40));
	if (!file_validation(&parse, &mlx))
		return (free_file_with_ret(&parse));
	add_from_file_to_game(&mlx, &parse);
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		return (error_message(0));
	initialize_values(&mlx);
	if (!initialize_texture(&mlx))
		return (error_message(0));
	if (!load_texture(&mlx, &parse))
		return (free_file(&parse));
	free_file(&parse);
	mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "IMPERIAL DOOM!!");
	mlx.img.img = mlx_new_image(mlx.mlx, mlx.width, mlx.height);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img,
			&mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);
	events(&mlx);
	mlx_loop(mlx.mlx);
}
