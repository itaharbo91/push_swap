# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 12:42:47 by itaharbo          #+#    #+#              #
#    Updated: 2025/03/27 18:34:03 by itaharbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap
NAME_BONUS= checker
CC= cc
I= -I srcs
CFLAGS= -Wall -Wextra -Werror $(I)
SRCS= srcs/main.c srcs/error_code.c	\
		srcs/instructions/swap.c srcs/instructions/push.c srcs/instructions/rotate.c srcs/instructions/rrotate.c	\
			srcs/sort/rotate_to_top.c srcs/sort/sort_small.c srcs/sort/sort_all.c srcs/sort/best_index.c	\
				srcs/tab/ft_atoi.c srcs/tab/total_nbr.c srcs/tab/ft_split.c srcs/tab/char_to_tab.c	\
					srcs/utils/utils.c srcs/utils/find_median.c srcs/utils/sort_utils.c	\
						srcs/opti/opti.c
SRCS_BONUS= bonus/main_bonus.c bonus/error_code_bonus.c	\
		bonus/swap_bonus.c bonus/push_bonus.c bonus/rotate_bonus.c bonus/rrotate_bonus.c	\
			bonus/char_to_tab_bonus.c bonus/total_nbr_bonus.c bonus/ft_atoi_bonus.c bonus/ft_split_bonus.c	\
				bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c	\
					bonus/utils_bonus.c
OBJS= $(SRCS:.c=.o)
OBJS_BONUS= $(SRCS_BONUS:.c=.o)

OPTION= -c

all: $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) $(OPTION) $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

clean:
	find . -name "*.o" -delete

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus
