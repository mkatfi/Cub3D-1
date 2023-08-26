/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 08:31:14 by aouaziz           #+#    #+#             */
/*   Updated: 2023/08/15 14:58:50 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	slen;

	slen = ft_strlen(s1) + 1;
	s = ft_malloc(slen * sizeof(char));
	if (!s)
		return (0);
	s = ft_memcpy(s, s1, slen);
	return (s);
}
char	*ft_cstrdup(const char *s1)
{
	char	*s;
	size_t	slen;

	slen = ft_strlen(s1) + 1;
	s = ft_calloc(slen , sizeof(char));
	if (!s)
		return (0);
	s = ft_memcpy(s, s1, slen);
	return (s);
}
char	*ft_cub_strdup(const char *s1,int len)
{
	int	i;
	char	*ptr;

	i = 0;
	ptr = ft_calloc((len + 1) * 400, sizeof(char));
	if (!ptr)
		return (0);
	while (i < ft_strlen(s1))
	{
		ptr[i] = ((char *)s1)[i];
		i++;
	}
	while (i < len)
	{
		ptr[i] = ' ';
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}