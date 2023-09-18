/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_check_newline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 03:38:49 by mkatfi            #+#    #+#             */
/*   Updated: 2023/09/16 20:44:33 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_mandatory.h"

int	chek_comma(char *s)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == ',')
			k++;
		i++;
	}
	if (k != 4)
		return (1);
	return (0);
}

int	check_chek(char *s)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s && s[i])
	{
		if (s[i] != '\n' && s[i + 1] == '\n')
		{
			k++;
			if (k == 6)
			{
				i++;
				break ;
			}
		}
		i++;
	}
	while (s && s[i])
	{
		if (s[i] == '1' && s[i + 1] == '1')
			return (i);
		i++;
	}
	return (0);
}

int	check_newline(char *s)
{
	int	i;

	i = check_chek(s);
	if (chek_comma(s) == 1)
		return (2);
	while (s[i])
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}
