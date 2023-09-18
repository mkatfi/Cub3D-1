/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes_mandatory.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:03:41 by iantar            #+#    #+#             */
/*   Updated: 2023/09/16 20:51:06 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_MANDATORY_H
# define INCLUDES_MANDATORY_H

# include "macros.h"
# include "mlx.h"
# include "structures.h"
# include <fcntl.h>
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

void			inisilize(t_data *data, t_textures *txt);
void			ft_check_1(char **map);
void			ft_check_pos(char **map);
char			**ft_get_map(char **map, int max_len);
int				ft_check_char(char c);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			draw_player(t_pos pos, int r, t_data *data, int color);
void			draw_disk(int x, int y, int r, t_data *data);
void			player_hooks(t_data *data);
int				key_press(int key_code, t_data *data);
void			player_direction(int x, int y, double angle, t_data *data);
void			render_map(t_data *data);
void			plan_vect(t_data *data, t_pos pos, double angle, int color);
void			slow_version(t_data *data, double distance);
void			dda_version(t_data *data);
int				game_loop(t_data *data);
unsigned int	rgb_color(int r, int g, int b, int density);
void			fake_3d(t_data *data, t_dda dda, int x, int tex);
void			set_textuers(t_data *data);
void			error_mesg(char *msg);
unsigned int	get_pixel_color(t_data *data, int x, double y);
double			magnitude(double x, double y);
int				close_win(t_data *data);
int				key_up(int key_code, t_data *data);
void			rotate(double *x, double *y, double angle);
int				hit_wall(t_data *data, int key);
int				key_press(int key_code, t_data *data);
t_pos			check_moves(t_data *data, int key);
void			destroy_evrything(t_data *data);

// parcing**********************

char			*ft_strrchr(char *s, int c);
int				ft_strchr(char *str, char c);
int				ft_strcmp(const char *str1, const char *str2);
void			ft_error(char *s);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
// used in split
size_t			ft_strlen(const char *s);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *s1);
// get_next_line
char			*get_next_line(int fd);
void			*ft_calloc(size_t count, size_t size);
size_t			ft_gstrlen(const char *s);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_read(int fd, char *container);

// check
int				check_chek(char *s);
int				first_line(char *c);
int				check_newline(char *s);
char			**git_map(char *srt);
void			partition_map(char **s, t_data *p);
int				check_newline(char *s);
int				long_line(char **str);
int				ft_aray_size(char **s);
int				check_play(t_data *p);
void			check_cub(char *str);

// void cheack_map(char **str);
int				cheack_map(char **str, char c);
int				plus_espice(t_data *p);
int				rgb(int r, int g, int b);
// check_texer

int				check_txter(char **s);
void			plus_txter_and_fc(t_data *p, t_textures *txt, t_color *g);
int				check_xpm(char *str);
void			freepath(char **ptr);
int				ft_atoi(const char *str);
int				check_path(char *s);
#endif
