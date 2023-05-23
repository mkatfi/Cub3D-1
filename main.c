/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:28:35 by iantar            #+#    #+#             */
/*   Updated: 2023/05/23 12:14:00 by iantar           ###   ########.fr       */
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

// int	width_count(fd)
// {
// 	char	*line;
	
// }

// char	**read_map(fd)
// {
// 	char	*line;

// 	line = get_next_line(fd);
	
// }

char	**get_map()
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * 10);
	while (i < )
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	char	*map;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Cub3D");
	
	mlx_pixel_put(mlx, mlx_win, 500, 500, 0x00FF0000);
	mlx_loop(mlx);
}