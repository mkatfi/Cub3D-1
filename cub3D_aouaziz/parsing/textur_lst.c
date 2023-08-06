/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textur_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:58:21 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/27 15:53:51 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes_aouaziz.h"
#include "../../includes/includes_iantar.h"
#include "../../includes/macros.h"
#include "../../includes/structures_aouaziz.h"
#include "../../includes/structures_iantar.h"

t_cube3d	*add_textur_to_list(t_cube3d *cube, char *content, int type)
{
	t_textur	*new;

	new = ft_malloc(sizeof(t_textur));
	if (!new)
		return (NULL);
	new->type = type;
	new->file = ft_strdup(content);
	new->next = NULL;
	ft_textur_list_add_back(&cube->textur, new);
	return (cube);
}

void	ft_textur_list_add_back(t_textur **lst, t_textur *new)
{
	t_textur	*i;

	if (!new)
		return ;
	i = ft_textur_lst_last(*lst);
	if (!i)
		*lst = new;
	else
		i->next = new;
}
t_textur	*ft_textur_lst_last(t_textur *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		if (lst->next == 0)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstsize_textur(t_textur *lst)
{
	int i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
