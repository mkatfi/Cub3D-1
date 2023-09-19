/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:17:36 by iantar            #+#    #+#             */
/*   Updated: 2023/09/18 15:00:06 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_mandatory.h"

void	destroy_evrything(t_data *data)
{
	freepath(data->map);
	freepath(data->mapm);
	free(data->txt.ea);
	free(data->txt.so);
	free(data->txt.no);
	free(data->txt.we);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->img);
}

double	magnitude(double x, double y)
{
	return (sqrt(x * x + y * y));
}

void	error_mesg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}
