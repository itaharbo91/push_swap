/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:32:22 by itaharbo          #+#    #+#             */
/*   Updated: 2025/03/20 17:11:32 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <unistd.h>
#include <stdio.h>

static void	instru_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static void	exec_instru(int *tab_a, int *tab_b, size_t sizes[2], char *instru)
{
	if (!ft_strcmp(instru, "sa\n"))
		sa(tab_a, sizes[0]);
	else if (!ft_strcmp(instru, "sb\n"))
		sb(tab_b, sizes[1]);
	else if (!ft_strcmp(instru, "ss\n"))
		ss(tab_a, sizes[0], tab_b, sizes[1]);
	else if (!ft_strcmp(instru, "pa\n"))
		pa(tab_a, &sizes[0], tab_b, &sizes[1]);
	else if (!ft_strcmp(instru, "pb\n"))
		pb(tab_a, &sizes[0], tab_b, &sizes[1]);
	else if (!ft_strcmp(instru, "ra\n"))
		ra(tab_a, sizes[0]);
	else if (!ft_strcmp(instru, "rb\n"))
		rb(tab_b, sizes[1]);
	else if (!ft_strcmp(instru, "rr\n"))
		rr(tab_a, sizes[0], tab_b, sizes[1]);
	else if (!ft_strcmp(instru, "rra\n"))
		rra(tab_a, sizes[0]);
	else if (!ft_strcmp(instru, "rrb\n"))
		rrb(tab_b, sizes[1]);
	else if (!ft_strcmp(instru, "rrr\n"))
		rrr(tab_a, sizes[0], tab_b, sizes[1]);
	else
		instru_error();
}

static void	sort_check(int *tab_a, int *tab_b, size_t tab_sizes[2])
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		exec_instru(tab_a, tab_b, tab_sizes, line);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (ft_issorted(tab_a, tab_sizes[0]) && tab_sizes[1] == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

static void	sort_nb(char **av, int size)
{
	int		*tab_a;
	int		*tab_b;
	size_t	tab_sizes[2];

	tab_sizes[0] = total_nbr(av, size);
	tab_sizes[1] = 0;
	tab_a = char_to_tab(av, size, tab_sizes[0]);
	if (!tab_a)
		return ;
	tab_b = malloc(sizeof(int) * tab_sizes[0]);
	if (!tab_b)
	{
		free(tab_a);
		return ;
	}
	sort_check(tab_a, tab_b, tab_sizes);
	free(tab_a);
	free(tab_b);
}

int	main(int ac, char **av)
{
	if (ac <= 1)
		return (0);
	if (error_code(av, ac) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	sort_nb(av, ac);
	return (0);
}
