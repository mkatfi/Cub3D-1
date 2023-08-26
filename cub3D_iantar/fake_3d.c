/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:53:05 by iantar            #+#    #+#             */
/*   Updated: 2023/08/26 15:07:54 by iantar           ###   ########.fr       */
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

void    fake_3d(t_data *data, double dist, int x, int tex)
{
    double line_h;
    int end;
    int y1;
    int y2;
   unsigned int    color;
    static  int check;

    
    int height;
    //(void)tex;
	int endian;
	int	width;
    if (!check)
    {
        data->texter.addr = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/iantar/Desktop/cub3d_team/cub3d/textures/almohad-_1_.xpm", &width, &height);
	    if (!data->texter.addr)
		    error_mesg("invalid texter\n");
	    data->texter.addr =  mlx_get_data_addr(data->texter.addr, &data->texter.bits_per_pixel, &data->texter.size_line, &endian);
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
    
    //if (dist < 1)
      //  dist = 1;//what the hwll is that
    line_h = SCREEN_HEIGHT / dist;
    y2 = SCREEN_HEIGHT / 2 - (int)(line_h / 2);
    end = SCREEN_HEIGHT / 2 + (int)(line_h / 2);
    double tmp = 0;
   // int bnb = line_h / GRID;
    while (y2 < end)
    {
        /**/
        //printf("here:%d\n", y2 / (line_h / GRID));
        if ((tmp / line_h) * GRID > 64)
        {
            printf("%f\n", (tmp / line_h) * GRID);
            //exit(1);
        }
        color = get_pixel_color(data, tex, (tmp / line_h) * GRID);
		my_mlx_pixel_put(data, x, y2, color);
        y2++;
        tmp++;

        /*
        my_mlx_pixel_put(data, x, y2, rgb_color(192,192,192, dist * 12));
        */
    }
}