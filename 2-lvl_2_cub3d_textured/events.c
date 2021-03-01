/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:20:12 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/01 18:52:29 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/**General Events**/

int		loop_events(t_mlx *mlx)
{
	calc(mlx);

	return (0);
}

int		destroy_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);

	free(mlx->mlx);

	exit(0);
	return (0);
}

/******************/




/**Mouse Commands**/

int		left_button(int button, int x,int y, t_mlx *mlx)
{
	if (button == 1) // Left Button
	{
		printf("Left Click! At %i %i\n", x, y);
	}
	return (0);
}

int		right_button(int button, int x,int y, t_mlx *mlx)
{
	if (button == 3) // Left Button
	{
		printf("Right Click! At %i %i\n", x, y);
	}
	return (0);
}

int		button_press(int button, int x,int y, t_mlx *mlx)
{
	left_button(button, x, y, mlx);
	right_button(button, x, y, mlx);

	return (0);
}


/*******************/


/**Keyboard Press Commands**/


int		space(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Space) // Enter Key 32 or XK_space
	{
		printf("Space Key Pressed!\n");
	}
	return (0);
}

int		enter(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Return) // Enter Key 65293 or XK_Return
	{
		printf("Enter Key Pressed!\n");
	}
	return (0);
}

int		escape(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape) // Esc Key 65307 or XK_Escape
	{
		destroy_window(mlx);
	}
	return (0);
}

int		asda_press(int keycode, t_mlx *mlx)
{
	if (keycode == XK_w) // W Key 119 or XK_w
	{
		printf("W Key Pressed!\n");
		if (!world_map[(int)(mlx->pos_x + mlx->dir_x * mlx->move_speed)][(int)(mlx->pos_y)])
			mlx->pos_x += mlx->dir_x * mlx->move_speed;
		if (!world_map[(int)(mlx->pos_x)][(int)(mlx->pos_y + mlx->dir_y * mlx->move_speed)])
			mlx->pos_y += mlx->dir_y * mlx->move_speed;
	}
	else if (keycode == XK_s) // S Key 115 or XK_s
	{
		printf("S Key Pressed!\n");
		if (!world_map[(int)(mlx->pos_x - mlx->dir_x * mlx->move_speed)][(int)(mlx->pos_y)])
			mlx->pos_x -= mlx->dir_x * mlx->move_speed;
		if (!world_map[(int)(mlx->pos_x)][(int)(mlx->pos_y - mlx->dir_y * mlx->move_speed)])
			mlx->pos_y -= mlx->dir_y * mlx->move_speed;
	}
	else if (keycode == XK_a) // A Key 97 or XK_a
	{
		printf("A Key Pressed!\n");
		double oldDirX = mlx->dir_x;
		mlx->dir_x = mlx->dir_x * cos(-mlx->rot_speed) - mlx->dir_y * sin(-mlx->rot_speed);
		mlx->dir_y = oldDirX * sin(-mlx->rot_speed) + mlx->dir_y * cos(-mlx->rot_speed);
		double oldPlaneX = mlx->plane_x;
		mlx->plane_x = mlx->plane_x * cos(-mlx->rot_speed) - mlx->plane_y * sin(-mlx->rot_speed);
		mlx->plane_y = oldPlaneX * sin(-mlx->rot_speed) + mlx->plane_y * cos(-mlx->rot_speed);
	}
	else if (keycode == XK_d) // D Key 100 or XK_d
	{
		printf("D Key Pressed!\n");
	}
	return (0);
}

int		arrows_press(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Left) // Left Key 65361 or XK_Left
		printf("Left Key Pressed!\n");
	else if (keycode == XK_Right) // Right Key 65363 or XK_Right
		printf("Right Key Pressed!\n");
	return (0);
}

int		h_key_press(int keycode, t_mlx *mlx)
{
	if (keycode == XK_h) // H Key (Mouse Hide / Mouse Reveal) 104 or XK_h
	{
		printf("H Key Pressed!\n");
		if (mlx->mouse_hide == 0)
		{
			//mlx_mouse_hide(mlx->mlx, mlx->win);
			mlx->mouse_hide = 1;
		}
		else if (mlx->mouse_hide == 1)
		{
			//mlx_mouse_show(mlx->mlx, mlx->win);
			mlx->mouse_hide = 0;
		}
	}
	return (0);
}

int		key_press(int keycode, t_mlx *mlx)
{
	asda_press(keycode, mlx);
	arrows_press(keycode, mlx);

	h_key_press(keycode, mlx);

	space(keycode, mlx);
	enter(keycode, mlx);

	escape(keycode, mlx);
	return (0);
}


/***************************/

/**Keyboard Release Commands**/

int		arrows_release(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Left) // Left Key 65361 or XK_Left
		printf("Left Key Released!\n");
	else if (keycode == XK_Right) // Right Key 65363 or XK_Right
		printf("Right Key Released!\n");
	return (0);
}

int		asda_release(int keycode, t_mlx *mlx)
{
	if (keycode == XK_w) // W Key 119 or XK_w
	{
		printf("W Key Released!\n");
	}
	else if (keycode == XK_s) // S Key 115 or XK_s
	{
		printf("S Key Released!\n");
	}
	else if (keycode == XK_a) // A Key 97 or XK_a
	{
		printf("A Key Released!\n");
	}
	else if (keycode == XK_d) // D Key 100 or XK_d
	{
		printf("D Key Released!\n");
	}
	return (0);
}

int		key_release(int keycode, t_mlx *mlx)
{
	asda_release(keycode, mlx);
	arrows_release(keycode, mlx);

	return (0);
}

/*****************************/


/**Window Commands**/

int		enter_window(t_mlx *mlx)
{
	printf("You've entered the window!\n");
	return (0);
}

int		leave_window(t_mlx *mlx)
{
	printf("You've exited the window!\n");
	return (0);
}

/*******************/


/**Focus Commands**/

int		focus_in(t_mlx *mlx)
{
	printf("Focus In!\n");
	return (0);
}

int		focus_out(t_mlx *mlx)
{
	printf("Focus Out!\n");
	return (0);
}

/*******************/



void	events(t_mlx *mlx, t_img *img)
{
	//mlx_do_key_autorepeatoff(mlx->mlx);

	mlx_loop_hook(mlx->mlx, loop_events, mlx);

	mlx_hook(mlx->win, KeyPress, KeyPressMask, key_press, mlx);
	mlx_hook(mlx->win, KeyRelease, KeyReleaseMask, key_release, mlx);
	mlx_hook(mlx->win, ButtonPress, ButtonPressMask, button_press, mlx);

	mlx_hook(mlx->win, EnterNotify, EnterWindowMask, enter_window, mlx);
	mlx_hook(mlx->win, LeaveNotify, LeaveWindowMask, leave_window, mlx);

	mlx_hook(mlx->win, FocusIn, FocusChangeMask, focus_in, mlx);
	mlx_hook(mlx->win, FocusOut, FocusChangeMask, focus_out, mlx);

	mlx_hook(mlx->win, ClientMessage, NoEventMask, destroy_window, mlx);


	//mlx_do_key_autorepeaton(mlx->mlx);

}
