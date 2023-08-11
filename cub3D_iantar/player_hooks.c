/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 08:05:16 by iantar            #+#    #+#             */
/*   Updated: 2023/08/10 10:56:46 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_iantar.h"
#include "../includes/includes_aouaziz.h"
#include "../includes/structures_iantar.h"
#include "../includes/structures_iantar.h"
#include "../includes/macros.h"

int	check_(t_pos pos, char **map, t_dir dir)
{
	if (map[(int)(((-1) * dir.y + pos.y)/GRID_SQUAR)][(int)((dir.x + pos.x)/GRID_SQUAR)] != '1' && map[(int)(dir.y + pos.y)/GRID_SQUAR][(int)(((-1) * dir.x + pos.x)/GRID_SQUAR)] != '1')
		return (0);
	return (1);
}
int	is_player_will_hit_wall(float pos_x, float pos_y, char **map, t_dir dir)
{
	float	a;

	a = 0;
	while (a <= 2 * PI)
	{
		if (map[(int)((pos_y + PLAYER_DIM * sin(dir.angle + a)) / GRID_SQUAR)][(int)((pos_x + PLAYER_DIM * cos(dir.angle + a)) / GRID_SQUAR)] == '1')
			return (1);
		a = a + PI / 2;
	}
	return(0);
}

void	draw_player(t_pos pos, int r, t_data *data, int color)
{
	float	i;
	float	j;

	j = 0;
	while (j < r)
	{
		i = 0;
		while (i < 2 * PI)
		{
			my_mlx_pixel_put(data, pos.x + j * cos(i), pos.y + j * sin(i), color);
			i = i + 0.1;
		}
		j = j + 0.1;
	}
}

float	vect_magnitude(t_pos pos, t_dir dir)
{
	float	x;
	float	y;

	x = (dir.x - pos.x) * (dir.x - pos.x);
	y = (dir.y - pos.y) * (dir.y - pos.y);
	return (sqrt(x + y));
}

t_dir	rotation(t_dir dir, float angle)
{
	t_dir	new_dir;

	new_dir.x = dir.x * (cos(angle) - sin(angle));
	new_dir.y = dir.y * (cos(angle) + sin(angle));
	return (new_dir);
}

// void	start_raycasting(float distance)
// {
// 	int	x;
// 	int	y;	
// }

float	distance(float a_x, float a_y)
{
	return (sqrt(a_x * a_x + a_y * a_y));
}

void	draw_dirction(t_data *data, t_pos pos, t_dir dir, float angle, int color)//rays
{
	float		i;

	//(void)dir;
	i = 0.1;
	
	while (data->map[(int)((pos.y + i * sin(angle)) / GRID_SQUAR)][(int)((pos.x + i * cos(angle)) / GRID_SQUAR)] != '1' && data->map[(int)((pos.y + i * sin(angle) + PI/2) / GRID_SQUAR)][(int)((pos.x + i * cos(angle) + PI/2) / GRID_SQUAR)] != '1')
	{
		my_mlx_pixel_put(data, pos.x + i * cos(angle), pos.y + i * sin(angle), color);
		i += 0.1;
	}
	data->dir = dir;
	if (data->dir.angle == angle)
		data->dist = distance(fabs(pos.x - pos.x + i * cos(angle)), fabs(pos.y - pos.y + i * sin(angle)));
	data->v_angle = angle;
	slow_version(data, distance(fabs(pos.x - pos.x + i * cos(angle)), fabs(pos.y - pos.y + i * sin(angle))));
	//printf("ray_x:%f, ray_y:%f\n",pos.x + i * cos(angle),  pos.y + i * sin(angle));
	//printf("pos_x:%f, pos_y:%f\n",pos.x,  pos.y);
	printf("distance:%f\n", distance(fabs(pos.x - pos.x + i * cos(angle)), fabs(pos.y - pos.y + i * sin(angle))));
	printf("angle of the ray:%f\n", angle);
	//get pos in plan
}

void	dir_vect(t_data *data, t_pos pos, t_dir dir, float angle, int color)
{
	float		i;

	(void)dir;
	i = 0.1;
	while (i <= GRID_SQUAR)
	{
		my_mlx_pixel_put(data, pos.x + i * cos(angle), pos.y + i * sin(angle), color);
		i += 0.1;
	}
}

void	plan_vect(t_data *data, t_pos pos, float angle, int color)
{
	float	a;
	float	ray_x;
	float	ray_y;

	ray_x = pos.x + GRID_SQUAR * cos(angle);
	ray_y = pos.y + GRID_SQUAR * sin(angle);
	a = 0;
	while (a < GRID_SQUAR * tan(PI / 5))
	{
		my_mlx_pixel_put(data, ray_x + a * cos(angle + PI / 2), ray_y + a * sin(angle + PI / 2), color);
		a = a + 0.1;
	}
	a = 0;
	while (a < GRID_SQUAR * tan(PI / 5))
	{
		my_mlx_pixel_put(data, ray_x + a * cos(angle - PI / 2), ray_y + a * sin(angle - PI / 2), color);
		a = a + 0.1;
	}
}

int	hit_wall(char **map, float next_x, float next_y)
{
	if (map[(int)((next_y) / GRID_SQUAR)][(int)(next_x / GRID_SQUAR)] == '1')
		return (1);
	return (0);
}

int	key_press(int key_code, t_data *data)
{
	static t_pos	pos;
	static t_dir	dir;
	float	direction;

	if (!pos.x && !pos.y)
	{
		pos.x = 75;
		pos.y = 75;
	}
	if (!dir.x && !dir.y && !dir.angle)
	{
		dir.angle = 0;
		dir.x = cos(dir.angle);
		dir.y = sin(dir.angle);
	}
	if (key_code == ESC)
		exit(1);
	(void)data;
	direction = 1;
	if (key_code == W && !is_player_will_hit_wall(pos.x + dir.x * SPEED, pos.y + dir.y * SPEED, data->map, dir))
	{
		pos.x += dir.x * SPEED;
		pos.y += dir.y * SPEED; 
	}
	if (key_code == S && !is_player_will_hit_wall(pos.x + (-1) * dir.x * SPEED, pos.y + (-1) * dir.y * SPEED, data->map, dir))
	{
		pos.x += (-1) * dir.x * SPEED;
		pos.y += (-1) * dir.y * SPEED;
	}
	if (key_code == D && !is_player_will_hit_wall(pos.x + (-1) * dir.y * SPEED, pos.y + dir.x * SPEED, data->map, dir))
	{
		pos.x += (-1) * dir.y * SPEED;
		pos.y += dir.x * SPEED; 
	}
	if (key_code == A && !is_player_will_hit_wall(pos.x + dir.y * SPEED, pos.y + (-1) * dir.x * SPEED, data->map, dir))
	{
		pos.x += dir.y * SPEED;
		pos.y += (-1) * dir.x * SPEED; 
	}
	if (key_code == RIGHT_ARR)
	{
		if (dir.angle + 0.1 >= 2 * PI)
			dir.angle = 0;
		dir.angle += 0.1;
		dir.x = cos(dir.angle);
		dir.y = sin(dir.angle);
	}
	if (key_code == LEFT_ARR)
	{
		if (dir.angle - 0.1 < 0)
			dir.angle = 2 * PI;
		dir.angle -= 0.1;
		dir.x = cos(dir.angle);
		dir.y = sin(dir.angle);
	}
	render_map(data, pos, dir);
	return (0);
}

int	close_win(void)
{
	exit(0);
	return (0);
}

void	player_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, ON_KEYDOWN, 0, key_press, data);
	mlx_hook(data->mlx_win, ON_DESTROY, 0, close_win, data);
	mlx_loop(data->mlx);
}
