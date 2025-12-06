/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:23:01 by itaharbo          #+#    #+#             */
/*   Updated: 2025/03/20 14:47:25 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static size_t	sp_count_word(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	*string(const char *s, char c)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	while (s[i] && s[i] != c)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	while (j < i)
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

void	ft_free_split(char **str)
{
	size_t	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	strs_len;
	char	**str;

	if (!s)
		return (NULL);
	strs_len = sp_count_word(s, c);
	str = (char **)malloc(sizeof(char *) * (strs_len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < strs_len)
	{
		while (*s == c)
			s++;
		str[i] = string(s, c);
		if (!str[i])
			return (ft_free_split(str), NULL);
		s = s + ft_strlen(str[i]);
		i++;
	}
	str[i] = NULL;
	return (str);
}
/*
#include <stdio.h>

int main(void)
{
    char **result;
    size_t i;

    result = ft_split("Hello         world this is a test", ' ');
    if (!result)
    {
        printf("Error: ft_split returned NULL\n");
        return 1;
    }

    i = 0;
    while (result[i])
    {
        printf("result[%zu]: %s\n", i, result[i]);
        i++;
    }

    ft_free_split(result);
    return 0;
}*/