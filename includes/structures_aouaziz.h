/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_aouaziz.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:03:57 by iantar            #+#    #+#             */
/*   Updated: 2023/07/27 13:06:39 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_AOUAZIZ_H
# define STRUCTURES_AOUAZIZ_H

enum				e_textur
{
	EA,
	NO,
	SO,
	WE,
};

typedef struct s_textur
{
	int				type;
	char			*file;
	struct s_textur	*next;
}					t_textur;

// typedef struct s_data
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	char	**map;
// 	void	*img;
// 	char	*get_adr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		m_width;
// 	int		m_height;
// }					t_data;

typedef struct s_cube3d
{
	char			**map;
	int 			m_width;
	int 			m_height;
	char			player;
	int				x;
	int				y;
	int				len;
	int				i;
	int				F;
	int				C;
	t_textur		*textur;
}					t_cube3d;

typedef struct s_vars
{
	int				i;
	int				j;
	int				len;
	int				hight;
	int				width;
	int				fd;
	int				x;
	int				y;
	char			*str;
}					t_vars;

// typedef struct s_pos
// {
// 	int				x;
// 	int				y;
// }					t_pos;

typedef struct s_map_coord
{
	int	length;
	int	hight;
	int				x;
	int				y;
}					t_map_coord;
#endif