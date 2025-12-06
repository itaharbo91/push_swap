/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:31:26 by itaharbo          #+#    #+#             */
/*   Updated: 2025/03/22 14:12:11 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_to_top(int *tab_a, size_t *size_a, size_t index)
{
	size_t	i;

	if (index <= *size_a / 2)
	{
		i = 0;
		while (i < index)
		{
			ra(tab_a, *size_a);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < *size_a - index)
		{
			rra(tab_a, *size_a);
			i++;
		}
	}
}

void	rotate_b_to_top(int *tab_b, size_t *size_b, size_t index)
{
	size_t	i;

	if (index <= *size_b / 2)
	{
		i = 0;
		while (i < index)
		{
			rb(tab_b, *size_b);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < *size_b - index)
		{
			rrb(tab_b, *size_b);
			i++;
		}
	}
}

void	rotate_med(int *tab_a, size_t *size_a, size_t close_index)
{
	if (close_index <= *size_a / 2)
	{
		while (close_index > 0)
		{
			ra(tab_a, *size_a);
			close_index--;
		}
	}
	else
	{
		while (close_index < *size_a)
		{
			rra(tab_a, *size_a);
			close_index++;
		}
	}
}
