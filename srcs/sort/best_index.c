/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:44:03 by itaharbo          #+#    #+#             */
/*   Updated: 2025/03/14 04:35:14 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_insert_pos_b(int *tab_b, size_t size_b, int element)
{
	size_t		i;
	size_t		best_pos;
	long long	best_diff;
	long long	diff;

	if (size_b == 0)
		return (0);
	i = 0;
	best_pos = 0;
	best_diff = LLONG_MAX;
	while (i < size_b)
	{
		diff = (long long)element - (long long)tab_b[i];
		if (diff < 0)
			diff = -diff;
		if (diff < best_diff)
		{
			best_diff = diff;
			best_pos = i;
		}
		i++;
	}
	if ((long long)element < (long long)tab_b[best_pos])
		best_pos++;
	return (best_pos);
}

size_t	find_insert_pos_a(int *tab_a, size_t size_a, int element)
{
	size_t		i;
	size_t		best_pos;
	long long	best_diff;
	long long	diff;

	if (size_a == 0)
		return (0);
	i = 0;
	best_pos = 0;
	best_diff = LLONG_MAX;
	while (i < size_a)
	{
		diff = (long long)element - (long long)tab_a[i];
		if (diff < 0)
			diff = -diff;
		if (diff < best_diff)
		{
			best_diff = diff;
			best_pos = i;
		}
		i++;
	}
	if ((long long)element > (long long)tab_a[best_pos])
		best_pos++;
	return (best_pos);
}

static size_t	calc_rot(size_t size, size_t index)
{
	if (index == 0)
		return (0);
	if (index <= size / 2)
		return (index);
	return (size - index);
}

size_t	bst_index_b(int *tab_a, size_t *size_a, int *tab_b, size_t *size_b)
{
	size_t	i;
	size_t	index;
	size_t	best_cost;
	size_t	cost;
	size_t	pos_in_a;

	if (*size_b == 0)
		return (0);
	i = 0;
	index = 0;
	best_cost = SIZE_MAX;
	while (i < *size_b)
	{
		pos_in_a = find_insert_pos_a(tab_a, *size_a, tab_b[i]);
		cost = calc_rot(*size_b, i) + calc_rot(*size_a, pos_in_a);
		if (cost < best_cost)
		{
			best_cost = cost;
			index = i;
		}
		i++;
	}
	return (index);
}

size_t	bst_index_a(int *tab_a, size_t *size_a, int *tab_b, size_t *size_b)
{
	size_t	i;
	size_t	index;
	size_t	best_cost;
	size_t	cost;
	size_t	pos_in_b;

	if (*size_a == 0)
		return (0);
	i = 0;
	index = 0;
	best_cost = SIZE_MAX;
	while (i < *size_a)
	{
		pos_in_b = find_insert_pos_b(tab_b, *size_b, tab_a[i]);
		cost = calc_rot(*size_a, i) + calc_rot(*size_b, pos_in_b);
		if (cost < best_cost)
		{
			best_cost = cost;
			index = i;
		}
		i++;
	}
	return (index);
}
