/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_iantar.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:05:23 by iantar            #+#    #+#             */
/*   Updated: 2023/07/27 13:26:25 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_IANTAR_H
# define STRUCTURES_IANTAR_H

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
	float	pos_x;
	float	pos_y;
}					t_data;

typedef struct s_pos
{
	int	x;
	int	y;
}					t_pos;

#endif