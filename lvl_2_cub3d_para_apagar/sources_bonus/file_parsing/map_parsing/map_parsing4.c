/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:03:14 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/14 19:08:33 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_bonus.h"

char	*fill_line_with_map_and_f(t_parse *parse, char *temp_map, int map_line)
{
	int	i;
	int	a;
	int	max_strlen;

	i = 0;
	a = 0;
	max_strlen = parse->max_strlen + 4;
	temp_map = malloc(sizeof(char) * max_strlen + 1);
	if (temp_map == NULL)
		return (NULL);
	temp_map[i++] = '*';
	temp_map[i++] = 'F';
	while (parse->map_string[map_line][a] != '\0')
	{
		if (parse->map_string[map_line][a] == ' ')
			temp_map[i++] = 'F';
		else
			temp_map[i++] = parse->map_string[map_line][a];
		a++;
	}
	while (i < max_strlen - 1)
		temp_map[i++] = 'F';
	temp_map[i++] = '*';
	temp_map[i++] = '\0';
	return (temp_map);
}

char	*fill_line_stars_and_f(t_parse *parse, char *temp_map)
{
	int	i;
	int	max_strlen;

	i = 1;
	max_strlen = parse->max_strlen + 4;
	temp_map = malloc(sizeof(char) * max_strlen + 1);
	if (temp_map == NULL)
		return (NULL);
	temp_map[0] = '*';
	while (i < max_strlen - 1)
	{
		temp_map[i] = 'F';
		i++;
	}
	temp_map[i++] = '*';
	temp_map[i] = '\0';
	return (temp_map);
}

char	*fill_line_with_stars(t_parse *parse, char *temp_map)
{
	int	i;
	int	max_strlen;

	i = 0;
	max_strlen = parse->max_strlen + 4;
	temp_map = malloc(sizeof(char) * max_strlen + 1);
	if (temp_map == NULL)
		return (NULL);
	while (i < max_strlen)
	{
		temp_map[i] = '*';
		i++;
	}
	temp_map[i] = '\0';
	return (temp_map);
}

int	fill_map_with_f_and_stars_check_border(t_parse *parse)
{
	char	**temp_map;
	int		line_send;

	line_send = 2;
	temp_map = malloc(sizeof(char *) * (parse->size_of_map_y + 4));
	if (temp_map == NULL)
		return (0);
	temp_map[0] = fill_line_with_stars(parse, temp_map[0]);
	temp_map[1] = fill_line_stars_and_f(parse, temp_map[1]);
	while (line_send < parse->size_of_map_y + 2)
	{
		temp_map[line_send] = fill_line_with_map_and_f(parse,
				temp_map[line_send], line_send - 2);
		line_send++;
	}
	temp_map[line_send] = fill_line_stars_and_f(parse, temp_map[line_send]);
	line_send++;
	temp_map[line_send] = fill_line_with_stars(parse, temp_map[line_send]);
	if (!check_map_border_valid(parse, temp_map))
	{
		free_array(temp_map, line_send);
		return (0);
	}
	free_array(temp_map, line_send);
	return (1);
}

int	check_map_borders(t_parse *parse)
{
	check_map_max_strlen(parse);
	if (!fill_map_with_f_and_stars_check_border(parse))
		return (0);
	return (1);
}
