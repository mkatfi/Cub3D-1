/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:42:16 by iantar            #+#    #+#             */
/*   Updated: 2023/07/28 13:15:18 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_iantar.h"
#include "../includes/includes_aouaziz.h"
#include "../includes/structures_iantar.h"
#include "../includes/structures_aouaziz.h"
#include "../includes/macros.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->get_adr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	render_map(t_data *data, float pos_x, float pos_y, float angle)
{
	int	i;
	int	j;
	int	endian;
	static	int	check;

	i = 0;
	j = 0;
	if (!check)
	{
		data->img = mlx_new_image(data->mlx, data->m_width * 50, data->m_height * 50);
		data->get_adr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &endian);
	}
	check = 1;
	while (i < data->m_height * 50)
	{
		j = 0;
		while (j < data->m_width * 50)
		{
			if (!(i % 50) || !(j % 50))
				my_mlx_pixel_put(data, j, i, BLACK);
			else if (data->map[i / 50][j / 50] == '1')
				my_mlx_pixel_put(data, j, i, 0x00aea587);
			else
				my_mlx_pixel_put(data, j, i, 0x004e4187);
			j++;
		}
		i++;
	}
	draw_player(pos_x, pos_y, 5, data);
	player_direction(pos_x, pos_y, angle, data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
