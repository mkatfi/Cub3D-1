/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_iantar.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:05:23 by iantar            #+#    #+#             */
/*   Updated: 2023/09/01 10:54:01 by iantar           ###   ########.fr       */
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
	int	door;
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
	int		state;
	
}					t_texter; 

typedef struct s_data
{
	t_dda	dda;
	int		check_door;
	void	*mlx;
	void	*mlx_win;
	char	**map;
	void	*img;
	char	*get_adr;
	t_texter	anim[12];
	t_texter	no;
	t_texter	so;
	t_texter	we;
	t_texter	ea;
	t_texter	door;
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
	int		input[4];
}					t_data;

#endif