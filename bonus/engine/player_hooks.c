/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 08:05:16 by iantar            #+#    #+#             */
/*   Updated: 2023/09/16 20:41:29 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_bonus.h"

void	go_up_down(t_data *data)
{
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
}

void	go_left_right(t_data *data)
{
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
}

void	turn_left_right(t_data *data)
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
	go_up_down(data);
	go_left_right(data);
	turn_left_right(data);
	render_map(data);
	dda_version(data);
	animation(data);
	mlx_mouse_hide(data->mlx, data->mlx_win);
	return (0);
}

void	player_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, ON_DESTROY, 1L << 0, close_win, data);
	mlx_hook(data->mlx_win, ON_KEYDOWN, 1L << 0, key_press, data);
	mlx_hook(data->mlx_win, ON_KEYUP, 1L << 1, key_up, data);
	mlx_hook(data->mlx_win, MOUSEMOVE, 1L << 6, mouse, data);
	mlx_loop_hook(data->mlx, game_loop, data);
}
