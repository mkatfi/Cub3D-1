/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:53:05 by iantar            #+#    #+#             */
/*   Updated: 2023/09/12 10:45:20 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_iantar.h"

void    fake_3d(t_data *data, t_dda dda, int x, double tex)
{
	double line_h;
	int end;
	int y1;
	int y2;
	unsigned int	color;

	y1 = 0;
	while (y1 < SCREEN_HEIGHT / 2)
	{
		my_mlx_pixel_put(data, x, y1, rgb_color(0, 139, 139, y1 / 2));
		y1++;
	}
	while (y1 < SCREEN_HEIGHT)
	{
		my_mlx_pixel_put(data, x, y1, rgb_color(218, 165, 32, (SCREEN_HEIGHT - y1) / 2));
		y1++;
	}
	line_h = SCREEN_HEIGHT / dda.distance;
	y2 = SCREEN_HEIGHT / 2 - line_h / 2;
	end = SCREEN_HEIGHT / 2 + line_h / 2;
	double tmp = 0;
	data->dda = dda;
	while (y2 < end)
	{
		// if (dda.distance > 2)
		// 	data->door.state = DOOR_CLOSED;
		color = get_pixel_color(data, tex, (tmp / line_h));
		my_mlx_pixel_put(data, x, y2, color);
		y2++;
		tmp++;
	}
}
