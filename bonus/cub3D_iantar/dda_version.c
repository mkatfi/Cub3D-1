/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_version.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:26:28 by iantar            #+#    #+#             */
/*   Updated: 2023/09/14 15:23:57 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_iantar.h"
 
double	magnitude(double x, double y)
{
	return (sqrt(x * x + y * y));
}

double	distace_between(t_pos pos, cor_int ray_map)
{
	return (magnitude(fabs(pos.x - ray_map.x), fabs(pos.y - ray_map.y)));
}

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
		info.dist.x =  (data->pos.x - info.ray_map.x) * ds.dx;
	}
	if (ray_dir.y < 0)
	{
		info.dist.y = (data->pos.y - info.ray_map.y) * ds.dy;
		info.step.y = -1;
	}
	else
	{
		info.dist.y =  ((info.ray_map.y + 1) - data->pos.y) * ds.dy;
		info.step.y = 1;
	}
	return (info);
}

int	ray_hit_wall(t_data *data, t_info *info)
{
	return (info->ray_map.y >= 0 && info->ray_map.y < data->m_height && info->ray_map.x >= 0 && info->ray_map.x < data->m_width &&
       data->map[info->ray_map.y][info->ray_map.x] != '1');
}

int	check_door(t_data *data, t_info *info)
{
	return (data->map[info->ray_map.y][info->ray_map.x] == 'D' && (data->door.state || distace_between(data->pos, info->ray_map) > 2));
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
			dda.door = 1;//to check if it is a door or not
			data->door.state = DOOR_CLOSED;
			break;
		}
		dda.side = (info->dist.x < info->dist.y);//norm
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

	ds.dx = magnitude(ray_dir.x, ray_dir.y) / fabs(ray_dir.x);//there is a problem here
	ds.dy = magnitude(ray_dir.x, ray_dir.y) / fabs(ray_dir.y);
	info = get_step_dist(data, ray_dir, ds);
	dda = calculate_dist(data, &info, ds);
	if (dda.side)
	{
		dda.distance = info.dist.x - ds.dx;
		if (ray_dir.x > 0)
			dda.side = NO;
		else
			dda.side = WE;
	}
	else
	{
		dda.distance = info.dist.y - ds.dy;
		if (ray_dir.y > 0)
			dda.side = EA;
		else
			dda.side = SO;
	}
	return (dda);
}

//t_dda	get_dda()//it will gives you the side where the ray hits, and the distance

void	dda_version(t_data *data)
{
	double		x;
	double	camera_x;
	t_dda	dda;
	t_pos	ray_dir;
	double	tex;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		camera_x = (2 * x) / SCREEN_WIDTH - 1;//x-coordinate in camera space
		ray_dir.x = data->dir.x + camera_x * data->plan.x;
		ray_dir.y = data->dir.y + camera_x * data->plan.y;
		dda = dda_distance(data, ray_dir);
		dda.distance = dda.distance / magnitude(ray_dir.x, ray_dir.y);
		if (dda.side == EA || dda.side == SO)//dda.side == NO || dda.side == WE)
			tex = (ray_dir.x * dda.distance + data->pos.x) - (int)(ray_dir.x * dda.distance + data->pos.x) ;//get the pos of the ray when it hit the wall
		else
			tex = ((ray_dir.y * dda.distance + data->pos.y) - (int)(ray_dir.y * dda.distance + data->pos.y));
		fake_3d(data, dda, x, tex);
		x++;
 	}
	mini_map(data);
}

void	draw_square_(t_data *data, cor_int cor, int grid, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < grid)
	{
		x = 0;
		while (x < grid)
		{
			my_mlx_pixel_put(data, cor.x * grid + x, cor.y * grid + y, color);
			x++;
		}
		y++;
	}
}

void	draw_player(t_data *data)
{
	double	angle;

	angle = 0;
	while (angle < 2 * PI)
	{
		line(data, 50, 50, angle, PLAYER_DIM / 2);
		angle += 0.1;
	}
}

void	mini_map(t_data *data)
{
	cor_int	cor;
	cor_int	m;
	
	cor.y = 0;
	m.y = data->pos.y - 5;
	while (cor.y * MINI_GRID < SCREEN_HEIGHT / 5)
	{
		cor.x = 0;
		m.x = data->pos.x - 5;
		while (cor.x * MINI_GRID < SCREEN_WIDTH / 5)
		{
			if ((m.x < 0 || m.y < 0) || (m.y >= data->m_height || m.x >= data->m_width) || (data->map[m.y][m.x] == '1'))
				draw_square_(data, cor, MINI_GRID, GRAY);
			else if (data->map[m.y][m.x] == 'D')
				draw_square_(data, cor, MINI_GRID, BRWON);
			else	
				draw_square_(data, cor, MINI_GRID, CYAN);
			cor.x++;
			m.x++;
		}
		cor.y++;
		m.y++;
	}
	draw_player(data);
}

