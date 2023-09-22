/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_version.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:26:28 by iantar            #+#    #+#             */
/*   Updated: 2023/09/21 14:39:52 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_mandatory.h"

t_info	get_step_dist(t_data *data, t_pos ray_dir, t_dist ds)
{
	t_info	info;

	info.ray_map.x = (int)data->pos.x;
	info.ray_map.y = (int)data->pos.y;
	if (ray_dir.x > 0)
	{
		info.step.x = 1;
		info.dist.x = ((info.ray_map.x + 1) - data->pos.x) * ds.dx;
	}
	else
	{
		info.step.x = -1;
		info.dist.x = (data->pos.x - info.ray_map.x) * ds.dx;
	}
	if (ray_dir.y < 0)
	{
		info.dist.y = (data->pos.y - info.ray_map.y) * ds.dy;
		info.step.y = -1;
	}
	else
	{
		info.dist.y = ((info.ray_map.y + 1) - data->pos.y) * ds.dy;
		info.step.y = 1;
	}
	return (info);
}

int	ray_hit_wall(t_data *data, t_info *info)
{
	return (info->ray_map.y >= 0 && info->ray_map.y
		< data->m_height && info->ray_map.x >= 0
		&& info->ray_map.x < data->m_width
		&& data->map[info->ray_map.y][info->ray_map.x] != '1');
}

t_dda	calculate_dist(t_data *data, t_info *info, t_dist ds)
{
	t_dda	dda;

	while (ray_hit_wall(data, info))
	{
		if (info->dist.x < info->dist.y)
		{
			info->dist.x += ds.dx;
			info->ray_map.x += info->step.x;
			dda.side = 1;
		}
		else
		{
			info->dist.y += ds.dy;
			info->ray_map.y += info->step.y;
			dda.side = 0;
		}
	}
	return (dda);
}

t_dda	dda_distance(t_data *data, t_pos ray_dir)
{
	t_dist	ds;
	t_info	info;
	t_dda	dda;

	ds.dx = magnitude(ray_dir.x, ray_dir.y) / fabs(ray_dir.x);
	ds.dy = magnitude(ray_dir.x, ray_dir.y) / fabs(ray_dir.y);
	info = get_step_dist(data, ray_dir, ds);
	dda = calculate_dist(data, &info, ds);
	if (dda.side)
	{
		dda.distance = info.dist.x - ds.dx;
		if (ray_dir.x > 0)
			dda.side = EA;
		else
			dda.side = SO;
	}
	else
	{
		dda.distance = info.dist.y - ds.dy;
		if (ray_dir.y > 0)
			dda.side = WE;
		else
			dda.side = NO;
	}
	return (dda);
}

void	dda_version(t_data *data)
{
	double		x;
	double		camera_x;
	t_dda		dda;
	t_pos		ray_dir;
	int			tex;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		camera_x = (2 * x) / SCREEN_WIDTH - 1;
		ray_dir.x = data->dir.x + camera_x * data->plan.x;
		ray_dir.y = data->dir.y + camera_x * data->plan.y;
		dda = dda_distance(data, ray_dir);
		dda.distance = dda.distance / magnitude(ray_dir.x, ray_dir.y);
		if (dda.side == NO || dda.side == WE)
			tex = abs((int)(((ray_dir.x * dda.distance + data->pos.x)
							- (int)(ray_dir.x * dda.distance + data->pos.x))
						* GRID));
		else
			tex = abs((int)(((ray_dir.y * dda.distance + data->pos.y)
							- (int)(ray_dir.y * dda.distance + data->pos.y))
						* GRID));
		fake_3d(data, dda, x, tex);
		x++;
	}
}
