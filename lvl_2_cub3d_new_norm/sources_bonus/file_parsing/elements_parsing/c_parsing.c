/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:27:43 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/19 15:00:19 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_bonus.h"

static int	free_stuff_save_space(char *temp, char **array, int i, int message)
{
	free(temp);
	free_array(array, i - 1);
	return (error_message(message));
}

static int	sort_c_conditions(char *temp, char **array, int i)
{
	int	r;
	int	g;
	int	b;

	if (i != 4)
		return (free_stuff_save_space(temp, array, i, 26));
	if (array[0][0] != 'C' || array[0][1] != '\0')
		return (free_stuff_save_space(temp, array, i, 27));
	if (!check_if_string_is_digit(array[1])
		|| !check_if_string_is_digit(array[2])
		|| !check_if_string_is_digit(array[3]))
		return (free_stuff_save_space(temp, array, i, 28));
	r = ft_atoi(array[1]);
	g = ft_atoi(array[2]);
	b = ft_atoi(array[3]);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		return (free_stuff_save_space(temp, array, i, 29));
	if (count_chars(temp, ',') > 2)
		return (free_stuff_save_space(temp, array, i, 27));
	return (1);
}

int	sort_c(char *line, t_parse *parse)
{
	char	*temp;
	char	**array;
	int		i;

	if (parse->c_val > 0)
		return (error_message(38));
	temp = ft_strdup(line);
	array = ft_split_chars(temp, " ,");
	i = 0;
	while (array[i] != NULL)
		i++;
	if (!sort_c_conditions(temp, array, i))
		return (0);
	parse->c_r = ft_atoi(array[1]);
	parse->c_g = ft_atoi(array[2]);
	parse->c_b = ft_atoi(array[3]);
	free(temp);
	free_array(array, i - 1);
	parse->index++;
	parse->c_val++;
	return (1);
}
