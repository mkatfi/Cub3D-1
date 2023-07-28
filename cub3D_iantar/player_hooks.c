/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 08:05:16 by iantar            #+#    #+#             */
/*   Updated: 2023/07/28 15:58:24 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_iantar.h"
#include "../includes/includes_aouaziz.h"
#include "../includes/structures_iantar.h"
#include "../includes/structures_iantar.h"
#include "../includes/macros.h"

void	player_direction(int x, int y, float a, t_data *data)
{
	int	i;

	i = 0;
	while (i < 50)
	{
		printf("pos_x:%f\n", data->pos_x);
		printf("pos_y:%f\n", data->pos_y);
		my_mlx_pixel_put(data, x + i * cos(a), y + i * sin(a), RED);
		i++;
	}
}

void	draw_player(float x, float y, int r, t_data *data)
{
	float	i, j;

	j = 0;
	while (j < r)
	{
		i = 0;
		while (i < 180)
		{
			my_mlx_pixel_put(data, x + j * cos(i), y + j * sin(i), RED);
			i = i + 0.5;
		}
		j = j + 0.1;
	}
}

int	key_press(int key_code, t_data *data)
{
	static float x, y;
	int	i, j;
	static float	angle;

	if (!x && !y)
	{
		x = 75;
		y = 75;
	}
	if (key_code == ESC)
		exit(1);
	(void)data;
	i = x;
	j = y;
	if (key_code == W && y + 5 > 0 && data->map[(j - 2 * SPEED) / 50][i / 50] != '1')
	{
		y = y + SPEED * sin(angle);
		x = x + SPEED * cos(angle);
		data->pos_y = y;
		data->pos_x = x;
	}
	if (key_code == S && y + 14 + SPEED < data->m_height * 50 && data->map[(j + SPEED) / 50][i / 50] != '1')
	{
		y = y + SPEED * sin(angle);
		x = x + SPEED * cos(angle);
		data->pos_y = y;
		data->pos_x = x;
	}
	if (key_code == D && x + 14 + SPEED < data->m_width * 50 && data->map[j / 50][(i + SPEED) / 50] != '1')
	{
		y = y + SPEED * sin(angle);
		x = x + SPEED * cos(angle);
		data->pos_y = y;
		data->pos_x = x;
	}
	if (key_code == A && x + 5 > 0 && data->map[j / 50][(i - 2 * SPEED) / 50] != '1')
	{
		y = y + SPEED * sin(angle);
		x = x + SPEED * cos(angle);
		data->pos_y = y;
		data->pos_x = x;
	}
	if (key_code == LEFT_ARR)
	{
		angle = angle - 0.1;
	}
	if (key_code == RIGHT_ARR)
	{
		angle = angle + 0.1;
	}
	render_map(data, x, y, angle);
	//mlx_destroy_image(data->mlx, data->img);
	return (0);
}

// int	key_press(int key_code, t_data *data)
// {
// 	static float x, y;
// 	int	i, j;
// 	static float	angle;

// 	if (!x && !y)
// 	{
// 		x = 75;
// 		y = 75;
// 	}
// 	if (key_code == ESC)
// 		exit(1);
// 	(void)data;
// 	i = x;
// 	j = y;
// 	if (key_code == W && y + 5 > 0 && data->map[(j - 2 * SPEED) / 50][i / 50] != '1')
// 	{
// 		y -= SPEED;
// 		data->pos_y = y + SPEED * sin(angle);
// 		data->pos_x = x + SPEED * cos(angle);
// 	}
// 	if (key_code == S && y + 14 + SPEED < data->m_height * 50 && data->map[(j + SPEED) / 50][i / 50] != '1')
// 	{
// 		y += SPEED;
// 		data->pos_y = y + SPEED * sin(angle);
// 		data->pos_x = x + SPEED * cos(angle);
// 	}
// 	if (key_code == D && x + 14 + SPEED < data->m_width * 50 && data->map[j / 50][(i + SPEED) / 50] != '1')
// 	{
// 		x += SPEED;
// 		data->pos_y = y + SPEED * sin(angle);
// 		data->pos_x = x + SPEED * cos(angle);
// 	}
// 	if (key_code == A && x + 5 > 0 && data->map[j / 50][(i - 2 * SPEED) / 50] != '1')
// 	{
// 		x -= SPEED;
// 		data->pos_y = y + SPEED * sin(angle);
// 		data->pos_x = x + SPEED * cos(angle);
// 	}
// 	if (key_code == LEFT_ARR)
// 	{
// 		angle = angle - 0.1;
// 	}
// 	if (key_code == RIGHT_ARR)
// 	{
// 		angle = angle + 0.1;
// 	}
// 	render_map(data, x, y, angle);
// 	//mlx_destroy_image(data->mlx, data->img);
// 	return (0);
// }

int	close_win(void)
{
	exit(0);
	return (0);
}

void	player_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, ON_KEYDOWN, 0, key_press, data);
	mlx_hook(data->mlx_win, ON_DESTROY, 0, close_win, data);
	//render_map(data);
	//mlx_loop_hook(data->mlx, key_press, data);
	mlx_loop(data->mlx);
}
