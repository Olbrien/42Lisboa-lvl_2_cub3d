/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 07:14:08 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/17 02:10:36 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	get_sprite_locations(t_mlx *mlx, int x, int y)
{
	mlx->worldmap[y][x] = 0;
	mlx->sprite_x[mlx->num_sprites] = y + 0.5;
	mlx->sprite_y[mlx->num_sprites] = x + 0.5;
	mlx->sprite_texture[mlx->num_sprites] = 10;
	mlx->num_sprites++;
}

static void	get_player_pos_and_dir2(t_parse *parse, char position)
{
	if (position == 'E')
	{
		parse->temp_dir_x = 0.0;
		parse->temp_dir_y = 1.0;
		parse->temp_plane_x = 0.66;
		parse->temp_plane_y = 0;
	}
	else if (position == 'W')
	{
		parse->temp_dir_x = 0.0;
		parse->temp_dir_y = -1.0;
		parse->temp_plane_x = -0.66;
		parse->temp_plane_y = 0;
	}
}

static void	get_player_pos_and_dir(t_parse *parse, int x, int y, char position)
{
	parse->temp_pos_x = y + 0.5;
	parse->temp_pos_y = x + 0.5;
	if (position == 'N')
	{
		parse->temp_dir_x = -1.0;
		parse->temp_dir_y = 0.0;
		parse->temp_plane_x = 0.0;
		parse->temp_plane_y = 0.66;
	}
	else if (position == 'S')
	{
		parse->temp_dir_x = 1.0;
		parse->temp_dir_y = 0;
		parse->temp_plane_x = 0.0;
		parse->temp_plane_y = -0.66;
	}
	else
		get_player_pos_and_dir2(parse, position);
}

static void	add_map_to_game2(t_parse *parse, t_mlx *mlx, int x, int y)
{
	if (parse->map_string[y - 1][x - 1] == ' ')
		mlx->worldmap[y][x] = 1;
	else if (parse->map_string[y - 1][x - 1] == 'N'
		|| parse->map_string[y - 1][x - 1] == 'S'
		|| parse->map_string[y - 1][x - 1] == 'E'
		|| parse->map_string[y - 1][x - 1] == 'W')
	{
		mlx->worldmap[y][x] = 0;
		get_player_pos_and_dir(parse, x, y,
			parse->map_string[y - 1][x - 1]);
	}
	else if (parse->map_string[y - 1][x - 1] == '2')
		get_sprite_locations(mlx, x, y);
	else
		mlx->worldmap[y][x] = parse->map_string[y - 1][x - 1] - '0';
}

void	add_map_to_game(t_parse *parse, t_mlx *mlx, int y, int l)
{
	int	x;

	x = 1;
	while (y < parse->size_of_map_y)
	{
		x = 1;
		l = ft_strlen(parse->map_string[y - 1]);
		while (x < l)
		{
			add_map_to_game2(parse, mlx, x, y);
			x++;
		}
		while (x < parse->max_strlen)
			mlx->worldmap[y][x++] = 1;
		y++;
	}
}
