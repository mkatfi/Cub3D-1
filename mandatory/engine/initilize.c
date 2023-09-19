/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:40:43 by iantar            #+#    #+#             */
/*   Updated: 2023/09/18 14:59:48 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_mandatory.h"

t_pos	get_pos(char **map)
{
	t_pos	pos;
	int		i;
	int		j;

	j = -1;
	pos.x = 1;
	pos.y = 1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'S'
				|| map[j][i] == 'W' || map[j][i] == 'E')
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

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'S'
				|| map[j][i] == 'W' || map[j][i] == 'E')
				return (map[j][i]);
			i++;
		}
		j++;
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

	plan.x = TAN33;
	plan.y = 0;
	if (dir.x)
	{
		plan.x = 0;
		if (dir.x > 0)
			plan.y = TAN33;
		else
			plan.y = -TAN33;
	}
	else
	{
		if (dir.y > 0)
			plan.x = -TAN33;
	}
	return (plan);
}

void	inisilize(t_data *data, t_textures *txt)
{
	data->dir = get_dir(data->map);
	data->plan = get_plan(data->dir);
	data->pos = get_pos(data->map);
	data->mlx = mlx_init(data->map);
	data->mlx_win = mlx_new_window(data->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT, "Cub3D");
	data->ea.img = mlx_xpm_file_to_image(data->mlx, txt->ea,
			&data->ea.width, &data->ea.height);
	data->no.img = mlx_xpm_file_to_image(data->mlx, txt->no,
			&data->no.width, &data->no.height);
	data->so.img = mlx_xpm_file_to_image(data->mlx, txt->so,
			&data->so.width, &data->so.height);
	data->we.img = mlx_xpm_file_to_image(data->mlx, txt->we,
			&data->we.width, &data->we.height);
	if (!data->ea.img || !data->no.img || !data->so.img || !data->we.img)
		error_mesg("invalid texter\n");
	data->no.addr = mlx_get_data_addr(data->no.img,
			&data->no.bits_per_pixel, &data->no.size_line, &data->no.endian);
	data->so.addr = mlx_get_data_addr(data->so.img,
			&data->so.bits_per_pixel, &data->so.size_line, &data->so.endian);
	data->we.addr = mlx_get_data_addr(data->we.img,
			&data->we.bits_per_pixel, &data->we.size_line, &data->we.endian);
	data->ea.addr = mlx_get_data_addr(data->ea.img,
			&data->ea.bits_per_pixel, &data->ea.size_line, &data->ea.endian);
}
