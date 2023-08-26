/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slow_version.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:47:37 by iantar            #+#    #+#             */
/*   Updated: 2023/08/23 09:23:56 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_iantar.h"
#include "../includes/includes_aouaziz.h"
#include "../includes/structures_iantar.h"
#include "../includes/structures_aouaziz.h"
#include "../includes/macros.h"
# define RANDOM 55

int	operation()
{
	return (0);
}

//max_dis = 562 --> height / 10
//min_dis = 5  ---> height 
//hight = GRID0
//hight - dis

void	slow_version(t_data *data, double distance)
{
	//x == 24 * GRID
	//y = 0
	int		y;
	int		x;
	int		wall;
	double	eps;
	int	cheat;
	
	cheat = 0;
	printf("distance_before:%f\n", distance );
	eps = (1 - cos(data->v_angle - data->dir.angle)) * GRID;//ep :0 --> sqrtf(data->l - 1)
	distance = distance - eps;
	if (data->v_angle == data->dir.angle)
		printf("distance_after:%f\n", distance );
	x = data->m_width * GRID + ((data->m_width * GRID) / 2 + data->k * GRID * 9) ;
	y = 0;
	distance = distance + data->dist * cos(data->v_angle - data->dir.angle);
	while (y < (data->m_height * GRID) / 2)//sky ::light blue 0x0000FFFF
	{
		cheat = -1;
		while (cheat++ < 10)
			my_mlx_pixel_put(data, x + cheat, y, CYAN);
		y++;
	}
	while (y < data->m_height * GRID)//ground :brawn 0x00FFD898
	{
		cheat = -1;
		while (cheat++ < 10)
			my_mlx_pixel_put(data, x + cheat, y, BRWON);
		
		y++;
	}
	wall = (data->m_height * GRID) - distance / 6;
	y = distance / 5;
	while (y < wall)//wall :gray  0x00808080
	{
		cheat = -1;
		while (cheat++ < 10)
			my_mlx_pixel_put(data,x + cheat, y , GRAY);
		y++;
	}
}