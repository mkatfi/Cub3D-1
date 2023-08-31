/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 09:27:38 by iantar            #+#    #+#             */
/*   Updated: 2023/08/31 21:25:51 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_iantar.h"
#include "../includes/includes_aouaziz.h"
#include "../includes/structures_iantar.h"
#include "../includes/structures_iantar.h"
#include "../includes/macros.h"

unsigned int	get_color(t_texter anim, int x, int y)
{
	char	*dst;
	
	dst = anim.addr + y * anim.size_line + x * (anim.bits_per_pixel / 8);
	return (*(unsigned int *)dst);
}

void	animation(t_data *data)
{
	static int  frame;
	unsigned int	color;
	cor_int	img;
	cor_int	screen;
	int	color_tmp;

	img.x = 0;
	img.y = 0;
	screen.x = SCREEN_WIDTH / 2 - data->anim[frame / 50].width / 2;
	screen.y = SCREEN_HEIGHT -  data->anim[frame / 50].height;
	if (screen.x < 0 || screen.y < 0)
		error_mesg("the texter is too big\n");
	while (img.y < data->anim[frame / 50].height && screen.y < SCREEN_HEIGHT)
	{
		img.x = 0;
		screen.x = SCREEN_WIDTH / 2 - data->anim[frame / 50].width / 2;
		while (img.x < data->anim[frame / 50].width && screen.x < SCREEN_WIDTH)
		{
			color = get_color(data->anim[frame / 50], img.x, img.y);
			color_tmp = color;
			if (color_tmp >> 24 == 0)
				my_mlx_pixel_put(data, screen.x, screen.y, color);
			img.x++;
			screen.x++;
		}
		img.y++;
		screen.y++;
	}
	frame++;
	if (frame > 50 * 12)
		frame = 0;
}