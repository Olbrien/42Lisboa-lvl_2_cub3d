/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_linux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 01:49:19 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/16 20:18:44 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"

int	key_press_linux(int key, t_mlx *mlx)
{
	if (key == 0xff1b)
		mlx->key_esc = 1;
	else if (key == 0x0077)
		mlx->key_w = 1;
	else if (key == 0x0061)
		mlx->key_a = 1;
	else if (key == 0x0073)
		mlx->key_s = 1;
	else if (key == 0x0064)
		mlx->key_d = 1;
	else if (key == 0xff51)
		mlx->key_left = 1;
	else if (key == 0xff53)
		mlx->key_right = 1;
	return (0);
}

int	key_release_linux(int key, t_mlx *mlx)
{
	if (key == 0xff1b)
		mlx->key_esc = 0;
	else if (key == 0x0077)
		mlx->key_w = 0;
	else if (key == 0x0061)
		mlx->key_a = 0;
	else if (key == 0x0073)
		mlx->key_s = 0;
	else if (key == 0x0064)
		mlx->key_d = 0;
	else if (key == 0xff51)
		mlx->key_left = 0;
	else if (key == 0xff53)
		mlx->key_right = 0;
	return (0);
}
