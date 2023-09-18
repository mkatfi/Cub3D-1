/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:53:05 by iantar            #+#    #+#             */
/*   Updated: 2023/09/16 20:44:33 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_mandatory.h"

void	fake_3d(t_data *data, t_dda dda, int x, int tex)
{
	double			line_h;
	int				y1;
	unsigned int	color;
	double			tmp;

	y1 = -1;
	while (++y1 < SCREEN_HEIGHT / 2)
		my_mlx_pixel_put(data, x, y1, rgb_color(data->color.ceiling.r,
				data->color.ceiling.g, data->color.ceiling.b, y1 / 2));
	y1--;
	while (++y1 < SCREEN_HEIGHT)
		my_mlx_pixel_put(data, x, y1, rgb_color(data->color.floor.r,
				data->color.floor.g, data->color.floor.b,
				(SCREEN_HEIGHT - y1) / 2));
	line_h = SCREEN_HEIGHT / dda.distance;
	y1 = SCREEN_HEIGHT / 2 - line_h / 2 - 1;
	tmp = -1;
	data->dda = dda;
	while (++y1 < SCREEN_HEIGHT / 2 + line_h / 2)
	{
		color = get_pixel_color(data, tex, (++tmp / line_h));
		my_mlx_pixel_put(data, x, y1, color);
	}
}
