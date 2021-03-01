/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:07:07 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/01 19:01:20 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	ver_line(t_mlx *mlx, t_raycast ray, int x, int color)
{
	int	y;

	y = ray.draw_start;
	while (y <= ray.draw_end)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, color);
		y++;
	}
}

void	calc(t_mlx *mlx)
{
	int			x;
	int			color;
	t_raycast	ray;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		ray.camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
		ray.ray_dir_x = mlx->dir_x + mlx->plane_x * ray.camera_x;
		ray.ray_dir_y = mlx->dir_y + mlx->plane_y * ray.camera_x;

		ray.map_x = (int)mlx->pos_x;
		ray.map_y = (int)mlx->pos_y;

		ray.delta_dist_x = fabs(1 / ray.ray_dir_x);
		ray.delta_dist_y = fabs(1 / ray.ray_dir_y);

		ray.hit = 0;

		if (ray.ray_dir_x < 0)
		{
			ray.step_x = -1;
			ray.side_dist_x = (mlx->pos_x - ray.map_x) * ray.delta_dist_x;
		}
		else
		{
			ray.step_x = 1;
			ray.side_dist_x = (ray.map_x + 1.0 - mlx->pos_x) * ray.delta_dist_x;
		}
		if (ray.ray_dir_y < 0)
		{
			ray.step_y = -1;
			ray.side_dist_y = (mlx->pos_y - ray.map_y) * ray.delta_dist_y;
		}
		else
		{
			ray.step_y = 1;
			ray.side_dist_y = (ray.map_y + 1.0 - mlx->pos_y) * ray.delta_dist_y;
		}

		while (ray.hit == 0)
		{
			if (ray.side_dist_x < ray.side_dist_y)
			{
				ray.side_dist_x += ray.delta_dist_x;
				ray.map_x += ray.step_x;
				ray.side = 0;
			}
			else
			{
				ray.side_dist_y += ray.delta_dist_y;
				ray.map_y += ray.step_y;
				ray.side = 1;
			}
			if (world_map[ray.map_x][ray.map_y] > 0)
			{
				ray.hit = 1;
			}
		}

		if (ray.side == 0)
			ray.perp_wall_dist = (ray.map_x - mlx->pos_x + (1 - ray.step_x) / 2) / ray.ray_dir_x;
		else
			ray.perp_wall_dist = (ray.map_y - mlx->pos_y + (1 - ray.step_y) / 2) / ray.ray_dir_y;

		ray.line_height = (int)(WINDOW_HEIGHT / ray.perp_wall_dist);
		ray.draw_start = -ray.line_height / 2 + WINDOW_HEIGHT / 2;
		if (ray.draw_start < 0)
		{
			ray.draw_start = 0;
		}
		ray.draw_end = ray.line_height / 2 + WINDOW_HEIGHT / 2;
		if (ray.draw_end >= WINDOW_HEIGHT)
		{
			ray.draw_end = WINDOW_HEIGHT - 1;
		}



		if (world_map[ray.map_y][ray.map_x] == 1)
			color = RED_PIXEL;
		else if (world_map[ray.map_y][ray.map_x] == 2)
			color = GREEN_PIXEL;
		else if (world_map[ray.map_y][ray.map_x] == 3)
			color = BLUE_PIXEL;
		else if (world_map[ray.map_y][ray.map_x] == 4)
			color = WHITE_PIXEL;
		else
			color = YELLOW_PIXEL;

		if (ray.side == 1)
			color = color / 2;

		ver_line(mlx, ray, x, color);

		x++;
	}


}
