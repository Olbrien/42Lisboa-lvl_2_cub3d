/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:33:10 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/14 06:26:41 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./sources/get_next_line/get_next_line.h"
# include "./sources/libft/libft.h"
# include "./sources/file_parsing/parsing.h"
# include "./sources/events/events.h"

# define TEXWIDTH 64
# define TEXHEIGHT 64

# define UDIV 1
# define VDIV 1
# define VMOVE 0.0

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0x00FF00
# define BLUE_PIXEL 0x0000FF
# define WHITE_PIXEL 0xFFFFFF
# define YELLOW_PIXEL 0xFFFF00
# define PINK_PIXEL 0xFFC0CB

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	int		key_a;
	int		key_w;
	int		key_s;
	int		key_d;
	int		key_left;
	int		key_right;
	int		key_esc;
	int		buf[1245][1245];
	double	zBuffer[5000];
	int		**texture;
	double	moveSpeed;
	double	rotSpeed;
	int		map_width;
	int		map_height;
	int		width;
	int		height;
	int		free_world_map;
	int		**worldMap;
	int		num_sprites;
	double	sprite_x[500];
	double	sprite_y[500];
	int		sprite_texture[500];
	int		floor_color;
	int		ceiling_color;
	int		save_bmp;
}				t_mlx;

int		file_validation(t_parse *parse, t_mlx *mlx);

int		check_file_name(char *argv);

int		start_parsing_map(int fd_n, t_parse *parse);
int		check_map_string_content(t_parse *parse);
int		remove_map_tabs(t_parse *parse);
int		check_map_borders(t_parse *parse);
void	check_map_max_strlen(t_parse *parse);
int		check_map_border_valid(t_parse *parse, char **temp_map);

int		sort_r(char *line, t_parse *parse);
int		sort_no(char *line, t_parse *parse);
int		sort_so(char *line, t_parse *parse);
int		sort_we(char *line, t_parse *parse);
int		sort_ea(char *line, t_parse *parse);
int		sort_s(char *line, t_parse *parse);
int		sort_f(char *line, t_parse *parse);
int		sort_c(char *line, t_parse *parse);

int		error_message(int message);

int		free_file(t_parse *parse);
int		free_file_with_ret(t_parse *parse);
int		free_exit(t_mlx *mlx);

char	**ft_split_chars(char const *s, const char *delimiters);
int		check_if_string_is_digit(char *string);
int		count_chars(char *str, char c);
void	free_array(char **array, int count);
int		create_trgb(int t, int r, int g, int b);

void	add_map_to_game(t_parse *parse, t_mlx *mlx, int y, int l);

int		initialize_texture(t_mlx *mlx);
int		load_texture(t_mlx *mlx, t_parse *parse);

void	events(t_mlx *mlx);
int		key_release(int key, t_mlx *mlx);
int		key_press(int key, t_mlx *mlx);

void	floor_and_ceiling(t_mlx *mlx);
void	walls(t_mlx *mlx);
void	sprites_draw(t_mlx *mlx);
void	draw(t_mlx *info);

void	convert_bmp(t_mlx *mlx);

void	keys_wasd_1(t_mlx *mlx);
void	keys_arrows(t_mlx *mlx);
void	keys_escape(t_mlx *mlx);

int		destroy_window(t_mlx *mlx);

#endif
