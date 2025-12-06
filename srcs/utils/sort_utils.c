/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:01:06 by itaharbo          #+#    #+#             */
/*   Updated: 2025/03/22 14:33:05 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(int *tab, size_t size, size_t *min_index)
{
	int		min;
	size_t	i;

	min = tab[0];
	*min_index = 0;
	i = 1;
	while (i < size)
	{
		if (tab[i] < min)
		{
			min = tab[i];
			*min_index = i;
		}
		i++;
	}
	return (min);
}

size_t	find_clos_index(int *tab_a, size_t size_a, int median)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = size_a - 1;
	while (i <= size_a / 2)
	{
		if (tab_a[i] >= median)
			break ;
		i++;
	}
	while (j > size_a / 2)
	{
		if (tab_a[j] >= median)
			break ;
		j--;
	}
	if (i <= size_a - j)
		return (i);
	return (j);
}
