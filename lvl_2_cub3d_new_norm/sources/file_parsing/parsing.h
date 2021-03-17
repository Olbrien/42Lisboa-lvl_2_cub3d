/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:51:38 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/17 02:13:58 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_parse
{
	int			ret;

	int			r_width;
	int			r_height;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	int			f_r;
	int			f_g;
	int			f_b;
	int			c_r;
	int			c_g;
	int			c_b;
	int			index;

	int			blank_lines;
	int			size_of_map_y;
	int			max_strlen;
	int			map_has_empty_lines;
	char		**map_string;

	double		temp_pos_x;
	double		temp_pos_y;
	double		temp_dir_x;
	double		temp_dir_y;
	double		temp_plane_x;
	double		temp_plane_y;

	int			r_val;
	int			no_val;
	int			so_val;
	int			we_val;
	int			ea_val;
	int			s_val;
	int			f_val;
	int			c_val;

	int			fd;
}				t_parse;

#endif
