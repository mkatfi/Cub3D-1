/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_check_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:01:42 by mkatfi            #+#    #+#             */
/*   Updated: 2023/09/16 20:44:33 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_mandatory.h"

int	ft_check(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0' || str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	cheack_map(char **str, char c)
{
	int	i;
	int	j;

	i = 0;
	if (ft_check(str[i], c) == 1
		|| ft_check(str[ft_aray_size(str) - 1], c) == 1)
		return (1);
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '0' || str[i][j] == c)
			{
				if (j == 0 || str[i + 1][j] == ' ' || str[i - 1][j] == ' '
					|| str[i][j + 1] == ' ' || str[i][j - 1] == ' ')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	plus_espice_used(t_data *p, int i)
{
	char	*buffer;
	int		j;

	if (p->m_height < p->m_width)
	{
		buffer = malloc(p->m_width + 1);
		j = 0;
		while (p->map[i][j])
		{
			buffer[j] = p->map[i][j];
			j++;
		}
		while (j < p->m_width)
		{
			buffer[j] = ' ';
			j++;
		}
		buffer[j] = '\0';
		free(p->map[i]);
		p->map[i] = buffer;
	}
}

int	plus_espice(t_data *p)
{
	int	i;

	p->m_width = long_line(p->map);
	i = 0;
	while (p->map[i])
	{
		p->m_height = ft_aray_size(p->map);
		plus_espice_used(p, i);
		i++;
	}
	if (check_play(p))
		return (1);
	if (cheack_map(p->map, '0'))
		return (1);
	return (0);
}
