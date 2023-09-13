/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:05:23 by iantar            #+#    #+#             */
/*   Updated: 2023/09/11 22:30:38 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_IANTAR_H
# define STRUCTURES_IANTAR_H

typedef struct s_dir
{
	double	x;
	double	y;
	double	angle;
}					t_dir;

typedef struct s_pos
{
	double	x;
	double	y;
}					t_pos;

typedef struct s_coor_int
{
	int	x;
	int	y;
}					cor_int;

typedef struct s_plan
{
	double	x;
	double	y;
}					t_plan;

typedef struct s_dda
{
	double	distance;
	int	side;
}					t_dda;

typedef struct s_texter
{
	char	*addr;
	void	*img;
	int		bits_per_pixel;
	int		size_line;
	int		height;
	int		endian;
	int		width;
	
}					t_texter; 

typedef struct s_textures
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}t_textures;

typedef struct s_color
{
	int	floor;
	int	ceiling;
}t_color;

typedef struct s_data
{
	t_dda	dda;
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	**mapm;
	void	*img;
	char	*get_adr;
	t_texter	no;
	t_texter	so;
	t_texter	we;
	t_texter	ea;
	int		bits_per_pixel;
	int		line_length;
	int		m_width;
	int		m_height;
	double	k;
	double	v_angle;
	double	dist;
	t_pos	pos;
	t_dir	dir;
	t_plan	plan;
	char	player;
	int		input[3];
}					t_data;

#endif