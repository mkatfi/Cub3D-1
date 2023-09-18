/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:16:02 by iantar            #+#    #+#             */
/*   Updated: 2023/09/16 22:31:52 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/includes_bonus.h"

int	main(int ac, char *av[])
{
	t_data		data;
	t_textures	txt;
	t_color		g;
	char		**map;

	if (ac != 2)
		error_mesg("Ivalide Number of Arguments\n");
	check_cub(av[1]);
	map = git_map(av[1]);
	partition_map(map, &data);
	if (check_txter(map) == 1)
		(freepath(map), ft_error("Error1\n"));
	freepath(map);
	plus_txter_and_fc(&data, &txt, &g);
	if (plus_espice(&data) == 1)
		(freepath(data.map), freepath(data.mapm), ft_error("Error2\n"));
	initialize(&data, &txt);
	data.txt = txt;
	data.color = g;
	render_map(&data);
	player_hooks(&data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
