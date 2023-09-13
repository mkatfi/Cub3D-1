/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:17:36 by iantar            #+#    #+#             */
/*   Updated: 2023/09/12 04:10:37 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_iantar.h"

// size_t  ft_strlen(char *str)
// {
// 	size_t  len;

// 	len = 0;
// 	while (str[len])
// 		len++;
// 	return (len);
// }

void	error_mesg(char *msg)
{
    write(2, msg, ft_strlen(msg));
    exit(1);
}
