/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:33:39 by itaharbo          #+#    #+#             */
/*   Updated: 2025/03/20 17:09:12 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	swap(int *tab, size_t size)
{
	int	tmp;

	if (size < 2)
		return ;
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
}

void	sa(int *tab_a, size_t size_a)
{
	swap(tab_a, size_a);
}

void	sb(int *tab_b, size_t size_b)
{
	swap(tab_b, size_b);
}

void	ss(int *tab_a, size_t size_a, int *tab_b, size_t size_b)
{
	swap(tab_a, size_a);
	swap(tab_b, size_b);
}
/*
#include <stdio.h>

int     main()
{
        int     	tab_a[5] = {5, 6, 1};
        int     	tab_b[5] = {3};
	size_t	size_a;
        size_t	i;

        i = 0;
	size_a = 3;
        while (i < 5)
        {
                printf("%d  %d\n", tab_a[i], tab_b[i]);
                i++;
        }
        printf("a  b\n\n");
        i = 0;
        swap(tab_a, size_a);
        while (i < 5)
        {
                printf("%d  %d\n", tab_a[i], tab_b[i]);
                i++;
        }
        printf("a  b\n");
        return (0);
}*/
