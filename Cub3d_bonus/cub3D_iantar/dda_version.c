/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_version.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:26:28 by iantar            #+#    #+#             */
/*   Updated: 2023/09/02 10:36:43 by iantar           ###   ########.fr       */
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
	dda.door = 0;
	while (data->map[ray_map.y][ray_map.x] != '1')//here you must to make sure that x and y are in thier place
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

// void	door()
// {

// }

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


void	draw_square(t_data *data, int i, int j, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < MINI_GRID)
	{
		x = 0;
		while (x < MINI_GRID)
		{
			my_mlx_pixel_put(data, i * MINI_GRID + x, j * MINI_GRID + y, color);
			x++;
		}
		y++;
	}
}
void	mini_map(t_data *data)
{
	cor_int	start;
	cor_int	end;
	int	i;
	int	j;
	int	x, y;

	start.x = (int)(data->pos.x) - 20;
	start.y = (int)(data->pos.y) - 12;
	end.x = (int)(data->pos.x) + 20;
	end.y = (int)(data->pos.y) + 12;
	start.x = 0;
	end.x = data->m_width;
	start.y = 0;
	end.y = data->m_height;
	j = start.y;
	y = 0;

	while (j < end.y)
	{
		i = start.x;
		x = 0;
		while (i < end.x)
		{
			if (data->map[j][i] == '1')
				draw_square(data, x, y, GRAY);
			else if (data->map[j][i] == 'D')
				draw_square(data, x, y, BRWON);
			else	
				draw_square(data, x, y, CYAN);
			i++;
			x++;
		}
		y++;
		j++;
	}
	t_pos	pos;
	pos.x = data->pos.x;
	pos.y = data->pos.y;
	draw_player(data, pos, RED);
}

void	draw_square_(t_data *data, cor_int cor, int grid, int color)
{
	int	x;
	int	y;

	j = 0;
	while (j < grid)
	{
		i = 0;
		while (i < grid)
		{
			my_mlx_pixel_put(data, cor.x * grid, + x, cor.y * grid + y, color);
			i++;
		}
		j++;
	}
}

void	new_mini_map(t_data *data)
{
	cor_int	mini;

	mini.x = SCREEN_WIDTH / 4;
	mini.y = SCREEN_HEIGHT / 4;
	while (i < )
	{
		/* code */
	}
		
}
void	draw_player(t_data *data, t_pos pos, int color)
{
	double	angle;

	angle = 0;
	(void)color;
	while (angle < 2 * PI)
	{
		line(data, pos.x * MINI_GRID, pos.y * MINI_GRID, angle, PLAYER_DIM / 2);
		angle += 0.1;
	}
}
//mini map : need to check
//doorsmake


//dynamic texters : done
//gliss: done
//curser : done
//animation : done
