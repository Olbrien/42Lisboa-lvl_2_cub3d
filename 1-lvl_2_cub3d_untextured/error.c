/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 21:48:32 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/27 21:48:38 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_message_free(int ret, t_mlx *mlx)
{
	ret = 0;

	free(mlx->mlx);
	printf("Error\nStop trying to break my code sff.\n");
	return (ret);
}

int	error_message(int ret)
{
	ret = 0;

	printf("Error\nStop trying to break my code sff.\n");
	return (ret);
}
