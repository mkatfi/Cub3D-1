/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_wall_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:38:57 by iantar            #+#    #+#             */
/*   Updated: 2023/09/17 14:48:25 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_bonus.h"

t_pos	check_up(t_data *data, int x_y)
{
	t_pos	check;

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
	return (check);
}

t_pos	check_down(t_data *data, int x_y)
{
	t_pos	check;

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
	return (check);
}

t_pos	check_left(t_data *data, int x_y)
{
	t_pos	check;

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
	return (check);
}

t_pos	check_right(t_data *data, int x_y)
{
	t_pos	check;

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
	return (check);
}

/// @brief this function will check if your next 
	//move will hit a wall , if yes it will return 1
/// @param data position and diraction and ...
/// @param key which key you press
/// @param x_y it describe witch side you will move,
	// it help when you want to gliss on the wall
/// @return 1 if it hits the wall, 0 otherwise.

int	hit_wall_(t_data *data, int key, int x_y)
{
	int		i;
	t_pos	check;

	i = 0;
	if (key == W)
		check = check_up(data, x_y);
	else if (key == S)
		check = check_down(data, x_y);
	else if (key == A)
		check = check_left(data, x_y);
	else
		check = check_right(data, x_y);
	while (i < 2 * PI)
	{
		if (data->map[(int)(check.y + 0.2 * sin(i))][(int)(check.x + 0.2
				* cos(i))] == '1')
			return (1);
		if (data->map[(int)(check.y + 0.2 * sin(i))][(int)(check.x + 0.2
				* cos(i))] == 'D' && data->door.state)
			return (1);
		i += PI / 3;
	}
	return (0);
}
