/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:36:26 by iantar            #+#    #+#             */
/*   Updated: 2023/05/24 21:20:35 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../mlx/mlx.h"
#include "math.h"
#include "../GNL/get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	void	*img;
	char	*get_adr;
}		t_data;

typedef struct s_vars
{
	int		i;
	int		j;
	int		len;
	int		hight;
	int		width;
	int		fd;
	int		x;
	int		y;
	char	*str;
}		t_vars;

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);

#endif