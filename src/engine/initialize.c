/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:39:45 by iantar            #+#    #+#             */
/*   Updated: 2023/09/17 11:19:48 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_bonus.h"

void	norm_set_texters_0(t_data *data)
{
	data->anim[6].img = mlx_xpm_file_to_image(data->mlx,
			"./textures/hand/frame7.xpm",
			&data->anim[6].width, &data->anim[6].height);
	data->anim[7].img = mlx_xpm_file_to_image(data->mlx,
			"./textures/hand/frame8.xpm",
			&data->anim[7].width, &data->anim[7].height);
	data->anim[8].img = mlx_xpm_file_to_image(data->mlx,
			"./textures/hand/frame9.xpm",
			&data->anim[8].width, &data->anim[8].height);
	data->anim[9].img = mlx_xpm_file_to_image(data->mlx,
			"./textures/hand/frame10.xpm",
			&data->anim[9].width, &data->anim[9].height);
	data->anim[10].img = mlx_xpm_file_to_image(data->mlx,
			"./textures/hand/frame11.xpm",
			&data->anim[10].width, &data->anim[10].height);
	data->anim[11].img = mlx_xpm_file_to_image(data->mlx,
			"./textures/hand/frame12.xpm",
			&data->anim[11].width, &data->anim[11].height);
}

void	norm_set_texters_1(t_data *data)
{
	data->anim[0].img = mlx_xpm_file_to_image(data->mlx,
			"./textures/hand/frame1.xpm",
			&data->anim[0].width, &data->anim[0].height);
	data->anim[1].img = mlx_xpm_file_to_image(data->mlx,
			"./textures/hand/frame2.xpm",
			&data->anim[1].width, &data->anim[1].height);
	data->anim[2].img = mlx_xpm_file_to_image(data->mlx,
			"./textures/hand/frame3.xpm",
			&data->anim[2].width, &data->anim[2].height);
	data->anim[3].img = mlx_xpm_file_to_image(data->mlx,
			"./textures/hand/frame4.xpm",
			&data->anim[3].width, &data->anim[3].height);
	data->anim[4].img = mlx_xpm_file_to_image(data->mlx,
			"./textures/hand/frame5.xpm",
			&data->anim[4].width, &data->anim[4].height);
	data->anim[5].img = mlx_xpm_file_to_image(data->mlx,
			"./textures/hand/frame6.xpm",
			&data->anim[5].width, &data->anim[5].height);
	norm_set_texters_0(data);
}

void	set_texters(t_data *data)
{
	int	i;

	i = 0;
	norm_set_texters_1(data);
	while (i < 12)
	{
		if (!data->anim[i].img)
			error_mesg("invalid texter\n");
		i++;
	}
	i = 0;
	while (i < 12)
	{
		data->anim[i].addr = mlx_get_data_addr(data->anim[i].img,
				&data->anim[i].bits_per_pixel, &data->anim[i].size_line,
				&data->anim[i].endian);
		i++;
	}
	while (++i < 12)
		if (!data->anim[i].addr)
			error_mesg("invalid texter\n");
}

void	norm_inisilize(t_data *data, t_textures *txt)
{
	data->dir = get_dir(data->map);
	data->plan = get_plan(data->dir);
	data->pos = get_pos(data->map);
	data->door.state = DOOR_CLOSED;
	data->mlx = mlx_init(data->map);
	data->mlx_win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			"Cub3D");
	data->ea.img = mlx_xpm_file_to_image(data->mlx, txt->ea, &data->ea.width,
			&data->ea.height);
	data->no.img = mlx_xpm_file_to_image(data->mlx, txt->no, &data->no.width,
			&data->no.height);
	data->so.img = mlx_xpm_file_to_image(data->mlx, txt->so, &data->so.width,
			&data->so.height);
	data->we.img = mlx_xpm_file_to_image(data->mlx, txt->we, &data->we.width,
			&data->we.height);
	data->door.img = mlx_xpm_file_to_image(data->mlx,
			"./textures/doors/door.xpm",
			&data->door.width, &data->door.height);
	if (!data->ea.img || !data->no.img || !data->so.img || !data->we.img
		|| !data->door.img)
		error_mesg("invalid texter\n");
}

void	initialize(t_data *data, t_textures *txt)
{
	norm_inisilize(data, txt);
	data->no.addr = mlx_get_data_addr(data->no.img, &data->no.bits_per_pixel,
			&data->no.size_line, &data->no.endian);
	data->so.addr = mlx_get_data_addr(data->so.img, &data->so.bits_per_pixel,
			&data->so.size_line, &data->so.endian);
	data->we.addr = mlx_get_data_addr(data->we.img, &data->we.bits_per_pixel,
			&data->we.size_line, &data->we.endian);
	data->ea.addr = mlx_get_data_addr(data->ea.img, &data->ea.bits_per_pixel,
			&data->ea.size_line, &data->ea.endian);
	data->door.addr = mlx_get_data_addr(data->door.img,
			&data->door.bits_per_pixel, &data->door.size_line,
			&data->door.endian);
	set_texters(data);
}
