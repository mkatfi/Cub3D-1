/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 06:10:40 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/25 08:39:34 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	 ft_print_error(char *str)
{
	printf("\033[91m%s", str);//sderr or sdin ?
	exit(1);
}
