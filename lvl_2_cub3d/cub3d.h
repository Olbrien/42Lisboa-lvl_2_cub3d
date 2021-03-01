/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:33:10 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/28 23:10:39 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	WINDOW_WIDTH 640
#define	WINDOW_HEIGHT 480

#define MAP_WIDTH 24
#define MAP_HEIGHT 24

#define	RED_PIXEL 0xFF0000
#define	GREEN_PIXEL 0x00FF00
#define	BLUE_PIXEL 0x0000FF
#define WHITE_PIXEL 0xFFFFFF
#define YELLOW_PIXEL 0xFFFF00
#define PINK_PIXEL 0xFFC0CB


typedef struct s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;

	double				pos_x;			// Position vector of the player.
	double				pos_y;			//
	double				dir_x;			// Directon of the player.
	double				dir_y;			//
	double				plane_x;		// Camera plane of the player.
	double				plane_y;		//
	double				move_speed;		// Movement Speed
	double				rot_speed;		// Rotation Speed


	double				time;			// Time of current frame.
	double				oldTime;		// Time of old frame.

	int					mouse_hide;


}				t_mlx;

typedef struct s_raycast
{
	double				camera_x;		// Cordinate of the camera.
	double				ray_dir_x;		// Direction of Ray.
	double				ray_dir_y;		//

	int					map_x;			// Which box of the map we're in.
	int					map_y;			//

	double				side_dist_x;	// Length of ray from current position to next x or y-side.
	double				side_dist_y;	//
	double				delta_dist_x;	// Length of ray from one x or y-side to next x or y-side.
	double				delta_dist_y;	//
	double				perp_wall_dist;	//

	int					step_x;			// What direction to step in x or y-direction (either +1 or -1).
	int					step_y;			//

	int					hit;			// Was there a wall hit?
	int					side;			// Was a NS or a EW wall hit?

	int					line_height;	// Height of the line.
	int					draw_start;		// Lowest pixel fill.
	int					draw_end;		// Highest pixel fill.
}				t_raycast;


typedef struct s_img
{
	char				*addr;

	char				*open_path;
	char				*open24_path;
	char				*open30_path;

	int					width;
	int					height;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}				t_img;


void			events(t_mlx *mlx, t_img *img);
void			images(t_mlx *mlx, t_img *img);

int				world_map[MAP_WIDTH][MAP_HEIGHT];

void			raycasting(t_mlx *mlx);

int				error_message(int ret);
int				error_message_free(int ret, t_mlx *mlx);


#endif
