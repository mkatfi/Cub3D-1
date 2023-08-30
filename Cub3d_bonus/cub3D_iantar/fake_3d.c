/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:53:05 by iantar            #+#    #+#             */
/*   Updated: 2023/08/30 13:36:33 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_iantar.h"
#include "../includes/includes_aouaziz.h"
#include "../includes/structures_iantar.h"
#include "../includes/structures_iantar.h"
#include "../includes/macros.h"

unsigned int modify_clor(unsigned int color, int density)
{
	unsigned int r;
	unsigned int g;
	unsigned int b;

	r = (color >> 16);
	g = (color >> 8);
	b = color;
	r -= density;
	g -= density;
	b -= density;
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	return (r << 16 | g << 8 | b);
} 

void    fake_3d(t_data *data, t_dda dda, int x, int tex)
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
		//if (data->map[data->pos.x + (dda.distance * dir.x)])
		color = get_pixel_color(data, tex, (tmp / line_h));
		my_mlx_pixel_put(data, x, y2, color);
		y2++;
		tmp++;
	}
}
