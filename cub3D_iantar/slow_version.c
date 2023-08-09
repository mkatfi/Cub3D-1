/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slow_version.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:47:37 by iantar            #+#    #+#             */
/*   Updated: 2023/08/09 16:36:36 by iantar           ###   ########.fr       */
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
//hight = 500
//hight - dis

void	slow_version(t_data *data, float distance)
{
	//x == 24 * 50
	//y = 0
	int		y;
	int		x;
	int		wall;
	float	eps;
	int	cheat;
	
	printf("distance_before:%f\n", distance );
	eps = (1 - cos(data->v_angle - data->dir.angle)) * 50;//ep :0 --> sqrtf(data->l - 1)
	distance = distance - eps;
	if (data->v_angle == data->dir.angle)
		printf("distance_after:%f\n", distance );
	x = data->m_width * 50 + ((data->m_width * 50) / 2 + data->k * 450) ;
	//printf("k=%d\n", x);
	y = 0;
	wall = (data->m_height * 50 + 10) - distance;
	while (y < (data->m_height * 50 - wall) / 2)//sky ::light blue 0x0000FFFF
	{
		cheat = -1;
		//(int)(data->k * 100) % 3;											
		while (cheat++ < 20)
			my_mlx_pixel_put(data, x + cheat, y, CYAN);
		y++;
	}
	wall = wall + y;
	while (y < wall)//wall :gray  0x00808080
	{
		cheat = -1;
		while (cheat++ < 20)
			my_mlx_pixel_put(data,x + cheat, y , GRAY);
		y++;
	}
	while (y < data->m_height * 50)//ground :brawn 0x00FFD898
	{
		cheat = -1;
		while (cheat++ < 20)
			my_mlx_pixel_put(data, x + cheat, y, BRWON);
		
		y++;
	}
	
}