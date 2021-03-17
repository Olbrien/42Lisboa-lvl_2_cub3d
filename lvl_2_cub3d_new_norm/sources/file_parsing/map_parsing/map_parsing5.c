/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 03:45:51 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/17 02:16:11 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"

static int	check_map_border_formula2(int validation, char **temp_map,
										int y, int x)
{
	if (temp_map[y + 1][x + 1] != 'F' && temp_map[y + 1][x + 1] != '*'
		&& temp_map[y + 1][x + 1] != '1')
		validation = 0;
	if (temp_map[y + 1][x - 1] != 'F' && temp_map[y + 1][x - 1] != '*'
		&& temp_map[y + 1][x - 1] != '1')
		validation = 0;
	if (temp_map[y - 1][x + 1] != 'F' && temp_map[y - 1][x + 1] != '*'
		&& temp_map[y - 1][x + 1] != '1')
		validation = 0;
	if (temp_map[y - 1][x - 1] != 'F' && temp_map[y - 1][x - 1] != '*'
		&& temp_map[y - 1][x - 1] != '1')
		validation = 0;
	return (validation);
}

static int	check_map_border_formula(char **temp_map, int y, int x)
{
	int	validation;

	validation = 1;
	if (temp_map[y + 1][x] != 'F' && temp_map[y + 1][x] != '*'
		&& temp_map[y + 1][x] != '1')
		validation = 0;
	if (temp_map[y - 1][x] != 'F' && temp_map[y - 1][x] != '*'
		&& temp_map[y - 1][x] != '1')
		validation = 0;
	if (temp_map[y][x + 1] != 'F' && temp_map[y][x + 1] != '*'
		&& temp_map[y][x + 1] != '1')
		validation = 0;
	if (temp_map[y][x - 1] != 'F' && temp_map[y][x - 1] != '*'
		&& temp_map[y][x - 1] != '1')
		validation = 0;
	return (check_map_border_formula2(validation, temp_map, y, x));
}

int	check_map_border_valid(t_parse *parse, char **temp_map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < parse->size_of_map_y + 4)
	{
		x = 0;
		while (x < parse->max_strlen + 5)
		{
			if (temp_map[y][x] == 'F')
			{
				if (!check_map_border_formula(temp_map, y, x))
					return (error_message(36));
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	check_map_max_strlen(t_parse *parse)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	parse->max_strlen = 0;
	while (i < parse->size_of_map_y)
	{
		max = ft_strlen(parse->map_string[i]);
		if (max > parse->max_strlen)
			parse->max_strlen = max;
		i++;
	}
}
