/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:35:56 by mkatfi            #+#    #+#             */
/*   Updated: 2023/09/02 15:49:14 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int reset_to_zero(int *x_ptr,int *y_ptr,int *z_ptr){
	*x_ptr = 0;
	*y_ptr = 0;
	*z_ptr = 0;
	return (0);
}

int main()
{
    int a;
	int *x = &a;
	int y;
	int z;

    // *x == a
    a = 15;
	y = 55;
	z = 41;
	reset_to_zero(x,&y,&z);
	printf("++>%d == %d +++ %d\n", a, y , z);
}