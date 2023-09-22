/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_plus_texter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 03:48:34 by mkatfi            #+#    #+#             */
/*   Updated: 2023/09/19 15:34:13 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_mandatory.h"

void	check_colors_1(t_color *g, char **strs, char **s)
{
	if (!ft_strcmp (strs[0], "F"))
	{
		g->floor.r = ft_atoi (s[0]);
		g->floor.g = ft_atoi (s[1]);
		g->floor.b = ft_atoi (s[2]);
	}
	if (!ft_strcmp (strs[0], "C"))
	{
		g->ceiling.r = ft_atoi (s[0]);
		g->ceiling.g = ft_atoi (s[1]);
		g->ceiling.b = ft_atoi (s[2]);
	}
}

void	check_colors(t_data *p, t_color *g)
{
	char	**strs;
	char	**s;
	int		i;
	int		j;

	i = -1;
	while (p->mapm[++i])
	{
		strs = ft_split (p->mapm[i], ' ');
		if (strs[0] && ((!ft_strcmp (strs[0], "F"))
				|| (!ft_strcmp (strs[0], "C"))))
		{
			s = ft_split (strs[1], ',');
			j = 0;
			while (s[j])
				ft_atoi (s[j++]);
			if (j != 3)
				(freepath(s), freepath(strs),
					ft_error("ERROR\n"));
			check_colors_1(g, strs, s);
			freepath(s);
		}
		freepath(strs);
	}
}

void	plus_txter_and_fc_1(t_data *p, t_textures *txt)
{
	char	**strs;
	int		i;

	i = 0;
	while (p->mapm[i])
	{
		strs = ft_split (p->mapm[i], ' ');
		if (ft_aray_size (strs) != 2)
			ft_error ("ERROR textur no valid!\n");
		if (strs[0] && !ft_strcmp (strs[0], "NO"))
		{
			if (check_xpm (strs[1]) == 1)
				(freepath(strs), ft_error ("Error\n"));
			txt->no = ft_strdup(strs[1]);
		}
		if (strs[0] && !ft_strcmp (strs[0], "EA"))
		{
			if (check_xpm (strs[1]) == 1)
				(freepath(strs), ft_error ("Error\n"));
			txt->ea = ft_strdup(strs[1]);
		}
		freepath (strs);
		i++;
	}
}

void	plus_txter_and_fc_2(t_data *p, t_textures *txt)
{
	char	**strs;
	int		i;

	i = 0;
	while (p->mapm[i])
	{
		strs = ft_split (p->mapm[i], ' ');
		if (ft_aray_size (strs) != 2)
			(freepath(strs), ft_error ("ERROR textur no valid!\n"));
		if (strs[0] && !ft_strcmp(strs[0], "SO"))
		{
			if (check_xpm (strs[1]) == 1)
				(freepath(strs), ft_error ("Error\n"));
			txt->so = ft_strdup(strs[1]);
		}
		if (strs[0] && !ft_strcmp (strs[0], "WE"))
		{
			if (check_xpm (strs[1]) == 1)
				(freepath(strs), ft_error ("Error\n"));
			txt->we = ft_strdup(strs[1]);
		}
		freepath (strs);
		i++;
	}
}

void	plus_txter_and_fc(t_data *p, t_textures *txt, t_color *g)
{
	plus_txter_and_fc_1 (p, txt);
	plus_txter_and_fc_2 (p, txt);
	check_colors (p, g);
}
