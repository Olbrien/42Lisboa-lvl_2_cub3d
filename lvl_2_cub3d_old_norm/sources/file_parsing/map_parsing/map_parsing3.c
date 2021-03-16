/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 03:09:11 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/15 15:45:52 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"

static void		remove_map_tabs4(t_parse *parse, int i, char *final)
{
	free(parse->map_string[i]);
	parse->map_string[i] = ft_strdup(final);
	free(final);
}

static void		remove_map_tabs3(t_parse *parse, int i, char *string, int len)
{
	char	*final;
	int		a;
	int		b;

	a = 0;
	b = 0;
	final = malloc(sizeof(char) * len);
	if (final == NULL)
		return ;
	while (string[a] != '\0')
	{
		if (string[a] == '\t')
		{
			final[b++] = ' ';
			final[b++] = ' ';
			final[b++] = ' ';
			final[b++] = ' ';
			a++;
		}
		else
			final[b++] = string[a++];
	}
	final[b] = '\0';
	remove_map_tabs4(parse, i, final);
}

static void		remove_map_tabs2(t_parse *parse, int i, char *string)
{
	int	tabs;
	int	a;
	int	len;

	tabs = 0;
	a = 0;
	while (string[a] != '\0')
	{
		if (string[a] == '\t')
			tabs++;
		a++;
	}
	len = ft_strlen(string) + 1 + (4 * tabs);
	remove_map_tabs3(parse, i, string, len);
}

int				remove_map_tabs(t_parse *parse)
{
	int	i;

	i = 0;
	while (i < parse->size_of_map_y)
	{
		if (ft_strchr(parse->map_string[i], '\t'))
			remove_map_tabs2(parse, i, parse->map_string[i]);
		i++;
	}
	return (1);
}
