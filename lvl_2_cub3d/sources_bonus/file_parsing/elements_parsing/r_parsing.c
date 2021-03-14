/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:35:51 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/14 19:08:12 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_bonus.h"

static int	sort_r_conditions(char *temp, char **array, int i)
{
	if (i != 3)
	{
		free(temp);
		free_array(array, i - 1);
		return (error_message(4));
	}
	if (array[0][0] != 'R' || array[0][1] != '\0')
	{
		free(temp);
		free_array(array, i - 1);
		return (error_message(5));
	}
	if (!check_if_string_is_digit(array[1])
		|| !check_if_string_is_digit(array[2]))
	{
		free(temp);
		free_array(array, i - 1);
		return (error_message(6));
	}
	return (1);
}

int	sort_r(char *line, t_parse *parse)
{
	char	*temp;
	char	**array;
	int		i;

	if (parse->r_val > 0)
		return (error_message(38));
	temp = ft_strdup(line);
	array = ft_split(temp, ' ');
	i = 0;
	while (array[i] != NULL)
		i++;
	if (!sort_r_conditions(temp, array, i))
		return (0);
	parse->r_width = ft_atoi(array[1]);
	parse->r_height = ft_atoi(array[2]);
	free(temp);
	free_array(array, i - 1);
	parse->index++;
	parse->r_val++;
	return (1);
}
