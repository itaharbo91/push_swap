/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 22:57:02 by itaharbo          #+#    #+#             */
/*   Updated: 2025/03/22 14:44:15 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	*ft_copy_tab(int *tab, size_t size)
{
	int		*copy;
	size_t	i;

	copy = malloc(sizeof(int) * size);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = tab[i];
		i++;
	}
	return (copy);
}

static void	sort_bubble(int *tab, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}

int	find_median(int *tab, size_t size)
{
	int	med;
	int	*copy;

	if (size == 0)
		return (-1);
	copy = ft_copy_tab(tab, size);
	if (!copy)
		return (-1);
	sort_bubble(copy, size);
	med = size / 2;
	if (size % 2 == 1)
		med = copy[size / 2];
	else
		med = (copy[size / 2] + copy[size / 2 - 1]) / 2;
	free(copy);
	return (med);
}

/*#include <stdio.h>

int	main()
{
	int	tab[] = {3, 2, 4, 0, -2, 42, 65, 1, -1};
	size_t	size = sizeof(tab) / sizeof(tab[0]);

	printf("median : %d\n", find_median(tab, size));
	return (0);
}*/
