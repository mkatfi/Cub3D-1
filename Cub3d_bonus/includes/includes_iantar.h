/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes_iantar.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:03:41 by iantar            #+#    #+#             */
/*   Updated: 2023/08/30 10:50:42 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_IANTAR_H
# define INCLUDES_IANTAR_H

# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx.h"
# include "../libft/includes/libft.h"
# include "structures_iantar.h"
# include "structures_aouaziz.h"
# include "macros.h"

void	ft_check_1(char **map);
void	ft_check_pos(char **map);
char	**ft_get_map(char **map, int max_len);
int		ft_check_char(char c);
//void	render_map(t_data *data, double pos_x, double pos_y, double angle);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
//void	draw_player(double i, double j, int size, t_data *data);
void	draw_dirction(t_data *data, t_pos pos, t_dir dir, double anglel, int color);
void	draw_disk(int x, int y, int r, t_data *data);
void	player_hooks(t_data *data);
int		key_press(int key_code, t_data *data);
void	player_direction(int x, int y, double angle, t_data *data);
void	render_map(t_data *data);
void	dir_vect(t_data *data, t_pos pos, t_dir dir, double angle, int color);
void	plan_vect(t_data *data, t_pos pos, double angle, int color);
void	slow_version(t_data *data, double distance);
void	dda_version(t_data *data);
int	    game_loop(t_data *data);
void	line(t_data *data, double x, double y, double angle, double len);
unsigned int	    rgb_color(int r, int g, int b, int density);
void    fake_3d(t_data *data, t_dda dda, int x, int tex);
void	set_textuers(t_data *data);
void	error_mesg(char *msg);
unsigned int	get_pixel_color(t_data *data, int x, double y);
void	mini_map(t_data *data);
void	draw_square(t_data *data, int i, int j, int color);
void	draw_player(t_data *data, t_pos pos, int color);
void    animation(t_data *data);

#endif
