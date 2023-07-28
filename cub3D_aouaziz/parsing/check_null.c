/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_null.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:18:02 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/26 16:56:22 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes_aouaziz.h"
#include "../../includes/includes_iantar.h"
#include "../../includes/macros.h"
#include "../../includes/structures_aouaziz.h"
#include "../../includes/structures_iantar.h"

int	check_Null_Character(char **map, int i, int j)
{
	int	len;

	len = ft_strlen(map[i]);
	if (ft_strlen(map[i + 1]) != 0 && ft_strlen(map[i - 1]) != 0)
	{
		if (map[i + 1][j] == '\0' || map[i - 1][j] == '\0')
			return (0);
	}
	if ((len - 1 >= j + 1) && (len - 1 <= j - 1))
	{
		if (map[i][j + 1] == '\0' || map[i][j - 1] == '\0')
			return (0);
	}
	return (1);
}
void	check_Zero_Surroundings(t_cube3d *cube)
{
	int		i;
	int		j;
	int		p;
	char	**map;

	i = 0;
	p = 0;
	map = cube->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' && check_Null_Character(map, i, j))
			{
				if (map[i][j + 1] == ' ' || map[i][j - 1] == ' ' ||
					map[i + 1][j] == ' ' || map[i - 1][j] == ' ')
					ft_print_error("Invalid Map - Spaces Around '0'\n");
			}
			j++;
		}
		i++;
	}
}
int	ft_skip_new_line(char **line, int y)
{
	while (line[y][0] == '\n')
		y++;
	return (y);
}

void	check_Map_Line(char **line, int x)
{
	int	i;

	i = 0;
	while (line[x][i])
	{
		if (line[x][i] != '1' && line[x][i] != ' ' && line[x][i] != '\n')
			ft_print_error("Invalid Map - Map Not Closed\n");
		i++;
	}
}
void	check_First_Line(char *line)
{
	int	len;

	len = 0;
	while (line[len] != '\n' && line[len] != '\0')
		len++;
	len--;
	while (line[len] == ' ')
		len--;
	if (line[0] != '1' || line[len] != '1')
		ft_print_error("Invalid Map - Map Not Closed\n");
	free(line);
}
