/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes_aouaziz.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:12:27 by iantar            #+#    #+#             */
/*   Updated: 2023/07/27 10:10:58 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_AOUAZIZ_H
# define INCLUDES_AOUAZIZ_H

# include "../libft/includes/libft.h"
# include "math.h"
# include "structures_aouaziz.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

//parsing file
int			ft_cub(char *c, int i);
t_cube3d	*check_File_And_Read_it(char *file);
t_cube3d	*initialize_Cube3D(t_cube3d *cube);

//reading map
void		read_File_And_Parse(t_cube3d *cube, int fd);
void		start_Map(t_cube3d *cube);
void		check_Map_Height_And_Width(char **map);
t_cube3d	*get_Map_Height(t_cube3d *cube, int fd);
t_cube3d	*get_Map_Length_And_Height(t_cube3d *cube);

//check map error
t_cube3d	*check_Map_Lines(t_cube3d *cube);
int			ft_check_char(char c);
int			check_Null_Character(char **map, int i, int j);
void		check_Zero_Surroundings(t_cube3d *cube);
void		check_Map_Not_Closed(char **map);
int			start_Map_Check(t_cube3d *cube);
void		check_First_Line(char *line);
void		check_Map_Line(char **line, int x);
int			ft_skip_new_line(char **line, int y);

// check player error
t_cube3d	*check_And_Set_Player_Position(t_cube3d *cube);
t_cube3d	*find_Player_Position(t_cube3d *cube);
void		validate_Player_Position(char **map, int i, int j);

//color and textur
t_cube3d	*cube_textur_color(t_cube3d *cube, char *line);
t_cube3d	*get_Texture(t_cube3d *cube, char *line);
t_cube3d	*get_Color(t_cube3d *cube, char *line);
t_textur	*ft_textur_lst_last(t_textur *lst);
void		ft_textur_list_add_back(t_textur **lst, t_textur *new);
t_cube3d	*add_textur_to_list(t_cube3d *cube, char *content, int type);
int			ft_lstsize_textur(t_textur *lst);

// print stract
void		print_textur(const t_textur *textur);
void		print_cube3d(const t_cube3d *cube);
void		print_str(char **str);

#endif