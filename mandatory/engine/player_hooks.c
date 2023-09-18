/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 08:05:16 by iantar            #+#    #+#             */
/*   Updated: 2023/09/16 20:44:33 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_mandatory.h"

t_pos	check_moves(t_data *data, int key)
{
	t_pos	check;

	if (key == W)
	{
		check.x = data->pos.x + data->dir.x * SPEED;
		check.y = data->pos.y + data->dir.y * SPEED;
	}
	else if (key == S)
	{
		check.x = data->pos.x + (-1) * data->dir.x * SPEED;
		check.y = data->pos.y + (-1) * data->dir.y * SPEED;
	}
	else if (key == A)
	{
		check.x = data->pos.x + data->dir.y * SPEED;
		check.y = data->pos.y + (-1) * data->dir.x * SPEED;
	}
	else
	{
		check.x = data->pos.x + (-1) * data->dir.y * SPEED;
		check.y = data->pos.y + data->dir.x * SPEED;
	}
	return (check);
}

void	move(t_data *data)
{
	if (data->input[0] == S && !hit_wall(data, S))
	{
		data->pos.x += (-1) * data->dir.x * SPEED;
		data->pos.y += (-1) * data->dir.y * SPEED;
	}
	if (data->input[0] == W && !hit_wall(data, W))
	{
		data->pos.x += data->dir.x * SPEED;
		data->pos.y += data->dir.y * SPEED;
	}
	if (data->input[1] == A && !hit_wall(data, A))
	{
		data->pos.x += data->dir.y * SPEED;
		data->pos.y += (-1) * data->dir.x * SPEED;
	}
	if (data->input[1] == D && !hit_wall(data, D))
	{
		data->pos.x += (-1) * data->dir.y * SPEED;
		data->pos.y += data->dir.x * SPEED;
	}
}

void	turn(t_data *data)
{
	int	c;

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
}

int	game_loop(t_data *data)
{
	move(data);
	turn(data);
	render_map(data);
	dda_version(data);
	mlx_mouse_hide(data->mlx, data->mlx_win);
	return (0);
}

void	player_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, ON_DESTROY, 1L << 0, close_win, data);
	mlx_hook(data->mlx_win, ON_KEYDOWN, 1L << 0, key_press, data);
	mlx_hook(data->mlx_win, ON_KEYUP, 1L << 1, key_up, data);
	mlx_loop_hook(data->mlx, game_loop, data);
}
