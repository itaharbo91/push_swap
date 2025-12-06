/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:32:22 by itaharbo          #+#    #+#             */
/*   Updated: 2025/03/20 15:22:54 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_algo(int *tab_a, size_t size_a, int *tab_b, size_t size_b)
{
	if (ft_issorted(tab_a, size_a))
		return ;
	if (size_a <= 5)
		sort_small(tab_a, size_a, tab_b, size_b);
	else
		sort_all(tab_a, size_a, tab_b, size_b);
}

static void	sort_nb(char **av, int size)
{
	int		*tab_a;
	int		*tab_b;
	size_t	tab_size;

	tab_size = total_nbr(av, size);
	tab_a = char_to_tab(av, size, tab_size);
	if (!tab_a)
		return ;
	tab_b = malloc(sizeof(int) * tab_size);
	if (!tab_b)
	{
		free(tab_a);
		return ;
	}
	sort_algo(tab_a, tab_size, tab_b, 0);
	free(tab_a);
	free(tab_b);
}

int	main(int ac, char **av)
{
	if (ac <= 1)
		return (1);
	if (error_code(av, ac) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	sort_nb(av, ac);
	return (0);
}
