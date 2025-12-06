/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:54:51 by itaharbo          #+#    #+#             */
/*   Updated: 2025/03/20 16:27:04 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# define ERROR_CODE 2147483648

# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include "./get_next_line/get_next_line.h"

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *str, int fd);
void		sa(int *tab_a, size_t size_a);
void		sb(int *tab_b, size_t size_b);
void		ss(int *tab_a, size_t size_a, int *tab_b, size_t size_b);
void		pa(int *tab_a, size_t *size_a, int *tab_b, size_t *size_b);
void		pb(int *tab_b, size_t *size_b, int *tab_a, size_t *size_a);
void		ra(int *tab_a, size_t size_a);
void		rb(int *tab_b, size_t size_b);
void		rr(int *tab_a, size_t size_a, int *tab_b, size_t size_b);
void		rra(int *tab_a, size_t size_a);
void		rrb(int *tab_b, size_t size_b);
void		rrr(int *tab_a, size_t size_a, int *tab_b, size_t size_b);
void		ft_free_split(char **str);
char		**ft_split(const char *s, char c);
size_t		ft_strlen(char *str);
size_t		total_nbr(char **av, int size);
int			ft_issorted(int *tab, size_t size);
int			ft_issign(char c);
int			ft_isdigit(int c);
int			ft_strcmp(char *s1, char *s2);
int			error_code(char **str, int size);
int			*char_to_tab(char **av, int size, size_t nbr_total);
long long	ft_atoi(char *str);

#endif