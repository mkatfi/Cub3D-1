/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:28:35 by iantar            #+#    #+#             */
/*   Updated: 2023/05/23 22:49:41 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	high_count(fd)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	len = 0;
	while (line)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	return (len);
}

// int	width_count()
// {
// 	char	*line;
	
// }

// char	**read_map(fd)
// {
// 	char	*line;

// 	line = get_next_line(fd);
	
// }

char	**get_map(void)
{
	char	**map;
	int		i;
	int		j;
	char	c;

	map = malloc(sizeof(char *) * 11);
	i = 0;
	while (i < 10)
	{
		map[i] = malloc(11 * sizeof(char));
		j = 0;
		while (j < 10)
		{
			if (i == 0 || i == 9 || j == 0 || j == 9 || i == j)
				c = '1';
			else
				c = '0';
			map[i][j] = c;
			j++;
		}
		map[i][j] = '\0';
		i++;		
	}
	map[i] = NULL;
	return (map);
}

void	print_map(char **map)
{
	int	i;

	i = -1;
	while (++i < 11)
		printf("%s\n", map[i]);
}

void	draw_square(int ref, int size, t_data data)
{
	int	x;
	int	y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			mlx_pixel_put(data.mlx, data.mlx_win, x + ref, y + ref, 0x00FF0000);
			y++;
		}
		x++;
	}
}

void	put_square(t_pos pos, int size, t_data data)
{
	int	i;
	int	bits_per_pixel;
	int	size_line;
	int	endian;

	i = 0;
	data.img = mlx_new_image(data.mlx, size, size);
	data.get_adr = mlx_get_data_addr(data.img, &bits_per_pixel, &size_line, &endian);
	while (i < size * size_line)
	{
		if (i % 4 == 0)
			data.get_adr[i] = 0;//bleu
		if (i % 4 == 1)
			data.get_adr[i] = 0;//green
		if (i % 4 == 2)
		data.get_adr[i] = -1;//red
		if (i % 4 == 3)
			data.get_adr[i] = 0;//more it become big the color becames less bright 
		i++;
	}
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, pos.x, pos.y);
}

void	render_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (map[i][j] == '')
		}
	}
	
}

//char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
int	main(void)
{
	t_pos	pos;
	t_data	data;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1000, 1000, "Cub3D");
	data.map = get_map();
	pos.x = 0;
	pos.y = 0;
	data.map = get_map();
	render_map(data);
	put_square(pos, 100, data);
	//printf("bits_per_pixel:%d, size_line:%d, endian:%d\n", bits_per_pixel, size_line, endian);
	mlx_loop(data.mlx);
}
