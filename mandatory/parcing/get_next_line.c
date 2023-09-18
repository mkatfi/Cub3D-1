/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:37:53 by mkatfi            #+#    #+#             */
/*   Updated: 2023/09/16 20:44:33 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_mandatory.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	s = malloc(count * size);
	if (!s)
		return (NULL);
	while (i < count * size)
	{
		s[i] = 0;
		i++;
	}
	return ((void *)s);
}

size_t	ft_gstrlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*g;
	int		i;
	int		j;

	i = 0;
	g = malloc(sizeof(char) * (ft_gstrlen(s2) + ft_gstrlen(s1)) + 1);
	if (!g)
	{
		free(s1);
		return (NULL);
	}
	while (s1 && s1[i])
	{
		g[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		g[i++] = s2[j++];
	g[i] = '\0';
	free(s1);
	return (g);
}

char	*ft_read(int fd, char *container)
{
	char	*buff;
	int		i;

	i = 1;
	buff = ft_calloc(BUFFER_SIZE + 1 * sizeof(char), 1);
	if (!buff)
		return (NULL);
	while (i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			free(container);
			return (NULL);
		}
		buff[i] = '\0';
		container = ft_strjoin(container, buff);
	}
	free(buff);
	return (container);
}

char	*get_next_line(int fd)
{
	static char	*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = ft_read(fd, s);
	return (s);
}
