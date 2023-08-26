/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_textur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:07:04 by aouaziz           #+#    #+#             */
/*   Updated: 2023/08/21 08:56:46 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes_aouaziz.h"
#include "../../includes/includes_iantar.h"
#include "../../includes/macros.h"
#include "../../includes/structures_aouaziz.h"
#include "../../includes/structures_iantar.h"

t_cube3d	*cube_textur_color(t_cube3d *cube, char *line)
{
	cube = get_Texture(cube, line);
	cube = get_Color(cube, line);
	return (cube);
}

t_cube3d	*get_Texture(t_cube3d *cube, char *line)
{
	char	**str;

	if (ft_strchr(line, '\t'))
		ft_print_error("Invalid Map - Tab Character Found\n");
	str = ft_split(line, ' ');
	if (!ft_strcmp(str[0], "NO "))
		cube = add_textur_to_list(cube, str[1], NO);
	else if (!ft_strcmp(str[0], "SO "))
		cube = add_textur_to_list(cube, str[1], SO);
	else if (!ft_strcmp(str[0], "WE "))
		cube = add_textur_to_list(cube, str[1], WE);
	else if (!ft_strcmp(str[0], "EA "))
		cube = add_textur_to_list(cube, str[1], EA);
	free_double_str(str);
	return (cube);
}

t_cube3d	*get_Color(t_cube3d *cube, char *line)
{
	char		**str;
	static int	i;

	str = ft_split(line, ' ');
	if (!ft_strncmp(str[0], "F", 2))
	{
		cube->F = ft_color_resolution(str[1]);
		i++;
	}
	else if (!ft_strncmp(str[0], "C", 2))
	{
		cube->C = ft_color_resolution(str[1]);
		i++;
	}
	//if (i > 2)
	//	ft_print_error("Invalid Color Parameter\n");
	free_double_str(str);
	return (cube);
}
