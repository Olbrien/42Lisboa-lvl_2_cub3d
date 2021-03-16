/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:16:27 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/15 16:13:06 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_bonus.h"

static int	free_stuff_save_space(char *temp, char **array, int i, int message)
{
	free(temp);
	free_array(array, i - 1);
	return (error_message(message));
}

static int	sort_no_conditions(char *temp, char **array, int i)
{
	int		len;
	char	*extension;

	if (i != 2)
		return (free_stuff_save_space(temp, array, i, 7));
	if (array[0][0] != 'N' || array[0][1] != 'O' || array[0][2] != '\0')
		return (free_stuff_save_space(temp, array, i, 8));
	extension = array[1];
	len = ft_strlen(extension);
	if (extension[len - 1] == 'm' && extension[len - 2] == 'p'
		&& extension[len - 3] == 'x' && extension[len - 4] == '.'
		&& extension[len - 5] != '.')
		return (1);
	else
		return (free_stuff_save_space(temp, array, i, 9));
	return (1);
}

int			sort_no(char *line, t_parse *parse)
{
	char	*temp;
	char	**array;
	int		i;

	if (parse->no_val > 0)
		return (error_message(38));
	temp = ft_strdup(line);
	array = ft_split(temp, ' ');
	i = 0;
	while (array[i] != NULL)
		i++;
	if (!sort_no_conditions(temp, array, i))
		return (0);
	parse->no = ft_strdup(array[1]);
	free(temp);
	free_array(array, i - 1);
	parse->index++;
	parse->no_val++;
	return (1);
}
