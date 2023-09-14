/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_used_check_map_in_main.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 01:52:09 by mkatfi            #+#    #+#             */
/*   Updated: 2023/09/14 11:55:42 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_iantar.h"

int	long_line(char **str)
{
	size_t	m;
	int		i;

	i = 0;
	m = ft_strlen(str[0]);
	while (str[i])
	{
		if (m < ft_strlen(str[i]))
			m = ft_strlen(str[i]);
		i++;
	}
	return (m);
}

int	ft_aray_size(char **s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	chaek_play_used(char **str)
{
	char	k;
	int		a;
	int		b;
	int		play;

	play = 0;
	a = -1;
	while (str[++a])
	{
		b = -1;
		while (str[a][++b])
		{
			if (str[a][b] == 'S' || str[a][b] == 'E' 
				|| str[a][b] == 'N' || str[a][b] == 'W')
			{
				play++;
				k = str[a][b];
			}
		}
	}
	if (play != 1)
		k = ' ';
	return (k);
}

int	check_play(t_data *p)
{
	char	k;
	int		a;
	int		b;

	k = chaek_play_used(p->map);
	if (k == 32)
		return (1);
	a = -1;
	while (p->map[++a])
	{
		b = -1;
		while (p->map[a][++b])
		{
			if (p->map[a][b] == 'N' || p->map[a][b] == 'S' 
				|| p->map[a][b] == 'W' || p->map[a][b] == 'E') 
				p->player = k;
			else if (p->map[a][b] != '0' && p->map[a][b] != '1' 
				&& p->map[a][b] != ' ' && p->map[a][b] != 'D')
				return (1);
			else if (k != 32)
				if (cheack_map(p->map, k) == 1)
					return (1);
		}
	}
	return (0);
}

void	check_cub(char	*str)
{
	int		i;
	char	*s;

	i = 0;
	s = ft_strrchr(str, '.');
	while (str[i])
		i++;
	if (ft_strchr(str, '.') == 0)
		ft_error("Error .cub\n");
	else if (ft_strcmp(s, ".cub") != 0)
		ft_error("Error .cub\n");
}
