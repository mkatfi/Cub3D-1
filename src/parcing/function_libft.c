/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_libft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:36:40 by mkatfi            #+#    #+#             */
/*   Updated: 2023/09/16 20:43:16 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_bonus.h"

void	check_digit(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			ft_error("ERROR NOT DIGIt\n");
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] == 32)
		i++;
	check_digit(str);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nb = (str[i] - 48) + nb * 10;
		i++;
	}
	if (nb >= 0 && nb <= 255)
		return (nb);
	else
	{
		ft_error("ERROR int not valide\n");
		return (0);
	}
}

void	freepath(char **ptr)
{
	int	i;

	i = 0;
	while (ptr && ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

char	*ft_strrchr(char *s, int c)
{
	int		i;
	char	*k;

	k = (char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (k[i] == (char)c)
			return (k + i);
		i--;
	}
	return (NULL);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		if (str[i++] == c)
			return (1);
	return (0);
}
