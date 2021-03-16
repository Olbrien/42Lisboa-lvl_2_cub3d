/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:50:51 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/15 15:25:44 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_array(char **array, int count)
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

int		check_if_string_is_digit(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (ft_isdigit(string[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int		count_chars(char *str, char c)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			a++;
		i++;
	}
	return (a);
}

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
