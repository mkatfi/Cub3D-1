/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_version.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:26:28 by iantar            #+#    #+#             */
/*   Updated: 2023/09/21 14:41:39 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_bonus.h"

/// @brief it will mesuer the first distance and the
	//"step" followed Forward or Backward
/// @param data the data
/// @param ray_dir the vector of a single ray
	//(ray_dir = dir + cameraX * plan)
/// @param ds a struct contain dx and dy (distances in one unit)
/// @return return the first disatnce (x unit) and the step followed 
	//(we will use it to know if we should add or subtract GRIDS).
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

t_dda	calculate_dist(t_data *data, t_info *info, t_dist ds)
{
	t_dda	dda;

	if (data->door.state)
		dda.door = 0;
	while (ray_hit_wall(data, info))
	{
		if (check_door(data, info))
		{
			dda.door = 1;
			data->door.state = DOOR_CLOSED;
			break ;
		}
		dda.side = (info->dist.x < info->dist.y);
		if (info->dist.x < info->dist.y)
		{
			info->dist.x += ds.dx;
			info->ray_map.x += info->step.x;
		}
		else
		{
			info->dist.y += ds.dy;
			info->ray_map.y += info->step.y;
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
	double	x;
	double	camera_x;
	t_dda	dda;
	t_pos	ray_dir;
	double	tex;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		camera_x = (2 * x) / SCREEN_WIDTH - 1;
		ray_dir.x = data->dir.x + camera_x * data->plan.x;
		ray_dir.y = data->dir.y + camera_x * data->plan.y;
		dda = dda_distance(data, ray_dir);
		dda.distance = dda.distance / magnitude(ray_dir.x, ray_dir.y);
		if (dda.side == NO || dda.side == WE)
			tex = (ray_dir.x * dda.distance + data->pos.x) - (int)(ray_dir.x
					* dda.distance + data->pos.x);
		else
			tex = ((ray_dir.y * dda.distance + data->pos.y) - (int)(ray_dir.y
						* dda.distance + data->pos.y));
		fake_3d(data, dda, x, tex);
		x++;
	}
	mini_map(data);
}
