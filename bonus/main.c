/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:16:02 by iantar            #+#    #+#             */
/*   Updated: 2023/09/13 09:57:39 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/includes_iantar.h"

void	set_texters(t_data *data)
{
	int	i;

	i = 0;
	data->anim[0].img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/cub3d_team/bonus/textures/hand/frame1.xpm", &data->anim[0].width, &data->anim[0].height);
	data->anim[1].img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/cub3d_team/bonus/textures/hand/frame2.xpm", &data->anim[1].width, &data->anim[1].height);
	data->anim[2].img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/cub3d_team/bonus/textures/hand/frame3.xpm", &data->anim[2].width, &data->anim[2].height);
	data->anim[3].img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/cub3d_team/bonus/textures/hand/frame4.xpm", &data->anim[3].width, &data->anim[3].height);
	data->anim[4].img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/cub3d_team/bonus/textures/hand/frame5.xpm", &data->anim[4].width, &data->anim[4].height);
	data->anim[5].img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/cub3d_team/bonus/textures/hand/frame6.xpm", &data->anim[5].width, &data->anim[5].height);
	data->anim[6].img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/cub3d_team/bonus/textures/hand/frame7.xpm", &data->anim[6].width, &data->anim[6].height);
	data->anim[7].img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/cub3d_team/bonus/textures/hand/frame8.xpm", &data->anim[7].width, &data->anim[7].height);
	data->anim[8].img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/cub3d_team/bonus/textures/hand/frame9.xpm", &data->anim[8].width, &data->anim[8].height);
	data->anim[9].img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/cub3d_team/bonus/textures/hand/frame10.xpm", &data->anim[9].width, &data->anim[9].height);
	data->anim[10].img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/cub3d_team/bonus/textures/hand/frame11.xpm", &data->anim[10].width, &data->anim[10].height);
	data->anim[11].img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/cub3d_team/bonus/textures/hand/frame12.xpm", &data->anim[11].width, &data->anim[11].height);
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

t_pos	get_pos(char **map)
{
	t_pos	pos;
	int	i;
	int	j;

	j = -1;
	pos.x = 1;
	pos.y = 1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'S' || map[j][i] == 'W' || map[j][i] == 'E')
			{
				pos.x = i + 0.5;
				pos.y = j + 0.5;
				return (pos);
			}
		}
	}
	return (pos);
}

char	get_player(char **map)
{
	int	i;
	int	j;

	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'S' || map[j][i] == 'W' || map[j][i] == 'E')
				return (map[j][i]);
		}
	}
	return (map[j][i]);
}

t_dir	get_dir(char **map)
{
	t_dir	dir;
	char	player;

	player = get_player(map);
	if (player == 'N')
	{
		dir.x = 0;
		dir.y = -1;
	}
	else if (player == 'W')
	{
		dir.x = 0;
		dir.y = 1;
	}
	else if (player == 'S')
	{
		dir.x = -1;
		dir.y = 0;
	}
	else
	{
		dir.x = 1;
		dir.y = 0;
	}
	return (dir);
}

t_plan	get_plan(t_dir dir)
{
	t_plan	plan;

	plan.x = 0.66;
	plan.y = 0;
	if (dir.x)
	{
		plan.x = 0;
		if (dir.x > 0)
			plan.y = 0.66;
		else
			plan.y = -0.66;
	}
	else
	{
		if (dir.y > 0)
			plan.x = -0.66;
	}
	return (plan);
}

void inisilize(t_data *data, t_textures *txt)
{

	data->dir = get_dir(data->map);
	data->plan = get_plan(data->dir);
	data->pos = get_pos(data->map);
	data->door.state = DOOR_CLOSED;
	data->mlx = mlx_init(data->map);
	data->m_width = 130;//use the parcing resulte
	data->m_height = 65;//use the parcing resulte
	data->mlx_win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	data->ea.img = mlx_xpm_file_to_image(data->mlx , txt->ea, &data->ea.width, &data->ea.height);
    data->no.img = mlx_xpm_file_to_image(data->mlx, txt->no, &data->no.width, &data->no.height);
    data->so.img = mlx_xpm_file_to_image(data->mlx, txt->so, &data->so.width, &data->so.height);
    data->we.img = mlx_xpm_file_to_image(data->mlx, txt->we, &data->we.width, &data->we.height);
    data->door.img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/cub3d_team/bonus/textures/doors/door.xpm", &data->door.width, &data->door.height);
	if (!data->ea.img || !data->no.img || !data->so.img || !data->we.img || !data->door.img)
		error_mesg("invalid texter\n");
	data->no.addr =  mlx_get_data_addr(data->no.img, &data->no.bits_per_pixel, &data->no.size_line, &data->no.endian);
	data->so.addr =  mlx_get_data_addr(data->so.img, &data->so.bits_per_pixel, &data->so.size_line, &data->so.endian);
	data->we.addr =  mlx_get_data_addr(data->we.img, &data->we.bits_per_pixel, &data->we.size_line, &data->we.endian);
	data->ea.addr =  mlx_get_data_addr(data->ea.img, &data->ea.bits_per_pixel, &data->ea.size_line, &data->ea.endian);
	data->door.addr =  mlx_get_data_addr(data->door.img, &data->door.bits_per_pixel, &data->door.size_line, &data->door.endian);
	set_texters(data);
}

// void	print(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (data->map[i])
// 	{
// 		printf("%s\n", data->map[i]);
// 		i++;
// 	}
// 	printf("height:%d, width:%d\n", data->m_height, data->m_width);
	
// }

int	main(int ac, char *av[])
{
	t_data		*data;
	t_textures	*txt;
	t_color		*g;
	char		**map;
	if (ac != 2)
		error_mesg("Ivalide Number of Arguments\n");
	map = NULL;
	check_cub (av[1]);
	txt = malloc(sizeof(t_textures));
	g = malloc(sizeof(t_color));
	data = malloc(sizeof(t_data));
	map = git_map(av[1]); 
	partition_map(map, data);// print(p,txt);
	if (check_txter(map) == 1)
		(freepath(map), ft_error("Error1\n"));
	plus_txter_and_fc(data, txt, g);
	if (plus_espice(data) == 1)
		(freepath(data->map), freepath(data->mapm),
			free(data), ft_error("Error2\n"));
	inisilize(data, txt);
	printf("height:%d, width:%d\n", data->m_height, data->m_width);
	render_map(data);
	player_hooks(data);
	mlx_loop(data->mlx);
	(freepath(map), freepath(data->mapm), freepath(data->map), free(g));
	free(txt->no);
	free(txt->so);
	free(txt->ea);
	free(txt->we);
	(free(txt), free(data));
	return (EXIT_SUCCESS);
}
