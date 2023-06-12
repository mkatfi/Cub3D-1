/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:28:35 by iantar            #+#    #+#             */
/*   Updated: 2023/06/01 23:09:03 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	get_hight_map(int fd)
{
	char	*line;
	int		len;
	//int		fd;

	len = 0;
	//fd = open(map_name, O_RDONLY, 0644);
	if (fd == -1)
		return (write(2, "fd can't open\n", 14), -1);
	line = get_next_line(fd);
	while (line)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	//close(fd);
	return (len);
}

int	get_width_map(int fd)
{
	char	*line;
	int		len;
	//int		fd;

	len = 0;
	//fd = open(map_name, O_RDONLY, 0644);
	if (fd == -1)
		return (write(2, "fd can't open\n", 14), -1);
	line = get_next_line(fd);
	if (line)
	{
		while (line[len] && line[len] != '\n')
			len++;
		free(line);
	}
	//close(fd);
	return (len);
}

char	*rm_new_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '\n')
			line[i] = '\0';
	}
	return (line);
}

char	**get_map(char *map_name)
{
	char	**map;
	char	*line;
	t_vars	var;

	var.fd = open(map_name, O_RDONLY, 0644);
	if (var.fd < 0)
		return (NULL);
	var.hight = get_hight_map(var.fd);
	close(var.fd);
	var.fd = open(map_name, O_RDONLY, 0644);
	var.width = get_width_map(var.fd);
	close(var.fd);
	var.fd = open(map_name, O_RDONLY, 0644);
	 printf("var.hight:%d,  var.width:%d\n", var.hight, var.width);
	map = malloc(sizeof(char *) * (var.hight + 2));
	var.i = 0;
	line = get_next_line(var.fd);
	printf("line:%s", line);
	while (line)
	{
		//map[var.i] = ft_strdup(line);
		map[var.i] = ft_strdup(rm_new_line(line));
		//free(line);
		line = get_next_line(var.fd);
		(var.i)++;
		
	}
	map[var.i] = NULL;
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

void	put_square(int x, int y, int size, t_data data)
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
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, x, y);
}

int	len_ptr(char **ptr)
{
	int	len;

	len = 0;
	while (ptr[len])
		len++;
	return (len);
}

void	render_map(t_data data)
{
	int	i;
	int	j;
	int	width;
	int	hight;

	i = 0;
	j = 0;
	width = ft_strlen(data.map[0]);
	hight = len_ptr(data.map);
	while (i < hight)
	{
		j = 0;
		while (j < width)
		{
			if (data.map[i][j] == '1')
				put_square(j * 100, i * 100, 100, data);
			j++;
		}
		i++;
	}
	
}

//char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
int	main(int ac, char *av[])
{
	t_data	data;

	if (ac != 2)
		return (0);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1000, 1000, "Cub3D");
	data.map = get_map(av[1]);
	//print_map(data.map);
	if (!data.map || !*data.map)
		return (0);
	render_map(data);
	//put_square(0, 0, 100, data);
	mlx_loop(data.mlx);
}
