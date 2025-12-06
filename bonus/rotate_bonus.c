/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:25:09 by itaharbo          #+#    #+#             */
/*   Updated: 2025/03/20 17:08:48 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rotate(int *tab, size_t size)
{
	size_t	i;
	int		tmp;

	if (size <= 1)
		return ;
	i = 0;
	tmp = tab[0];
	while (i < size - 1)
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[size - 1] = tmp;
}

void	ra(int *tab_a, size_t size_a)
{
	rotate(tab_a, size_a);
}

void	rb(int *tab_b, size_t size_b)
{
	rotate(tab_b, size_b);
}

void	rr(int *tab_a, size_t size_a, int *tab_b, size_t size_b)
{
	rotate(tab_a, size_a);
	rotate(tab_b, size_b);
}
/*

#include <stdio.h>

int     main()
{
        int     tab_a[5] = {5, 6, 1, 4, 3};
        int     tab_b[5] = {0};
	size_t	size_a;
        size_t	i;

        i = 0;
	size_a = 5;
        while (i < 5)
        {
                printf("%d  %d\n", tab_a[i], tab_b[i]);
                i++;
        }
        printf("a  b\n\n");
        i = 0;
        rotate(tab_a, size_a);
        while (i < 5)
        {
                printf("%d  %d\n", tab_a[i], tab_b[i]);
                i++;
        }
        printf("a  b\n");
        return (0);
}*/
