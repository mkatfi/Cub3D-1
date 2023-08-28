/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:49:31 by aouaziz           #+#    #+#             */
/*   Updated: 2023/08/21 09:14:39 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes_aouaziz.h"
#include "../../includes/includes_iantar.h"
#include "../../includes/macros.h"
#include "../../includes/structures_aouaziz.h"
#include "../../includes/structures_iantar.h"

t_cube3d	*get_Map_Height(t_cube3d *cube, int fd)
{
	char	*line;
	int		height;
	int		width;

	height = 0;
	width = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		width = ft_strlen(line);
		if (width > cube->m_width)
			cube->m_width = width;
		height++;
		free(line);
	}
	close(fd);
	cube->m_height = height;
	cube->map = (char **)ft_malloc(sizeof(char *) * (height + 1));
	cube->map[height] = NULL;
	free(line);
	return (cube);
}
void	check_Map_Height_And_Width(char **map)
{
	int	x_len;
	int	i;
	int	max_len;

	i = 0;
	while (map[i])
	{
		x_len = ft_strlen(map[i]);
		if (x_len > max_len)
			max_len = x_len;
		i++;
	}
}


void	read_File_And_Parse(t_cube3d *cube, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[0] != '\n' && i == 0)
			cube = cube_textur_color(cube, line);
		if (line[0] == '\n' && i == 0)
			continue ;
		else if (start_Map_Check(cube))
		{
			if (line[0] == '\n' && i > 0)
				ft_print_error("Invalid Map - Empty Line in Map\n");
			cube->map[i] = ft_cub_strdup(line, cube->m_width);
			i++;
		}
		free(line);
	}
	free(line);
	cube->map[i] = NULL;
	start_Map(cube);
}
t_cube3d	*get_Map_Length_And_Height(t_cube3d *cube)
{
	int	x_len;

	cube->m_height = 0;
	cube->m_width = 0;
	while (cube->map[cube->m_height])
	{
		x_len = ft_strlen(cube->map[cube->m_height]);
		if (x_len > cube->m_width)
			cube->m_width = x_len;
		cube->m_height++;
	}
	cube->m_width--;
	return (cube);
}
