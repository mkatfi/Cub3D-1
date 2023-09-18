/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:46:21 by iantar            #+#    #+#             */
/*   Updated: 2023/09/18 10:15:24 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_mandatory.h"

int	close_win(t_data *data)
{
	destroy_evrything(data);
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

void	rotate(double *x, double *y, double angle)
{
	double	tmp;

	tmp = *x;
	*x = (*x) * cos(angle) - (*y) * sin(angle);
	*y = tmp * sin(angle) + (*y) * cos(angle);
}

/// @brief this function will check if your next 
	//move will hit a wall , if yes it will return 1
/// @param data position and diraction and ...
/// @param key which key you press
/// @return 1 if it hits the wall, 0 otherwise.

int	hit_wall(t_data *data, int key)
{
	int		i;
	t_pos	check;

	i = 0;
	check = check_moves(data, key);
	while (i < 2 * PI)
	{
		if (data->map[(int)(check.y + 0.05 * sin(i))][(int)(check.x + 0.05
				* cos(i))] == '1')
			return (1);
		i += PI / 3;
	}
	return (0);
}

int	key_press(int key_code, t_data *data)
{
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
