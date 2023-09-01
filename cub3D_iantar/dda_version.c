/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_version.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:26:28 by iantar            #+#    #+#             */
/*   Updated: 2023/09/01 09:19:30 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_iantar.h"
#include "../includes/includes_aouaziz.h"
#include "../includes/structures_iantar.h"
#include "../includes/structures_iantar.h"
#include "../includes/macros.h"
 
double	magnitude(double x, double y)
{
	return (sqrt(x * x + y * y));
}

t_dda	dda_distance(t_data *data, t_pos ray_dir)
{
	double	dx;
	double	dy;
	cor_int	step;
	t_pos	dist;
	//int		side;
	cor_int	ray_map;
	t_dda	dda;

	dx = magnitude(ray_dir.x, ray_dir.y) / fabs(ray_dir.x);//there is a problem here
	dy = magnitude(ray_dir.x, ray_dir.y) / fabs(ray_dir.y);

	ray_map.x = (int)data->pos.x;
	ray_map.y = (int)data->pos.y;
	if (ray_dir.x > 0)
	{
		step.x = 1;
		dist.x = ((ray_map.x + 1) - data->pos.x) * dx;
	}
	else
	{
		step.x = -1;
		dist.x =  (data->pos.x - ray_map.x) * dx;
	}
	if (ray_dir.y < 0)
	{
		dist.y = (data->pos.y - ray_map.y) * dy;
		step.y = -1;
	}
	else
	{
		dist.y =  ((ray_map.y + 1) - data->pos.y) * dy; 
		step.y = 1;
	}

	while (data->map[ray_map.y][ray_map.x] != '1')//here you must to make sure that x and y are in thier place
	{
		if (dist.x < dist.y)
		{
			dist.x += dx;
			ray_map.x += step.x;
			dda.side = 1;
		}
		else
		{
			dist.y += dy;
			ray_map.y += step.y;
			dda.side = 0;
		}
	}
	if (dda.side)
	{
		dda.distance = dist.x - dx;
		if (ray_dir.x > 0)
			dda.side = NO;
		else
			dda.side = WE;
	}
	else
	{
		dda.distance = dist.y - dy;
		if (ray_dir.y > 0)
			dda.side = EA;
		else
			dda.side = SO;
	}
	return (dda);
}

void	dda_version(t_data *data)
{
	double		x;
	double	camera_x;
	t_dda	dda;
	t_pos	ray_dir;
	int	tex;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		camera_x = (2 * x) / SCREEN_WIDTH - 1;//x-coordinate in camera space
		ray_dir.x = data->dir.x + camera_x * data->plan.x;
		ray_dir.y = data->dir.y + camera_x * data->plan.y;
		dda = dda_distance(data, ray_dir);
		dda.distance = dda.distance / magnitude(ray_dir.x, ray_dir.y);
		if (dda.side == EA || dda.side == SO)//dda.side == NO || dda.side == WE)
		{
			tex = abs((int)(((ray_dir.x * dda.distance + data->pos.x) - (int)(ray_dir.x * dda.distance + data->pos.x)) * GRID));//get the pos of the ray when it hit the wall
		}
		else
		{
			tex = abs((int)(((ray_dir.y * dda.distance + data->pos.y) - (int)(ray_dir.y * dda.distance + data->pos.y)) * GRID));
		}
		
		//line(data, data->pos.x * GRID, data->pos.y * GRID, atan2(ray_dir.y, ray_dir.x), dda.distance * GRID * magnitude(ray_dir.x, ray_dir.y));
		fake_3d(data, dda, x, tex);
		x++;
 	}
}
//dynamic texters
//gliss
//curser
//animation
//doors
//