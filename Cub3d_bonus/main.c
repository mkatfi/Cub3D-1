/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:16:02 by iantar            #+#    #+#             */
/*   Updated: 2023/08/30 11:17:33 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/includes_iantar.h"
#include "./includes/includes_aouaziz.h"
#include "./includes/structures_iantar.h"
#include "./includes/structures_aouaziz.h"
#include "./includes/macros.h"

void	set_texters(t_data *data)
{
	int	i;

	i = 0;
	data->anim[0].img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/Cub3D/Cub3d_bonus/textures/hand/frame1.xpm", &data->anim[0].width, &data->anim[0].height);
	data->anim[1].img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/Cub3D/Cub3d_bonus/textures/hand/frame2.xpm", &data->anim[1].width, &data->anim[1].height);
	data->anim[2].img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/Cub3D/Cub3d_bonus/textures/hand/frame3.xpm", &data->anim[2].width, &data->anim[2].height);
	data->anim[3].img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/Cub3D/Cub3d_bonus/textures/hand/frame4.xpm", &data->anim[3].width, &data->anim[3].height);
	data->anim[4].img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/Cub3D/Cub3d_bonus/textures/hand/frame5.xpm", &data->anim[4].width, &data->anim[4].height);
	data->anim[5].img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/Cub3D/Cub3d_bonus/textures/hand/frame6.xpm", &data->anim[5].width, &data->anim[5].height);
	data->anim[6].img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/Cub3D/Cub3d_bonus/textures/hand/frame7.xpm", &data->anim[6].width, &data->anim[6].height);
	data->anim[7].img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/Cub3D/Cub3d_bonus/textures/hand/frame8.xpm", &data->anim[7].width, &data->anim[7].height);
	data->anim[8].img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/Cub3D/Cub3d_bonus/textures/hand/frame9.xpm", &data->anim[8].width, &data->anim[8].height);
	data->anim[9].img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/Cub3D/Cub3d_bonus/textures/hand/frame10.xpm", &data->anim[9].width, &data->anim[9].height);
	data->anim[10].img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/Cub3D/Cub3d_bonus/textures/hand/frame11.xpm", &data->anim[10].width, &data->anim[10].height);
	data->anim[11].img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/Cub3D/Cub3d_bonus/textures/hand/frame12.xpm", &data->anim[11].width, &data->anim[11].height);
	while (i < 12)
	{
		if (!data->anim[i].img)
			error_mesg("invalid texter\n");
		i++;
	}
	i = 0;
	while (i < 12)
	{
		data->anim[i].addr = mlx_get_data_addr(data->anim[i].img, &data->anim[i].bits_per_pixel, &data->anim[i].size_line, &data->anim[i].endian);
		i++;
	}
		
}

t_data	*inisilize(char *av)
{
	t_data		*data;
	t_cube3d	*cube;

	data = malloc(sizeof(t_data));
	cube = check_File_And_Read_it(av);
	data->map = cube->map;
	/*
	if (data->player == NO)
	else if (data->player == WE)
	else if (data->player == EA)
	else if (data->player == SO)
	*/
	data->dir.y = -1; //N
    data->dir.x = 0;
	data->plan.x = 0.66;
	data->plan.y = 0;//tan(33)
	data->pos.x = 2;
	data->pos.y = 2;
	data->mlx = mlx_init(data->map);
	data->m_width = 15;//use the parcing resulte
	data->m_height = 41;//use the parcing resulte
	data->mlx_win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	data->ea.img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/Cub3D/textures/StoneUWL.xpm", &data->ea.width, &data->ea.height);
    data->no.img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/Cub3D/textures/GrasswallL.xpm", &data->no.width, &data->no.height);
    data->so.img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/Cub3D/textures/SnowbrickL.xpm", &data->so.width, &data->so.height);
    data->we.img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/Cub3D/textures/MultibrickL.xpm", &data->we.width, &data->we.height);
	if (!data->ea.img || !data->no.img || !data->so.img || !data->we.img)
		error_mesg("invalid texter\n");
	data->no.addr =  mlx_get_data_addr(data->no.img, &data->no.bits_per_pixel, &data->no.size_line, &data->no.endian);
	data->so.addr =  mlx_get_data_addr(data->so.img, &data->so.bits_per_pixel, &data->so.size_line, &data->so.endian);
	data->we.addr =  mlx_get_data_addr(data->we.img, &data->we.bits_per_pixel, &data->we.size_line, &data->we.endian);
	data->ea.addr =  mlx_get_data_addr(data->ea.img, &data->ea.bits_per_pixel, &data->ea.size_line, &data->ea.endian);
	set_texters(data);
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
