/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 06:58:32 by aouaziz           #+#    #+#             */
/*   Updated: 2023/08/15 13:55:09 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes_aouaziz.h"
#include "../../includes/includes_iantar.h"
#include "../../includes/macros.h"
#include "../../includes/structures_aouaziz.h"
#include "../../includes/structures_iantar.h"

int	ft_cub(char *c, int i)
{
	if (c[i - 1] == 'b' && c[i - 2] == 'u' && c[i - 3] == 'c' && c[i
		- 4] == '.')
		return (1);
	else
		return (0);
}

int	start_Map_Check(t_cube3d *cube)
{
	static int	i;

	if (ft_lstsize_textur(cube->textur) == 4 && cube->F != 0 && cube->C != 0
		&& i == 0)
	{
		i++;
		return (0);
	}
	else if (ft_lstsize_textur(cube->textur) == 4 && cube->F != 0
			&& cube->C != 0)
		return (1);
	return (0);
}
t_cube3d	*check_File_And_Read_it(char *file)
{
	int	fd;
	t_cube3d	*cube;

	cube = malloc(sizeof(t_cube3d));
	cube->textur = NULL;
	cube->map = malloc(sizeof(char *) * 10);
	cube->F = 0;
	cube->C = 0;
	cube->i = 0;
	fd = open(file, O_RDONLY);
	if (!ft_cub(file, ft_strlen(file)) || fd < 1)
		ft_print_error("Invalid File\n");
	cube = get_Map_Height(cube, fd);
	fd = open(file, O_RDONLY);
	read_File_And_Parse(cube, fd);
	return (cube);
}
t_cube3d	*initialize_Cube3D(t_cube3d *cube)
{
	// Set all parameters of the cube to NULL or 0
	cube->F = 0;
	cube->C = 0;
	cube->textur = NULL;
	cube->player = '\0';
	cube->x = 0;
	cube->y = 0;
	cube->m_width = 0;
	cube->m_height = 0;
	cube->len = 0;
	cube->map = NULL;
	cube->i = 0;
	return (cube);
}
