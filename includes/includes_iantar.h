/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes_iantar.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:03:41 by iantar            #+#    #+#             */
/*   Updated: 2023/07/27 14:47:47 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_IANTAR_H
# define INCLUDES_IANTAR_H

# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
#include "../mlx/mlx.h"
# include "../libft/includes/libft.h"
#include "structures_iantar.h"
#include "structures_aouaziz.h"
#include "macros.h"

void	ft_check_1(char **map);
void	ft_check_pos(char **map);
char	**ft_get_map(char **map, int max_len);
int		ft_check_char(char c);
void	render_map(t_data *data, int pos_x, int pos_y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_player(int i, int j, int size, t_data *data);
void	draw_disk(int x, int y, int r, t_data *data);
void	player_hooks(t_data *data);
int		key_press(int key_code, t_data *data);

#endif
