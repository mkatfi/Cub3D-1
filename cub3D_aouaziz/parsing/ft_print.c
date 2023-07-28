/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:12:00 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/27 09:35:45 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/includes_aouaziz.h"
#include "../../includes/includes_iantar.h"
#include "../../includes/macros.h"
#include "../../includes/structures_aouaziz.h"
#include "../../includes/structures_iantar.h"


void	print_str(char **str)
{
	int	i;

	for (i = 0; str[i] != NULL; i++)
	{
		printf("%s\n", str[i]);
	}
}
void print_textur(const t_textur *textur)
{
    const t_textur *current = textur;

    while (current != NULL)
    {
        printf("Type: %d, File: %s\n", current->type, current->file);
        current = current->next;
    }
}

void print_cube3d(const t_cube3d *cube)
{
    printf("F: %d\n", cube->F);
    printf("C: %d\n", cube->C);
    printf("Player: %c\n", cube->player);
    printf("X: %d\n", cube->x);
    printf("Y: %d\n", cube->y);
    printf("Len: %d\n", cube->len);
    printf("I: %d\n", cube->i);
	printf("Map Length: %d\n", cube->m_width);
	printf("Map Height: %d\n", cube->m_height);

    printf("Map:\n");
    print_str(cube->map);

    printf("Textur:\n");
    print_textur(cube->textur);
}
