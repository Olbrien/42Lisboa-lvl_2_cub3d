/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:10:19 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/14 19:09:39 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

static void	free_array_int(int **array, int count)
{
	if (count == -1)
		return ;
	while (count >= 0)
	{
		free(array[count]);
		count--;
	}
	free(array);
}

int	free_file_with_ret(t_parse *parse)
{
	int		ret;
	char	*line;

	ret = get_next_line(parse->fd, &line);
	free(line);
	while (ret >= 1)
	{
		ret = get_next_line(parse->fd, &line);
		free(line);
	}
	return (free_file(parse));
}

int	free_file(t_parse *parse)
{
	if (parse->no_val >= 1)
		free(parse->no);
	if (parse->so_val >= 1)
		free(parse->so);
	if (parse->we_val >= 1 )
		free(parse->we);
	if (parse->ea_val >= 1)
		free(parse->ea);
	if (parse->s_val >= 1)
		free(parse->s);
	if (parse->size_of_map_y > 0)
		free_array(parse->map_string, parse->size_of_map_y - 1);
	return (0);
}

int	free_exit(t_mlx *mlx)
{
	free(mlx->mlx);
	if (mlx->free_world_map)
		free_array_int(mlx->worldmap, 499);
	free_array_int(mlx->texture, 10);
	return (0);
}
/*
**	free(mlx->win);
**	free(mlx->img.img);
*/
