/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:42:16 by iantar            #+#    #+#             */
/*   Updated: 2023/08/09 16:03:37 by iantar           ###   ########.fr       */
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

void	render_map(t_data *data, t_pos pos, t_dir dir)
{
	int	i;
	int	j;
	int	endian;
	static	int	check;

	i = 0;
	j = 0;
	if (!check)
	{
		data->img = mlx_new_image(data->mlx, 24 * GRID_SQUAR, data->m_height * GRID_SQUAR);//data->m_width = 24
		data->get_adr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &endian);
	}
	check = 1;
	while (i < data->m_height * GRID_SQUAR)
	{
		j = 0;
		while (j < data->m_width * GRID_SQUAR)
		{
			if (data->map[i / GRID_SQUAR][j / GRID_SQUAR] == '1')
			{
				if (!(i % GRID_SQUAR) || !(j % GRID_SQUAR))
					my_mlx_pixel_put(data, j, i, WITE);
				else
					my_mlx_pixel_put(data, j, i, BLACK);
			}
			else
			{
				if (!(i % GRID_SQUAR) || !(j % GRID_SQUAR))
					my_mlx_pixel_put(data, j, i, BLACK);
				else
					my_mlx_pixel_put(data, j, i, WITE);
			}
			j++;
		}
		i++;
	}
	draw_player(pos, PLAYER_DIM, data, RED);
	float	k = 0;
	while (k <= PI / 5)
	{
		data->k = k;
		draw_dirction(data, pos, dir, dir.angle + k, NEON_GREEN);//add k as a parameter
		k += 0.01;
		printf("x=k*10=%f\n", k * 10);
	}
	k = 0;
	while (k <= PI / 5)
	{
		data->k = k * (-1);
		draw_dirction(data, pos, dir, dir.angle - k, NEON_GREEN);
		k += 0.01;
		//printf("x=k*10=%f\n", (-1) * (k * 10));
		//PI/5 - k
	}
	dir_vect(data, pos, dir, dir.angle, RED);
	plan_vect(data, pos, dir.angle, BLUE);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
