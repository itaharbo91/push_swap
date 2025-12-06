/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:44:45 by itaharbo          #+#    #+#             */
/*   Updated: 2025/03/14 04:31:24 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_size_2(int *tab_a, size_t size_a)
{
	if (tab_a[0] > tab_a[1])
		sa(tab_a, size_a);
}

static void	sort_size_3(int *tab_a, size_t *size_a)
{
	if (tab_a[0] > tab_a[1] && tab_a[0] > tab_a[2])
		ra(tab_a, *size_a);
	if (tab_a[1] > tab_a[2])
		rra(tab_a, *size_a);
	sort_size_2(tab_a, *size_a);
}

static void	sort_size_4(int *tab_a, size_t *size_a, int *tab_b, size_t *size_b)
{
	size_t	min_index;

	find_min(tab_a, *size_a, &min_index);
	if (min_index <= *size_a / 2)
	{
		while (min_index > 0)
		{
			ra(tab_a, *size_a);
			min_index--;
		}
	}
	else
	{
		while (min_index < *size_a)
		{
			rra(tab_a, *size_a);
			min_index++;
		}
	}
	if (ft_issorted(tab_a, *size_a))
		return ;
	pb(tab_a, size_a, tab_b, size_b);
	sort_size_3(tab_a, size_a);
	pa(tab_a, size_a, tab_b, size_b);
}

static void	sort_size_5(int *tab_a, size_t *size_a, int *tab_b, size_t *size_b)
{
	size_t	min_index;

	find_min(tab_a, *size_a, &min_index);
	if (min_index <= *size_a / 2)
	{
		while (min_index > 0)
		{
			ra(tab_a, *size_a);
			min_index--;
		}
	}
	else
	{
		while (min_index < *size_a)
		{
			rra(tab_a, *size_a);
			min_index++;
		}
	}
	if (ft_issorted(tab_a, *size_a))
		return ;
	pb(tab_a, size_a, tab_b, size_b);
	sort_size_4(tab_a, size_a, tab_b, size_b);
	pa(tab_a, size_a, tab_b, size_b);
}

void	sort_small(int *tab_a, size_t size_a, int *tab_b, size_t size_b)
{
	if (size_a == 2)
		sort_size_2(tab_a, size_a);
	else if (size_a == 3)
		sort_size_3(tab_a, &size_a);
	else if (size_a == 4)
		sort_size_4(tab_a, &size_a, tab_b, &size_b);
	else if (size_a == 5)
		sort_size_5(tab_a, &size_a, tab_b, &size_b);
}
/*
#include <stdio.h>

int main(int argc, char **argv)
{
    int *tab_a;
    int *tab_b;
    size_t size_a;
    size_t size_b;
    int i;

    if (argc < 2)
    {
        printf("Usage: %s <numbers separated by spaces>\n", argv[0]);
        return (1);
    }

    size_a = argc - 1;
    size_b = 0;
    tab_a = malloc(sizeof(int) * size_a);
    tab_b = malloc(sizeof(int) * size_a); // Taille maximale possible pour tab_b

    if (!tab_a || !tab_b)
    {
        printf("Erreur d'allocation de mémoire.\n");
        return (1);
    }

    for (i = 0; i < (int)size_a; i++)
    {
        tab_a[i] = atoi(argv[i + 1]);
    }

    printf("Tableau avant tri:\n");
    for (i = 0; i < (int)size_a; i++)
    {
        printf("%d ", tab_a[i]);
    }
    printf("\n");

    sort_small(tab_a, size_a, tab_b, size_b);

    printf("Tableau après tri:\n");
    for (i = 0; i < (int)size_a; i++)
    {
        printf("%d ", tab_a[i]);
    }
    printf("\n");

    free(tab_a);
    free(tab_b);

    return (0);
}*/