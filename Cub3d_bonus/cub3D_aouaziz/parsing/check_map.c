/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 07:19:58 by aouaziz           #+#    #+#             */
/*   Updated: 2023/08/29 11:27:55 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes_aouaziz.h"
#include "../../includes/includes_iantar.h"
#include "../../includes/macros.h"
#include "../../includes/structures_aouaziz.h"
#include "../../includes/structures_iantar.h"

int	ft_check_char(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == 'D')
		return (0);
	return (1);
}

t_cube3d	*check_Map_Lines(t_cube3d *cube)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = cube->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1' || map[i][j] == ' ' || map[i][j] == '0' ||
				map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' ||
				map[i][j] == 'E' || map[i][j] == '\n' || map[i][j] == 'D')
				j++;
			else
				ft_print_error("Invalid Map - Unknown Character in Map\n");
		}
		i++;
	}
	cube = check_And_Set_Player_Position(cube);
	check_Zero_Surroundings(cube);
	cube = get_Map_Length_And_Height(cube);
	return (cube);
}
