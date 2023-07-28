/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 08:05:16 by iantar            #+#    #+#             */
/*   Updated: 2023/07/28 09:56:03 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_iantar.h"
#include "../includes/includes_aouaziz.h"
#include "../includes/structures_iantar.h"
#include "../includes/structures_iantar.h"
#include "../includes/macros.h"

void	draw_player(int x, int y, int r, t_data *data)
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
	static int x, y;

	if (key_code == ESC)
		exit(1);
	(void)data;
	if (key_code == W && y > 0)
	{
		data->pos_y = --y;
	}
	if (key_code == S && y + 10 < data->m_height * 50)
		data->pos_y = ++y;
	if (key_code == D && x + 15 < data->m_width * 50)
		data->pos_x = ++x;
	if (key_code == A && x > 0)
		data->pos_x = --x;
	printf("key_code :%d\n", key_code);
	render_map(data, x + 10, y + 10);
	//mlx_destroy_image(data->mlx, data->img);
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
	//render_map(data);
	//mlx_loop_hook(data->mlx, key_press, data);
	mlx_loop(data->mlx);
}
