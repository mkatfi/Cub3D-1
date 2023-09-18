/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:34:55 by iantar            #+#    #+#             */
/*   Updated: 2023/09/16 20:54:14 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_bonus.h"

void	draw_square(t_data *data, t_cor_int cor, int grid, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < grid)
	{
		x = 0;
		while (x < grid)
		{
			my_mlx_pixel_put(data, cor.x * grid + x, cor.y * grid + y, color);
			x++;
		}
		y++;
	}
}

void	draw_player(t_data *data)
{
	double	angle;

	angle = 0;
	while (angle < 2 * PI)
	{
		line(data, angle, PLAYER_DIM / 2);
		angle += 0.1;
	}
}

void	mini_map(t_data *data)
{
	t_cor_int	cor;
	t_cor_int	m;

	cor.y = -1;
	m.y = data->pos.y - 5;
	while (++cor.y * MINI_GRID < SCREEN_HEIGHT / 5)
	{
		cor.x = -1;
		m.x = data->pos.x - 5;
		while (++cor.x * MINI_GRID < SCREEN_WIDTH / 5)
		{
			if ((m.x < 0 || m.y < 0) || (m.y >= data->m_height
					|| m.x >= data->m_width) || (data->map[m.y][m.x] == '1'))
				draw_square(data, cor, MINI_GRID, GRAY);
			else if (data->map[m.y][m.x] == 'D')
				draw_square(data, cor, MINI_GRID, BRWON);
			else
				draw_square(data, cor, MINI_GRID, CYAN);
			m.x++;
		}
		m.y++;
	}
	draw_player(data);
}
