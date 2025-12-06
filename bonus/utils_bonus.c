/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:20:34 by itaharbo          #+#    #+#             */
/*   Updated: 2025/03/20 14:48:05 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_issign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_issorted(int *tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
