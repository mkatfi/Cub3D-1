/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:19:54 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/25 14:14:44 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if(s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strlen_array(char **array)
{
	int length = 0;
	int i;
	i = 0;
	if (array == NULL)
		return (0);

	while (array[i] != NULL)
	{
		length++;
		i++;
	}
	return (length);
}
