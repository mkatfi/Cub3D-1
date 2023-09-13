/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_version.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:26:28 by iantar            #+#    #+#             */
/*   Updated: 2023/09/13 12:40:36 by iantar           ###   ########.fr       */
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

t_dda	dda_distance(t_data *data, t_pos ray_dir)
{
	double	dx;
	double	dy;
	cor_int	step;
	t_pos	dist;
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
	dda.door = 0;
	
	// while (data->map[ray_map.y][ray_map.x] != '1' )//here you must to make sure that x and y are in thier place
	while (ray_map.y >= 0 && ray_map.y < data->m_height && ray_map.x >= 0 && ray_map.x < data->m_width &&
       data->map[ray_map.y][ray_map.x] != '1')
	{
		if (data->map[ray_map.y][ray_map.x] == 'D' && (data->door.state || distace_between(data->pos, ray_map) > 2))
		{
			dda.door = 1;
			break;
		}
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


// void	draw_square(t_data *data, int i, int j, int color)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < MINI_GRID)
// 	{
// 		x = 0;
// 		while (x < MINI_GRID)
// 		{
// 			my_mlx_pixel_put(data, i * MINI_GRID + x, j * MINI_GRID + y, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }

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

void	draw_player_(t_data *data)
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
	draw_player_(data);
}

void	draw_player(t_data *data, t_pos pos, int color)
{
	double	angle;

	angle = 0;
	(void)color;
	if (pos.x * MINI_GRID > SCREEN_WIDTH / 5 - 5)
		pos.x = SCREEN_WIDTH / (5 * MINI_GRID) - 1;
	if (pos.y * MINI_GRID > (SCREEN_HEIGHT / 5) - 5)
		pos.y = SCREEN_HEIGHT / (5 * MINI_GRID) - 1;
	while (angle < 2 * PI)
	{
		line(data, pos.x * MINI_GRID, pos.y * MINI_GRID, angle, PLAYER_DIM / 2);
		angle += 0.1;
	}
}
//doorsmake


//dynamic texters : done
