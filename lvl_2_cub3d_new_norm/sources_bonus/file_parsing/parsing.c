/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:57:16 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/19 15:01:51 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

static int	sort_parsing_elements(char *line, t_parse *parse)
{
	int	validation;

	validation = 0;
	if (line != NULL && line[0] == '\0')
		return (1);
	if (!ft_strncmp(line, "R ", 2))
		validation = sort_r(line, parse);
	else if (!ft_strncmp(line, "NO", 2))
		validation = sort_no(line, parse);
	else if (!ft_strncmp(line, "SO", 2))
		validation = sort_so(line, parse);
	else if (!ft_strncmp(line, "WE", 2))
		validation = sort_we(line, parse);
	else if (!ft_strncmp(line, "EA", 2))
		validation = sort_ea(line, parse);
	else if (!ft_strncmp(line, "S ", 2))
		validation = sort_s(line, parse);
	else if (!ft_strncmp(line, "F ", 2))
		validation = sort_f(line, parse);
	else if (!ft_strncmp(line, "C ", 2))
		validation = sort_c(line, parse);
	return (validation);
}

static void	initialize_values(t_parse *parse)
{
	parse->r_val = 0;
	parse->no_val = 0;
	parse->so_val = 0;
	parse->we_val = 0;
	parse->ea_val = 0;
	parse->s_val = 0;
	parse->f_val = 0;
	parse->c_val = 0;
}

static int	start_parsing_elements(int fd_n, t_parse *parse)
{
	int		fd;
	int		ret;
	char	*line;

	initialize_values(parse);
	fd = fd_n;
	ret = get_next_line(fd, &line);
	if (!sort_parsing_elements(line, parse))
	{
		free(line);
		return (error_message(39));
	}
	free(line);
	while (ret >= 1 && parse->index != 8)
	{
		ret = get_next_line(fd, &line);
		if (!sort_parsing_elements(line, parse))
		{
			free(line);
			return (error_message(39));
		}
		free(line);
	}
	parse->ret = ret;
	return (1);
}

int	check_file_name(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (len <= 4)
		return (error_message(2));
	if (argv[len - 1] == 'b' && argv[len - 2] == 'u'
		&& argv[len - 3] == 'c' && argv[len - 4] == '.'
		&& argv[len - 5] != '.')
	{
		return (1);
	}
	return (error_message(1));
}

int	file_validation(t_parse *parse, t_mlx *mlx)
{
	int	y;

	y = 0;
	parse->index = 0;
	parse->size_of_map_y = 0;
	if (!start_parsing_elements(parse->fd, parse))
		return (0);
	if (parse->index != 8)
		return (error_message(30));
	if (!start_parsing_map(parse->fd, parse))
		return (0);
	mlx->worldmap = malloc(sizeof(int *) * 500);
	while (y < 500)
	{
		mlx->worldmap[y] = malloc(sizeof(int) * 500);
		y++;
	}
	mlx->free_world_map = 1;
	return (1);
}
