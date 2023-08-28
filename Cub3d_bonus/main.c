/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:16:02 by iantar            #+#    #+#             */
/*   Updated: 2023/08/28 16:10:01 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/includes_iantar.h"
#include "./includes/includes_aouaziz.h"
#include "./includes/structures_iantar.h"
#include "./includes/structures_aouaziz.h"
#include "./includes/macros.h"

t_data	*inisilize(char *av)
{
	t_data		*data;
	t_cube3d	*cube;

	data = malloc(sizeof(t_data));
	cube = check_File_And_Read_it(av);
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
	data->ea.img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/Cub3D/textures/ea.xpm", &data->ea.width, &data->ea.height);
    data->no.img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/Cub3D/textures/iantar.xpm", &data->no.width, &data->no.height);
    data->so.img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/Cub3D/textures/alaouite.xpm", &data->so.width, &data->so.height);
    data->we.img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/Cub3D/textures/Almoravides.xpm", &data->we.width, &data->we.height);
	if (!data->ea.img || !data->no.img || !data->so.img || !data->we.img)
		error_mesg("invalid texter\n");
	data->no.addr =  mlx_get_data_addr(data->no.img, &data->no.bits_per_pixel, &data->no.size_line, &data->no.endian);
	data->so.addr =  mlx_get_data_addr(data->so.img, &data->so.bits_per_pixel, &data->so.size_line, &data->so.endian);
	data->we.addr =  mlx_get_data_addr(data->we.img, &data->we.bits_per_pixel, &data->we.size_line, &data->we.endian);
	data->ea.addr =  mlx_get_data_addr(data->ea.img, &data->ea.bits_per_pixel, &data->ea.size_line, &data->ea.endian);
	return (data);
}

int	main(int ac, char *av[])
{
	t_data		*data;

	if (ac != 2)
		error_mesg("Ivalide Number of Arguments\n");
	data = inisilize(av[1]);
	render_map(data);
 	player_hooks(data);
	mlx_loop(data->mlx);
	return (EXIT_SUCCESS);
}
