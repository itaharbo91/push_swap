/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:44:36 by itaharbo          #+#    #+#             */
/*   Updated: 2025/03/20 17:09:00 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rrotate(int *tab, size_t size)
{
	size_t	i;
	int		tmp;

	if (size <= 1)
		return ;
	i = size - 1;
	tmp = tab[i];
	while (i > 0)
	{
		tab[i] = tab[i - 1];
		i--;
	}
	tab[0] = tmp;
}

void	rra(int *tab_a, size_t size_a)
{
	rrotate(tab_a, size_a);
}

void	rrb(int *tab_b, size_t size_b)
{
	rrotate(tab_b, size_b);
}

void	rrr(int *tab_a, size_t size_a, int *tab_b, size_t size_b)
{
	rrotate(tab_a, size_a);
	rrotate(tab_b, size_b);
}
/*

#include <stdio.h>

int     main()
{
        int     tab_a[5] = {3, 1};
        int     tab_b[5] = {1};
	size_t	size_a;
        size_t	i;

        i = 0;
	size_a = 2;
        while (i < 5)
        {
                printf("%d  %d\n", tab_a[i], tab_b[i]);
                i++;
        }
        printf("a  b\n\n");
        i = 0;
        rrotate(tab_a, size_a);
        while (i < 5)
        {
                printf("%d  %d\n", tab_a[i], tab_b[i]);
                i++;
        }
        printf("a  b\n");
        return (0);
}*/
