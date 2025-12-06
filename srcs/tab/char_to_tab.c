/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:19:17 by itaharbo          #+#    #+#             */
/*   Updated: 2025/03/20 15:03:49 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	final_tab(char **av, int *tab, int size)
{
	char	**nbr;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 1;
	while (j < size)
	{
		nbr = ft_split(av[j], ' ');
		if (!nbr)
			return ;
		k = 0;
		while (nbr[k])
		{
			tab[i] = (int)ft_atoi(nbr[k]);
			free(nbr[k]);
			i++;
			k++;
		}
		free(nbr);
		j++;
	}
}

int	*char_to_tab(char **av, int size, size_t nbr_total)
{
	int		*tab;

	tab = malloc(sizeof(int) * nbr_total);
	if (!tab)
		return (NULL);
	final_tab(av, tab, size);
	return (tab);
}
/*
#include <stdio.h>

int main(int argc, char **argv)
{
    int *tab;
    size_t nbr_total;
    int i;

    if (argc < 2)
    {
        printf("Usage: %s <numbers separated by spaces>\n", argv[0]);
        return (1);
    }

    tab = char_to_tab(argv, argc);
    if (!tab)
    {
        printf("Erreur d'allocation de mémoire.\n");
        return (1);
    }

    nbr_total = total_nbr(argv, argc);
    i = 0;
    while (i < (int)nbr_total)
    {
        printf("Element %d: %d\n", i, tab[i]);
        i++;
    }

    free(tab);
    return (0);
}*/