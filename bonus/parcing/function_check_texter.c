/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_check_texter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:06:32 by mkatfi            #+#    #+#             */
/*   Updated: 2023/09/11 22:57:22 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_iantar.h"

int	rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	check_txter(char **s)
{
	char	**strs;
	int		i;
	int		c;

	i = -1;
	c = 0;
	while (s && s[++i])
	{
		strs = ft_split (s[i], ' ');
		if (strs[0] && !ft_strcmp(strs[0], "NO"))
			c++;
		if (strs[0] && !ft_strcmp(strs[0], "EA"))
			c++;
		if (strs[0] && !ft_strcmp(strs[0], "SO"))
			c++;
		if (strs[0] && !ft_strcmp(strs[0], "WE"))
			c++;
		if (strs[0] && (!ft_strcmp(strs[0], "F") || !ft_strcmp(strs[0], "C")))
			c++;
		freepath(strs);
	}
	if (c != 6)
		return (1);
	return (0);
}

int	check_xpm(char	*str)
{
	int		i;
	char	*s;

	i = 0;
	s = ft_strrchr(str, '.');
	while (str[i])
		i++;
	if (i < 5)
		return (1);
	else if (ft_strchr(str, '.') == 0)
		return (1);
	else if (ft_strcmp(s, ".xpm") != 0)
		return (1);
	/* if(check_path(str)== 1)
	 	return(1);*/
	return (0);
}

int	check_path(char *s)
{
	int	i;
	int	fd;

	i = -1;
	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (1);
	while (s[++i])
		if (s[i] == 32)
			return (1);
	return (0);
}
