/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_iantar.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:05:23 by iantar            #+#    #+#             */
/*   Updated: 2023/09/17 09:45:36 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_IANTAR_H
# define STRUCTURES_IANTAR_H

typedef struct s_dir
{
	double		x;
	double		y;
	double		angle;
}				t_dir;

typedef struct s_pos
{
	double		x;
	double		y;
}				t_pos;

typedef struct s_coor_int
{
	int			x;
	int			y;
}				t_cor_int;

typedef struct s_dist
{
	double		dx;
	double		dy;
}				t_dist;

typedef struct s_info
{
	t_cor_int	ray_map;
	t_cor_int	step;
	t_pos		dist;
}				t_info;

typedef struct s_plan
{
	double		x;
	double		y;
}				t_plan;

typedef struct s_dda
{
	double		distance;
	int			side;
	int			door;
}				t_dda;

typedef struct s_texter
{
	char		*addr;
	void		*img;
	int			bits_per_pixel;
	int			size_line;
	int			height;
	int			endian;
	int			width;
	int			state;

}				t_texter;

typedef struct s_textures
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
}				t_textures;

typedef struct s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct s_color
{
	t_rgb		floor;
	t_rgb		ceiling;
}				t_color;

typedef struct s_data
{
	t_dda		dda;
	t_color		color;
	t_textures	txt;
	int			check_door;
	void		*mlx;
	void		*mlx_win;
	char		**map;
	char		**mapm;
	void		*img;
	char		*get_adr;
	t_texter	anim[12];
	t_texter	no;
	t_texter	so;
	t_texter	we;
	t_texter	ea;
	t_texter	door;
	int			bits_per_pixel;
	int			line_length;
	int			m_width;
	int			m_height;
	double		k;
	double		v_angle;
	double		dist;
	t_pos		pos;
	t_dir		dir;
	t_plan		plan;
	char		player;
	int			input[3];
}				t_data;

#endif
