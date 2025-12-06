/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:52:21 by itaharbo          #+#    #+#             */
/*   Updated: 2025/03/14 04:32:40 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(int *src, size_t *size_src, int *dest, size_t *size_dest)
{
	size_t	i;

	if (*size_src == 0)
		return ;
	i = *size_dest;
	while (i > 0)
	{
		dest[i] = dest[i - 1];
		i--;
	}
	dest[0] = src[0];
	(*size_dest)++;
	i = 0;
	while (i < (*size_src - 1))
	{
		src[i] = src[i + 1];
		i++;
	}
	if (*size_src > 0)
		src[*size_src - 1] = 0;
	(*size_src)--;
}

void	pa(int *tab_a, size_t *size_a, int *tab_b, size_t *size_b)
{
	push(tab_b, size_b, tab_a, size_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(int *tab_a, size_t *size_a, int *tab_b, size_t *size_b)
{
	push(tab_a, size_a, tab_b, size_b);
	ft_putstr_fd("pb\n", 1);
}
/*
#include <stdio.h>

int	main()
{
	int		tab_a[4] = {4, 3, 2, 1};
	int		tab_b[4] = {};
	size_t	size_a;
	size_t	size_b;
	size_t	i;

	size_a = 4;
	size_b = 0;
	i = 0;
	while (i < 4)
	{
    	printf("%d  %d\n", tab_a[i], tab_b[i]);
        i++;
	}
	printf("a  b\n\n");
	i = 0;
	push(tab_a, &size_a, tab_b, &size_b);
	while (i < 4)
	{
		printf("%d  %d\n", tab_a[i], tab_b[i]);
		i++;
	}
	printf("a  b\n");
	return (0);
}*/