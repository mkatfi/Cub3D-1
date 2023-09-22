/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_read_and_partition_map.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:53:03 by mkatfi            #+#    #+#             */
/*   Updated: 2023/09/19 15:34:32 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_mandatory.h"

char	**git_map(char *srt)
{
	char	**m;
	char	*buff;
	int		fd;

	fd = open(srt, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error not file\n", 16);
		exit(1);
	}
	buff = get_next_line(fd);
	close(fd);
	if (!buff || !buff[0])
		return (NULL);
	if (check_newline(buff))
		(free(buff), ft_error("ERROR\n"));
	else if (check_newline(buff) == 2)
		(free(buff), ft_error("ERROR\n"));
	m = ft_split(buff, '\n');
	return (free(buff), m);
}

void	partition_map2(char **s, t_data *p, int i)
{
	int	j;
	int	k;

	j = 0;
	k = ft_aray_size(s);
	if (k == 0)
		ft_error("file is empty\n");
	p->map = malloc(sizeof(char *) * ((k - 6) + 1));
	while (s && s[i])
		p->map[j++] = ft_strdup(s[i++]);
	p->map[j] = NULL;
}

void	partition_map(char **s, t_data *p)
{
	int	i;

	i = 0;
	p->mapm = (char **)malloc(sizeof(char *) * 7);
	while (s && s[i] && i < 6)
	{
		p->mapm[i] = ft_strdup(s[i]);
		i++;
	}
	p->mapm[i] = NULL;
	partition_map2 (s, p, i);
}
