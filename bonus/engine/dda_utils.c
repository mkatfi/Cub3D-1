/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:07:27 by iantar            #+#    #+#             */
/*   Updated: 2023/09/17 11:06:14 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_bonus.h"

double	magnitude(double x, double y)
{
	return (sqrt(x * x + y * y));
}

double	distace_between(t_pos pos, t_cor_int ray_map)
{
	return (magnitude(fabs(pos.x - ray_map.x), fabs(pos.y - ray_map.y)));
}

int	ray_hit_wall(t_data *data, t_info *info)
{
	return (info->ray_map.y >= 0 && info->ray_map.y < data->m_height
		&& info->ray_map.x >= 0 && info->ray_map.x < data->m_width
		&& data->map[info->ray_map.y][info->ray_map.x] != '1');
}

int	check_door(t_data *data, t_info *info)
{
	return (data->map[info->ray_map.y][info->ray_map.x] == 'D'
		&& (data->door.state || distace_between(data->pos, info->ray_map) > 2));
}
