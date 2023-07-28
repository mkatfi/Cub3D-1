/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:14:33 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/27 10:35:50 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes_aouaziz.h"
#include "../../includes/includes_iantar.h"
#include "../../includes/macros.h"
#include "../../includes/structures_aouaziz.h"
#include "../../includes/structures_iantar.h"

t_cube3d	*check_And_Set_Player_Position(t_cube3d *cube)
{
	int	i;
	int	j;

	i = -1;
	while (cube->map[++i])
	{
		j = 0;
		while (cube->map[i][j])
		{
			if (cube->map[i][j] == 'N' || cube->map[i][j] == 'S'
				|| cube->map[i][j] == 'W' ||
				cube->map[i][j] == 'E')
			{
				cube->i++;
				cube->player = cube->map[i][j];
			}
			j++;
		}
	}
	if (cube->i > 1)
		ft_print_error("Multiple Players Found in Map\n");
	if (cube->i == 0)
		ft_print_error("Player Not Found in Map\n");
	//cube = find_Player_Position(cube);
	return (cube);
}

t_cube3d	*find_Player_Position(t_cube3d *cube)
{
	while (cube->map[cube->y])
	{
		cube->x = 1;
		while (cube->map[cube->y][cube->x])
		{
			if (cube->map[cube->y][cube->x] == cube->player)
				break ;
			cube->x++;
		}
		if (cube->map[cube->y][cube->x] == cube->player)
			break ;
		cube->y++;
	}
	validate_Player_Position(cube->map, cube->y, cube->x);
	return (cube);
}
void	validate_Player_Position(char **map, int i, int j)
{
	if (map[i + 1][j] != '0' && map[i + 1][j] != '1')
		ft_print_error("Invalid Map - Incorrect Player Position\n");
	else if (map[i - 1][j] != '0' && map[i - 1][j] != '1')
		ft_print_error("Invalid Map - Incorrect Player Position\n");
	else if (map[i][j + 1] != '0' && map[i][j + 1] != '1')
		ft_print_error("Invalid Map - Incorrect Player Position\n");
	else if (map[i][j - 1] != '0' && map[i][j - 1] != '1')
		ft_print_error("Invalid Map - Incorrect Player Position\n");
}
void	check_Map_Not_Closed(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = ft_skip_new_line(map, 0);
	check_Map_Line(map, y);
	while (map[x])
		x++;
	x = x - 1;
	while (map[x][0] == '\n')
		x--;
	check_Map_Line(map, x);
	while (x != y)
	{
		check_First_Line(ft_strtrim(map[x], " "));
		x--;
	}
}
