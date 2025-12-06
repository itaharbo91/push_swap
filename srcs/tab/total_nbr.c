/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:44:23 by itaharbo          #+#    #+#             */
/*   Updated: 2025/03/20 14:58:28 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static size_t	count_nbr(char *str)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '-' || str[i] == '+')
			i++;
		if (ft_isdigit(str[i]))
		{
			count++;
			while (ft_isdigit(str[i]))
				i++;
		}
	}
	return (count);
}

size_t	total_nbr(char **av, int size)
{
	int		j;
	size_t	nbr_total;

	j = 1;
	nbr_total = 0;
	while (j < size)
	{
		nbr_total += count_nbr(av[j]);
		j++;
	}
	return (nbr_total);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	printf("%lu\n", total_nbr(av, ac));
	return (0);
}*/
