/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 09:27:38 by iantar            #+#    #+#             */
/*   Updated: 2023/09/18 10:33:43 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_bonus.h"

unsigned int	get_color(t_texter anim, int x, int y)
{
	char	*dst;

	dst = anim.addr + y * anim.size_line + x * (anim.bits_per_pixel / 8);
	return (*(unsigned int *)dst);
}

void	animation(t_data *data)
{
	static int		frame;
	unsigned int	color[2];
	t_cor_int		img;
	t_cor_int		screen;

	img.y = -1;
	screen.y = SCREEN_HEIGHT - data->anim[frame / TIME].height;
	while (++img.y < data->anim[frame / TIME].height && screen.y < SCREEN_HEIGHT)
	{
		img.x = 0;
		screen.x = SCREEN_WIDTH / 2 - data->anim[frame / TIME].width / 2;
		(screen.x < 0 || screen.y < 0) && error_mesg("the texter is too big\n");
		while (img.x < data->anim[frame / TIME].width && screen.x < SCREEN_WIDTH)
		{
			color[0] = get_color(data->anim[frame / TIME], img.x, img.y);
			color[1] = color[0];
			if (color[1] >> 24 == 0)
				my_mlx_pixel_put(data, screen.x, screen.y, color[0]);
			img.x++;
			screen.x++;
		}
		screen.y++;
	}
	if (++frame > TIME * 12)
		frame = 0;
}
