/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:24:36 by mkatfi            #+#    #+#             */
/*   Updated: 2023/09/19 12:43:09 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_bonus.h"

int	check_txter_1(char **s)
{
	char	**strs;
	int		i;
	int		no;
	int		so;

	i = -1;
	no = 0;
	so = 0;
	while (s && s[++i])
	{
		strs = ft_split(s[i], ' ');
		if (strs[0] && !ft_strcmp(strs[0], "NO"))
			no++;
		if (strs[0] && !ft_strcmp(strs[0], "SO"))
			so++;
		freepath(strs);
	}
	if (so != 1 || no != 1)
		return (1);
	return (0);
}

int	check_txter_2(char **s)
{
	char	**strs;
	int		i;
	int		ea;
	int		we;

	i = -1;
	ea = 0;
	we = 0;
	while (s && s[++i])
	{
		strs = ft_split(s[i], ' ');
		if (strs[0] && !ft_strcmp(strs[0], "EA"))
			ea++;
		if (strs[0] && !ft_strcmp(strs[0], "WE"))
			we++;
		freepath(strs);
	}
	if (we != 1 || ea != 1)
		return (1);
	return (0);
}

int	check_txter_3(char **s)
{
	char	**strs;
	int		i;
	int		c;
	int		f;

	i = -1;
	c = 0;
	f = 0;
	while (s && s[++i])
	{
		strs = ft_split(s[i], ' ');
		if (strs[0] && !ft_strcmp(strs[0], "F"))
			f++;
		if (strs[0] && !ft_strcmp(strs[0], "C"))
			c++;
		freepath(strs);
	}
	if (c != 1 || f != 1)
		return (1);
	return (0);
}
