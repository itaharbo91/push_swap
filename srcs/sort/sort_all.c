/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:22:00 by itaharbo          #+#    #+#             */
/*   Updated: 2025/03/22 14:32:54 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_min_a(int *tab_a, size_t size_a)
{
	int		min_a;
	size_t	min_index;

	min_a = find_min(tab_a, size_a, &min_index);
	if (tab_a[0] != min_a)
	{
		while (tab_a[0] != min_a)
		{
			if (min_index <= size_a / 2)
				ra(tab_a, size_a);
			else
				rra(tab_a, size_a);
		}
	}
}

static void	push_to_b(int *tab_a, size_t *size_a, int *tab_b, size_t *size_b)
{
	size_t	index_a;
	size_t	pos_in_b;

	index_a = bst_index_a(tab_a, size_a, tab_b, size_b);
	pos_in_b = find_insert_pos_b(tab_b, *size_b, tab_a[index_a]);
	if (index_a <= *size_a / 2 && pos_in_b <= *size_b / 2)
		rr_b_top(tab_a, size_a, tab_b, size_b);
	else if (index_a > *size_a / 2 && pos_in_b > *size_b / 2)
		rrr_b_bot(tab_a, size_a, tab_b, size_b);
	index_a = bst_index_a(tab_a, size_a, tab_b, size_b);
	pos_in_b = find_insert_pos_b(tab_b, *size_b, tab_a[index_a]);
	rotate_a_to_top(tab_a, size_a, index_a);
	rotate_b_to_top(tab_b, size_b, pos_in_b);
	pb(tab_a, size_a, tab_b, size_b);
}

static void	push_to_a(int *tab_a, size_t *size_a, int *tab_b, size_t *size_b)
{
	size_t	index_b;
	size_t	pos_in_a;

	index_b = bst_index_b(tab_a, size_a, tab_b, size_b);
	pos_in_a = find_insert_pos_a(tab_a, *size_a, tab_b[index_b]);
	if (index_b <= *size_b / 2 && pos_in_a <= *size_a / 2)
		rr_a_top(tab_a, size_a, tab_b, size_b);
	else if (index_b > *size_b / 2 && pos_in_a > *size_a / 2)
		rrr_a_bot(tab_a, size_a, tab_b, size_b);
	index_b = bst_index_b(tab_a, size_a, tab_b, size_b);
	pos_in_a = find_insert_pos_a(tab_a, *size_a, tab_b[index_b]);
	rotate_b_to_top(tab_b, size_b, index_b);
	rotate_a_to_top(tab_a, size_a, pos_in_a);
	pa(tab_a, size_a, tab_b, size_b);
}

static void	push_median(int *tab_a, size_t *size_a, int *tab_b, size_t *size_b)
{
	int		median;
	size_t	i;
	size_t	close_index;

	median = find_median(tab_a, *size_a);
	i = 0;
	while (i < *size_a)
	{
		if (tab_a[0] < median)
		{
			close_index = find_clos_index(tab_a, *size_a, median);
			rotate_med(tab_a, size_a, close_index);
		}
		if (tab_a[0] >= median)
		{
			pb(tab_a, size_a, tab_b, size_b);
			i++;
		}
	}
}

void	sort_all(int *tab_a, size_t size_a, int *tab_b, size_t size_b)
{
	while (size_b < 2)
		pb(tab_a, &size_a, tab_b, &size_b);
	if (tab_b[0] < tab_b[1])
		sb(tab_b, size_b);
	if (size_a > 100)
		push_median(tab_a, &size_a, tab_b, &size_b);
	while (size_a > 3)
	{
		if (ft_issorted(tab_a, size_a))
			break ;
		push_to_b(tab_a, &size_a, tab_b, &size_b);
	}
	sort_small(tab_a, size_a, tab_b, size_b);
	while (size_b > 0)
		push_to_a(tab_a, &size_a, tab_b, &size_b);
	if (!ft_issorted(tab_a, size_a))
		rotate_min_a(tab_a, size_a);
}
