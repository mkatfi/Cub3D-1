/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textuers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:07:46 by iantar            #+#    #+#             */
/*   Updated: 2023/08/26 13:37:57 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_iantar.h"
#include "../includes/includes_aouaziz.h"
#include "../includes/structures_iantar.h"
#include "../includes/structures_aouaziz.h"
#include "../includes/macros.h"

// unsigned int get_texl()
// {
	
// }

unsigned int	get_pixel_color(t_data *data, int x, int y)
{
	char	*dst;

	//printf("in get_:%p\n", data->texter.addr);
	//printf("wallx:%d\n", x);
	dst = data->texter.addr + (y * data->texter.size_line + x * (data->texter.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	set_textuers(t_data *data)
{
	int width;
	int height;
	int endian;
	int	wallx;
	unsigned	int	color;

	wallx = 0;
	data->texter.addr = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/cub3d_team/cub3d/textures/texter.xpm", &width, &height);
	if (!data->texter.addr)
		error_mesg("invalid texter\n");
	data->texter.addr =  mlx_get_data_addr(data->texter.addr, &data->texter.bits_per_pixel, &data->texter.size_line, &endian);
	int	 x, y = 0;
	x = 0;
	while (y < height)
	{
		color = get_pixel_color(data, x, y);
		//printf("%u\n", color);
		my_mlx_pixel_put(data, wallx, y, color);
		y++;
	}
	get_pixel_color(data, x, y);
	//printf("width:%d, height:%d\n", width, height);
}