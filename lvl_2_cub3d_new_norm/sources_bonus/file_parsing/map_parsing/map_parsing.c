/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:11:51 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/17 02:23:16 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_bonus.h"

void	add_string_to_array3(char **temp, t_parse *parse)
{
	int	i;

	i = 0;
	free_array(parse->map_string, parse->size_of_map_y - 1);
	parse->map_string = malloc(sizeof(char *) * (parse->size_of_map_y + 1));
	if (parse->map_string == NULL)
		return ;
	while (i < parse->size_of_map_y + 1)
	{
		parse->map_string[i] = ft_strdup(temp[i]);
		i++;
	}
	free_array(temp, parse->size_of_map_y);
}

void	add_string_to_array2(char *line, t_parse *parse)
{
	char	**temp;
	int		i;

	i = 0;
	temp = malloc(sizeof(char *) * (parse->size_of_map_y + 1));
	if (temp == NULL)
		return ;
	while (i < parse->size_of_map_y)
	{
		temp[i] = ft_strdup(parse->map_string[i]);
		i++;
	}
	temp[i] = ft_strdup(line);
	add_string_to_array3(temp, parse);
}

void	add_string_to_array(char *line, t_parse *parse)
{
	if (parse->size_of_map_y == 0)
	{
		parse->map_string = malloc(sizeof(char *) * 1);
		if (parse->map_string == NULL)
			return ;
		parse->map_string[parse->size_of_map_y] = ft_strdup(line);
	}
	else
	{
		add_string_to_array2(line, parse);
	}
}

static int	fill_map_string(int fd_n, t_parse *parse)
{
	int		fd;
	char	*line;

	fd = fd_n;
	while (parse->ret >= 1)
	{
		parse->ret = get_next_line(fd, &line);
		if (line != NULL && line[0] == '\0')
		{
			if (parse->size_of_map_y > 0)
				parse->blank_lines++;
			free(line);
			continue ;
		}
		if (parse->blank_lines > 0)
			parse->map_has_empty_lines++;
		add_string_to_array(line, parse);
		parse->size_of_map_y++;
		free(line);
	}
	return (1);
}

int	start_parsing_map(int fd_n, t_parse *parse)
{
	parse->blank_lines = 0;
	parse->size_of_map_y = 0;
	parse->map_has_empty_lines = 0;
	if (!fill_map_string(fd_n, parse))
		return (0);
	if (parse->map_has_empty_lines > 0)
		return (error_message(31));
	if (!check_map_string_content(parse))
		return (0);
	if (!remove_map_tabs(parse))
		return (0);
	if (!check_map_borders(parse))
		return (0);
	if (parse->max_strlen < 3 || parse->size_of_map_y < 3)
		return (error_message(35));
	return (1);
}
