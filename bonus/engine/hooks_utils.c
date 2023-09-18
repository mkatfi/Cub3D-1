/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:03:34 by iantar            #+#    #+#             */
/*   Updated: 2023/09/17 14:43:24 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_bonus.h"

int	close_win(t_data *data)
{
	destroy_everything(data);
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
	return (0);
}

int	mouse(int key_code, int y, t_data *data)
{
	static int	save;

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

int	key_press(int key_code, t_data *data)
{
	if (key_code == SP)
	{
		if (data->door.state)
			data->door.state = DOOR_OPEND;
		else if (data->map[(int)data->pos.y][(int)data->pos.x] != 'D')
			data->door.state = DOOR_CLOSED;
	}
	if (key_code == ESC)
		close_win(data);
	if (key_code == W || key_code == S)
		data->input[0] = key_code;
	if (key_code == D || key_code == A)
		data->input[1] = key_code;
	if (key_code == RIGHT_ARR || key_code == LEFT_ARR)
		data->input[2] = key_code;
	return (0);
}

void	rotate(double *x, double *y, double angle)
{
	double	tmp;

	tmp = *x;
	*x = (*x) * cos(angle) - (*y) * sin(angle);
	*y = tmp * sin(angle) + (*y) * cos(angle);
}
