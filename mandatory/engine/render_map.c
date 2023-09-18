/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:42:16 by iantar            #+#    #+#             */
/*   Updated: 2023/09/16 20:44:33 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_mandatory.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > SCREEN_WIDTH * 2 || y > SCREEN_HEIGHT)
		return ;
	dst = data->get_adr + (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	rgb_color(int r, int g, int b, int density)
{
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

void	render_map(t_data *data)
{
	static int	check;
	int			endian;

	if (!check)
	{
		data->img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
		data->get_adr = mlx_get_data_addr(data->img,
				&data->bits_per_pixel, &data->line_length, &endian);
		check = 1;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
