/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textuers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:07:46 by iantar            #+#    #+#             */
/*   Updated: 2023/09/11 22:56:41 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_iantar.h"

unsigned int	get_pixel_color(t_data *data, int x, double y)
{
	char	*dst;

	if (x < 0 || y < 0 || x > 64 || y > 64)
	{
		
		return (0);
	}
	if (data->dda.side == NO)
	{
		dst = data->no.addr + ((int)(y * data->no.height) * data->no.size_line + (x * (data->no.width / GRID)) * (data->no.bits_per_pixel / 8));
	}
	else if (data->dda.side == WE)
	{
		dst = data->we.addr + ((int)(y * data->we.height) * data->we.size_line + (x * (data->we.width / GRID)) * (data->we.bits_per_pixel / 8));
	}
	else if (data->dda.side == SO)
	{
		dst =  data->so.addr + ((int)(y * data->so.height) * data->so.size_line + (x * (data->so.width / GRID)) * (data->so.bits_per_pixel / 8));
	}
	else
	{
		dst = data->ea.addr + ((int)(y * data->ea.height) * data->ea.size_line + (x * (data->ea.width / GRID)) * (data->ea.bits_per_pixel / 8));
	}
	return (*(unsigned int *)dst);
}
