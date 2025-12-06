/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 02:45:11 by itaharbo          #+#    #+#             */
/*   Updated: 2025/03/14 04:30:45 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_b_top(int *tab_a, size_t *size_a, int *tab_b, size_t *size_b)
{
	size_t	index_a;
	size_t	pos_in_b;
	size_t	rrot;
	size_t	i;

	index_a = bst_index_a(tab_a, size_a, tab_b, size_b);
	pos_in_b = find_insert_pos_b(tab_b, *size_b, tab_a[index_a]);
	if (index_a <= pos_in_b)
		rrot = index_a;
	else
		rrot = pos_in_b;
	i = 0;
	while (i < rrot)
	{
		rr(tab_a, *size_a, tab_b, *size_b);
		i++;
	}
}

void	rrr_b_bot(int *tab_a, size_t *size_a, int *tab_b, size_t *size_b)
{
	size_t	index_a;
	size_t	pos_in_b;
	size_t	rrot;
	size_t	i;

	index_a = bst_index_a(tab_a, size_a, tab_b, size_b);
	pos_in_b = find_insert_pos_b(tab_b, *size_b, tab_a[index_a]);
	if (index_a <= pos_in_b)
		rrot = *size_a - index_a;
	else
		rrot = *size_b - pos_in_b;
	i = 0;
	while (i < rrot)
	{
		rrr(tab_a, *size_a, tab_b, *size_b);
		i++;
	}
}

void	rr_a_top(int *tab_a, size_t *size_a, int *tab_b, size_t *size_b)
{
	size_t	index_b;
	size_t	pos_in_a;
	size_t	rrot;
	size_t	i;

	index_b = bst_index_b(tab_a, size_a, tab_b, size_b);
	pos_in_a = find_insert_pos_a(tab_a, *size_a, tab_b[index_b]);
	if (index_b <= pos_in_a)
		rrot = index_b;
	else
		rrot = pos_in_a;
	i = 0;
	while (i < rrot)
	{
		rr(tab_a, *size_a, tab_b, *size_b);
		i++;
	}
}

void	rrr_a_bot(int *tab_a, size_t *size_a, int *tab_b, size_t *size_b)
{
	size_t	index_b;
	size_t	pos_in_a;
	size_t	rrot;
	size_t	i;

	index_b = bst_index_b(tab_a, size_a, tab_b, size_b);
	pos_in_a = find_insert_pos_a(tab_a, *size_a, tab_b[index_b]);
	if (index_b <= pos_in_a)
		rrot = *size_b - index_b;
	else
		rrot = *size_a - pos_in_a;
	i = 0;
	while (i < rrot)
	{
		rrr(tab_a, *size_a, tab_b, *size_b);
		i++;
	}
}
