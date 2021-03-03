/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 01:54:13 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/03 01:55:05 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"

void	keys_escape(t_mlx *mlx)
{
	if (mlx->key_esc)
	{
		// falta adicionar os free's e etc. Tens já na outra pasta é copy pasta.
		exit(0);
	}
}
