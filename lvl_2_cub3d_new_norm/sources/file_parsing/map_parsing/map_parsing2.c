/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 22:27:53 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/19 14:56:12 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"

static int	check_valid_values(char *map_line)
{
	int	i;

	i = 0;
	while (map_line[i] != '\0')
	{
		if (map_line[i] == '0')
			i++;
		else if (map_line[i] == '1')
			i++;
		else if (map_line[i] == '2')
			i++;
		else if (map_line[i] == 'N')
			i++;
		else if (map_line[i] == 'S')
			i++;
		else if (map_line[i] == 'W')
			i++;
		else if (map_line[i] == 'E')
			i++;
		else if (map_line[i] == ' ' || map_line[i] == '\t')
			i++;
		else
			return (0);
	}
	return (1);
}

static int	check_repeated_players(char *string, char position, int player)
{
	int	i;
	int	chr;

	i = 0;
	chr = 0;
	if (player > 0)
		return (2);
	while (string[i] != '\0')
	{
		if (string[i] == position)
			chr++;
		i++;
	}
	return (chr);
}

int	check_map_string_content(t_parse *parse)
{
	int	i;
	int	player;

	i = 0;
	player = 0;
	while (i < parse->size_of_map_y)
	{
		if (!check_valid_values(parse->map_string[i]))
			return (error_message(32));
		if (ft_strchr(parse->map_string[i], 'N'))
			player = check_repeated_players(parse->map_string[i], 'N', player);
		if (ft_strchr(parse->map_string[i], 'S'))
			player = check_repeated_players(parse->map_string[i], 'S', player);
		if (ft_strchr(parse->map_string[i], 'W'))
			player = check_repeated_players(parse->map_string[i], 'W', player);
		if (ft_strchr(parse->map_string[i], 'E'))
			player = check_repeated_players(parse->map_string[i], 'E', player);
		i++;
	}
	if (player == 0)
		return (error_message(33));
	if (player > 1)
		return (error_message(34));
	return (1);
}
