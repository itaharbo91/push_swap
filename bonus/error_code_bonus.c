/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:05:56 by itaharbo          #+#    #+#             */
/*   Updated: 2025/03/20 15:24:11 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_isempty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_isvalid_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || ft_issign(str[i]) || str[i] == ' '))
			return (0);
		if (ft_issign(str[i]))
		{
			if (!ft_isdigit(str[i + 1]) || ft_isdigit(str[i - 1]))
				return (0);
		}
		i++;
	}
	if (!(ft_isdigit(str[0]) || ft_issign(str[0]) || str[0] == ' '))
		return (0);
	return (1);
}

static int	valid_int(char **str, int size)
{
	int		j;
	size_t	i;
	char	**nbr;

	j = 1;
	while (j < size)
	{
		nbr = ft_split(str[j], ' ');
		if (!nbr)
			return (0);
		i = 0;
		while (nbr[i])
		{
			if (ft_atoi(nbr[i]) == ERROR_CODE)
			{
				ft_free_split(nbr);
				return (0);
			}
			i++;
		}
		ft_free_split(nbr);
		j++;
	}
	return (1);
}

static int	check_dupl(char **str, int size, size_t tab_size)
{
	size_t	i;
	size_t	k;
	int		*tab;

	i = 0;
	tab = char_to_tab(str, size, tab_size);
	if (!tab)
		return (0);
	while (i < tab_size - 1)
	{
		k = i + 1;
		while (k < tab_size)
		{
			if (tab[i] == tab[k])
			{
				free(tab);
				return (0);
			}
			k++;
		}
		i++;
	}
	free(tab);
	return (1);
}

int	error_code(char **str, int size)
{
	int		j;
	size_t	tab_size;

	j = 1;
	while (j < size)
	{
		if (ft_isempty(str[j]))
			return (0);
		if (ft_isvalid_char(str[j]) == 0)
			return (0);
		j++;
	}
	if (valid_int(str, size) == 0)
		return (0);
	tab_size = total_nbr(str, size);
	if (check_dupl(str, size, tab_size) == 0)
		return (0);
	return (1);
}
