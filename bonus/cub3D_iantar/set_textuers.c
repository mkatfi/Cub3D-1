/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textuers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:07:46 by iantar            #+#    #+#             */
/*   Updated: 2023/09/14 15:14:26 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_iantar.h"

unsigned int	get_pixel_color(t_data *data, double x, double y)
{
	char	*dst;

	if (x < 0 || y < 0 || x > 64 || y > 64)
		return (0);
	if (data->dda.door)//to check
		dst = data->door.addr + ((int)(y * data->door.height) * data->door.size_line + (int)(x * (data->door.width)) * (data->door.bits_per_pixel / 8));
	else if (data->dda.side == NO)
		dst = data->no.addr + ((int)(y * data->no.height) * data->no.size_line + (int)(x * (data->no.width)) * (data->no.bits_per_pixel / 8));
	else if (data->dda.side == WE)
		dst = data->we.addr + ((int)(y * data->we.height) * data->we.size_line + (int)(x * (data->we.width)) * (data->we.bits_per_pixel / 8));
	else if (data->dda.side == SO)
		dst =  data->so.addr + ((int)(y * data->so.height) * data->so.size_line + (int)(x * (data->so.width)) * (data->so.bits_per_pixel / 8));
	else
		dst = data->ea.addr + ((int)(y * data->ea.height) * data->ea.size_line + (int)(x * (data->ea.width)) * (data->ea.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
