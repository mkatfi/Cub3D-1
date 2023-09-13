/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 08:05:16 by iantar            #+#    #+#             */
/*   Updated: 2023/09/12 11:06:35 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_iantar.h"

int	close_win(void)
{
	exit(0);
	return (0);
}

int	key_up(int key_code, t_data *data)
{
	if (key_code == W || key_code == S)
		data->input[0] = -1;
	if (key_code == D || key_code == A)
		data->input[1] = -1;
	if (key_code == RIGHT_ARR || key_code == LEFT_ARR)
		data->input[2] = -1;
	if (key_code == SP)
	{
		data->door.state = DOOR_CLOSED;
		data->input[3] = -1;
	}
	return 0;
}	


void	rotate(double *x, double *y, double angle)
{
	double tmp;

	tmp = *x;
	*x = (*x) * cos(angle) - (*y) * sin(angle);
	*y = tmp * sin(angle) + (*y) * cos(angle);
}

int	key_press(int key_code, t_data *data)
{
	if (key_code == SP)
		data->input[3] = SP;
	if (key_code == ESC)
		close_win();
	if (key_code == W || key_code == S)
		data->input[0] = key_code;
	if (key_code == D || key_code == A)
		data->input[1] = key_code;
	if (key_code == RIGHT_ARR || key_code == LEFT_ARR)
		data->input[2] = key_code;
	return 0;
}

int	hit_wall_(t_data *data, int key, int x_y)
{
	int	i;
	t_pos	check;

	i = 0;
	if (key == W)
	{
		if (!x_y)
		{
			check.x = data->pos.x + data->dir.x * SPEED;
			check.y = data->pos.y;
		}
		else
		{
			check.x = data->pos.x;
			check.y = data->pos.y + data->dir.y * SPEED;
		}
	}
	else if (key == S)
	{
		if (!x_y)
		{
			check.x = data->pos.x + (-1) * data->dir.x * SPEED;
			check.y = data->pos.y;
		}
		else
		{
			check.x = data->pos.x;
			check.y = data->pos.y + (-1) * data->dir.y * SPEED;
		}
	}
	else if (key == A)
	{
		if (!x_y)
		{
			check.x = data->pos.x + data->dir.y * SPEED;
			check.y = data->pos.y;
		}
		else
		{
			check.x = data->pos.x;
			check.y = data->pos.y + (-1) * data->dir.x * SPEED;
		}
	}
	else if (key == D)
	{
		if (!x_y)
		{
			check.x = data->pos.x + (-1) * data->dir.y * SPEED;
			check.y = data->pos.y;
		}
		else
		{
			check.x = data->pos.x;
			check.y = data->pos.y + data->dir.x * SPEED;
		}
	}
	while (i < 2 * PI)
	{
		if (data->map[(int)(check.y + 0.2 * sin(i))][(int)(check.x + 0.2 * cos(i))] == '1')
			return (1);
		if (data->map[(int)(check.y + 0.2 * sin(i))][(int)(check.x + 0.2 * cos(i))] == 'D' && data->door.state)
			return (1);
		i += PI / 3;
	}
	return (0);
}

int	game_loop(t_data *data)
{
	int	c;

	while  (data->map[(int)data->pos.y][(int)data->pos.x] == 'D')
	{
		if (data->input[0] == W)
		{
			data->pos.x += data->dir.x * SPEED * 10;//dyalax had 10??
			data->pos.y += data->dir.y * SPEED * 10;
		}
		if (data->input[0] == S)
		{
			data->pos.x += (-1) * data->dir.x * SPEED * 10;
			data->pos.y += (-1) * data->dir.y * SPEED * 10;
		}
		if (data->input[1] == D)
		{
			data->pos.x += (-1) * data->dir.y * SPEED * 10;
			data->pos.y += data->dir.x * SPEED * 10;
		}
		if (data->input[1] == A)
		{
			data->pos.x += data->dir.y * SPEED * 10;
			data->pos.y += (-1) * data->dir.x * SPEED * 10;
		}
	}
	if (data->input[0] == W)
	{
		if (!hit_wall_(data, W, X_TEX))
			data->pos.x += data->dir.x * SPEED;
		if (!hit_wall_(data, W, Y_TEX))
			data->pos.y += data->dir.y * SPEED;
	}
	if (data->input[0] == S)
	{
		if (!hit_wall_(data, S, X_TEX))
			data->pos.x += (-1) * data->dir.x * SPEED;
		if (!hit_wall_(data, S, Y_TEX))
			data->pos.y += (-1) * data->dir.y * SPEED;
	}
	if (data->input[1] == A)
	{
		if (!hit_wall_(data, A, X_TEX))
			data->pos.x += data->dir.y * SPEED;
		if (!hit_wall_(data, A, Y_TEX))
			data->pos.y += (-1) * data->dir.x * SPEED;
	}
	if (data->input[1] == D)
	{
		if (!hit_wall_(data, D, X_TEX))
			data->pos.x += (-1) * data->dir.y * SPEED;
		if (!hit_wall_(data, D, Y_TEX))
			data->pos.y += data->dir.x * SPEED;
	}
	if (data->input[2] == RIGHT_ARR)
	{
		c = 1;
		rotate(&data->dir.x, &data->dir.y, 0.03 * c);
		rotate(&data->plan.x, &data->plan.y, 0.03 * c);
	}
	if (data->input[2] == LEFT_ARR)
	{
		c = -1;
		rotate(&data->dir.x, &data->dir.y, 0.03 * c);
		rotate(&data->plan.x, &data->plan.y, 0.03 * c);
	}
	if (data->input[3] == SP)
	{
		//printf("OPEN\n");
		data->door.state = DOOR_OPEND;
	}
	// else
	// 	printf("NOT\n");
	render_map(data);//??
	dda_version(data);
	animation(data);
	return (0);
}

int	mouse(int key_code, int y, t_data *data)
{
	static int save;

	if (key_code > save)
	{
		rotate(&data->dir.x, &data->dir.y, 0.03);
		rotate(&data->plan.x, &data->plan.y, 0.03);
	}
	else if (key_code < save)
	{
		rotate(&data->dir.x, &data->dir.y, 0.03 * (-1));
		rotate(&data->plan.x, &data->plan.y, 0.03 * (-1));
	}
	save = key_code;
	return (0);
	(void)y;
}

void	player_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, ON_DESTROY, 1L << 0, close_win, data);
	mlx_hook(data->mlx_win, ON_KEYDOWN, 1L << 0 , key_press, data);
	mlx_hook(data->mlx_win, ON_KEYUP, 1L << 1, key_up, data);
	mlx_hook(data->mlx_win, MOUSEMOVE, 1L << 6, mouse, data);
	mlx_loop_hook(data->mlx, game_loop, data);
}
