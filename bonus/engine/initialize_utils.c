/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:33:28 by iantar            #+#    #+#             */
/*   Updated: 2023/09/16 20:41:13 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_bonus.h"

t_pos	get_pos(char **map)
{
	t_pos	pos;
	int		i;
	int		j;

	j = -1;
	pos.x = 1;
	pos.y = 1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'S' || map[j][i] == 'W'
				|| map[j][i] == 'E')
			{
				pos.x = i + 0.5;
				pos.y = j + 0.5;
				return (pos);
			}
		}
	}
	return (pos);
}

char	get_player(char **map)
{
	int	i;
	int	j;

	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'S' || map[j][i] == 'W'
				|| map[j][i] == 'E')
				return (map[j][i]);
		}
	}
	return (map[j][i]);
}

t_dir	get_dir(char **map)
{
	t_dir	dir;
	char	player;

	player = get_player(map);
	if (player == 'N')
	{
		dir.x = 0;
		dir.y = -1;
	}
	else if (player == 'W')
	{
		dir.x = 0;
		dir.y = 1;
	}
	else if (player == 'S')
	{
		dir.x = -1;
		dir.y = 0;
	}
	else
	{
		dir.x = 1;
		dir.y = 0;
	}
	return (dir);
}

t_plan	get_plan(t_dir dir)
{
	t_plan	plan;

	plan.x = 0.66;
	plan.y = 0;
	if (dir.x)
	{
		plan.x = 0;
		if (dir.x > 0)
			plan.y = 0.66;
		else
			plan.y = -0.66;
	}
	else
	{
		if (dir.y > 0)
			plan.x = -0.66;
	}
	return (plan);
}
