/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:55:46 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/28 18:48:27 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes_aouaziz.h"
#include "../../includes/includes_iantar.h"
#include "../../includes/macros.h"
#include "../../includes/structures_aouaziz.h"
#include "../../includes/structures_iantar.h"

void	start_Map(t_cube3d *cube)
{
	if (cube->map[0] == NULL)
		ft_print_error("Invalid Map\n");
	check_Map_Not_Closed(cube->map);
	cube = check_Map_Lines(cube);
	print_cube3d(cube);
}


// int	main(int ac, char *av[])
// {
//  	t_cube3d	*cube;

// 	cube = ft_malloc(sizeof(t_cube3d));
// 	cube = initialize_Cube3D(cube);
// 	if (ac != 2)
// 		ft_print_error("Incorrect Number of Arguments\n");
// 	check_File_And_Read_it(av[1]);
// }
