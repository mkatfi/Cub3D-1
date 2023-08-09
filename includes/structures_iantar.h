/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_iantar.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:05:23 by iantar            #+#    #+#             */
/*   Updated: 2023/08/09 16:09:56 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_IANTAR_H
# define STRUCTURES_IANTAR_H

typedef struct s_dir
{
	float	x;
	float	y;
	float	angle;
}					t_dir;

typedef struct s_pos
{
	float	x;
	float	y;
}					t_pos;

typedef struct s_plan
{
	float	x;
	float	y;
}					t_plan;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	void	*img;
	char	*get_adr;
	int		bits_per_pixel;
	int		line_length;
	int		m_width;
	int		m_height;
	float	k;
	float	v_angle;
	t_pos	pos;
	t_dir	dir;
	t_plan	plan;
	// float	pos_x;
	// float	pos_y;
}					t_data;


#endif