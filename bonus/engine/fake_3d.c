/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:53:05 by iantar            #+#    #+#             */
/*   Updated: 2023/09/16 20:40:47 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_bonus.h"

void	put_texter(t_data *data, t_dda dda, int x, double tex)
{
	double			tmp;
	unsigned int	color;
	int				y1;
	double			line_h;

	line_h = SCREEN_HEIGHT / dda.distance;
	y1 = SCREEN_HEIGHT / 2 - line_h / 2;
	tmp = 0;
	data->dda = dda;
	while (y1 < SCREEN_HEIGHT / 2 + line_h / 2)
	{
		color = get_pixel_color(data, tex, (tmp / line_h));
		my_mlx_pixel_put(data, x, y1, color);
		y1++;
		tmp++;
	}
}

void	fake_3d(t_data *data, t_dda dda, int x, double tex)
{
	int	y1;

	y1 = -1;
	while (++y1 < SCREEN_HEIGHT / 2)
		my_mlx_pixel_put(data, x, y1, rgb_color(data->color.ceiling.r,
				data->color.ceiling.g, data->color.ceiling.b, y1 / 2));
	y1--;
	while (++y1 < SCREEN_HEIGHT)
		my_mlx_pixel_put(data, x, y1, rgb_color(data->color.floor.r,
				data->color.floor.g, data->color.floor.b, (SCREEN_HEIGHT - y1)
				/ 2));
	put_texter(data, dda, x, tex);
}
