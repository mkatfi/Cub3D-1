/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:16:02 by iantar            #+#    #+#             */
/*   Updated: 2023/08/16 09:47:03 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/includes_iantar.h"
#include "./includes/includes_aouaziz.h"
#include "./includes/structures_iantar.h"
#include "./includes/structures_aouaziz.h"
#include "./includes/macros.h"

// t_data	*mlx_initialize()
// {

// }

// t_pos	get_pos(char *map)
// {
// 	int	i;
// 	int	j;

// 	while (map[i])
// 	{
// 		j = 0;75
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == 'N' )
// 		}
// 	}
// }

//initialize angle, pos_x, pos_y
//if :: E (angle == 0) , N (angle == 90) , W (angle == 180) , S (angle == 270)
int	main(int ac, char *av[])
{
	t_cube3d	*cube;
	t_data		*data;
	t_pos		pos;
	//char		**map;
	t_dir		dir;

	if (ac != 2)
		ft_print_error("Incorrect Number of Arguments\n");
	data = malloc(sizeof(t_data));
	cube = check_File_And_Read_it(av[1]);
	data->map = cube->map;
	dir.y = -1; //N
    dir.x = 0;
	pos.x = 2.5;
	pos.y = 2.5;
	//data->pos = get_pos();
	//data->dir = get_dir(data->map);
	data->mlx = mlx_init(data->map);
	//data->m_height = cube->m_height;
	data->m_width = 12;
	data->m_height = 10;
	data->mlx_win = mlx_new_window(data->mlx, GRID_SQUAR * 24, GRID_SQUAR * data->m_height, "Cub3D");
	//render_map(data, pos, dir);
	player_hooks(data);
	mlx_loop(data->mlx);
	return (0);
}
