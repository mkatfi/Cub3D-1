/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:16:02 by iantar            #+#    #+#             */
/*   Updated: 2023/08/27 13:01:53 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/includes_iantar.h"
#include "./includes/includes_aouaziz.h"
#include "./includes/structures_iantar.h"
#include "./includes/structures_aouaziz.h"
#include "./includes/macros.h"


int	main(int ac, char *av[])
{
	t_cube3d	*cube;
	t_data		*data;
	
	//t_pos		pos;
	//char		**map;
	//t_dir		dir;

	if (ac != 2)
		ft_print_error("Incorrect Number of Arguments\n");
	data = malloc(sizeof(t_data));
	cube = check_File_And_Read_it(av[1]);
	data->map = cube->map;
	data->dir.y = 0; //N
    data->dir.x = 1;
	data->pos.x = 2;
	data->pos.y = 2;
	data->plan.x = 0;
	data->plan.y = 0.66;//tan(33)
	data->mlx = mlx_init(data->map);
	data->m_width = 12;
	data->m_height = 10;
	data->mlx_win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	render_map(data);
 	player_hooks(data);
	mlx_loop(data->mlx);
	return (EXIT_SUCCESS);
}
