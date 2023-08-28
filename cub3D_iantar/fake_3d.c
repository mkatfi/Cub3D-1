/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:53:05 by iantar            #+#    #+#             */
/*   Updated: 2023/08/28 09:39:44 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_iantar.h"
#include "../includes/includes_aouaziz.h"
#include "../includes/structures_iantar.h"
#include "../includes/structures_iantar.h"
#include "../includes/macros.h"

//void    ceiling_ground()
//{

//}

unsigned int modify_clor(unsigned int color, int density)
{
    unsigned int r;
    unsigned int g;
    unsigned int b;

    r = (color >> 16);
    g = (color >> 8);
    b = color;
    r -= density;
	g -= density;
	b -= density;
    if (r < 0)
        r = 0;
    if (g < 0)
        g = 0;
    if (b < 0)
        b = 0;
    return (r << 16 | g << 8 | b);
} 

void    fake_3d(t_data *data, t_dda dda, int x, int tex)
{
    double line_h;
    int end;
    int y1;
    int y2;
   unsigned int    color;
    static  int check;

    
   
    if (!check)
    {
        data->ea.img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/Cub3D/textures/ea.xpm", &data->ea.width, &data->ea.height);
        data->no.img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/Cub3D/textures/no.xpm", &data->no.width, &data->no.height);
        data->so.img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/Cub3D/textures/alaouite.xpm", &data->so.width, &data->so.height);
        data->we.img = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/Cub3D/textures/Almoravides.xpm", &data->we.width, &data->we.height);
	    if (!data->ea.img || !data->no.img || !data->so.img || !data->we.img)
		    error_mesg("invalid texter\n");
	    data->no.addr =  mlx_get_data_addr(data->no.img, &data->no.bits_per_pixel, &data->no.size_line, &data->no.endian);
	    data->so.addr =  mlx_get_data_addr(data->so.img, &data->so.bits_per_pixel, &data->so.size_line, &data->so.endian);
	    data->we.addr =  mlx_get_data_addr(data->we.img, &data->we.bits_per_pixel, &data->we.size_line, &data->we.endian);
	    data->ea.addr =  mlx_get_data_addr(data->ea.img, &data->ea.bits_per_pixel, &data->ea.size_line, &data->ea.endian);
        check++;
    }
    //printf("dddaatta:%p;\n", data->texter.addr);
    y1 = 0;
    while (y1 < SCREEN_HEIGHT / 2)
    {
        my_mlx_pixel_put(data, x, y1, rgb_color(0, 139, 139, y1 / 2));
        y1++;
    }
    while (y1 < SCREEN_HEIGHT)
    {
        my_mlx_pixel_put(data, x, y1, rgb_color(218, 165, 32, (SCREEN_HEIGHT - y1) / 2));
        y1++;
    }
    
    //if (dda.distance < 1)
      //  dda.distance = 1;//what the hwll is that
    line_h = SCREEN_HEIGHT / dda.distance;
    y2 = SCREEN_HEIGHT / 2 - line_h / 2;
    end = SCREEN_HEIGHT / 2 + line_h / 2;
    double tmp = 0;
    data->dda = dda;
   // int bnb = line_h / GRID;
    while (y2 < end)
    {
        color = get_pixel_color(data, tex, (tmp / line_h) * GRID);
       // printf("x=%d, y2= %d\n", x, y2);
		my_mlx_pixel_put(data, x, y2, color);
        y2++;
        tmp++;
    }
}

