# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 10:44:32 by ysahraou          #+#    #+#              #
#    Updated: 2024/05/25 13:01:05 by ysahraou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -g
CC = cc
RM = rm -f
SRC = ./src/push_swap.c ./src/ft_atol_check.c ./src/utils_init.c \
	./src/stack_init.c ./src/actions_a.c ./src/sort_3_4_5.c ./src/actions_b.c \
	./src/actions_ab.c ./src/big_sort.c ./src/utils_2.0.c ./src/big_sort_utils.c

SRC_B = ./src_bonus/checker.c ./src_bonus/stack_init_bonus.c \
		./src_bonus/ft_atol_check_bonus.c ./src_bonus/utils_init_bonus.c \
		./src_bonus/utils_2.0_bonus.c ./src_bonus/actions_a_bonus.c \
		./src_bonus/actions_ab_bonus.c ./src_bonus/actions_b_bonus.c \
		./src_gnl/get_next_line.c ./src_gnl/get_next_line_utils.c

OBJS = $(SRC:.c=.o)
OBJS_B = $(SRC_B:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c -o $@ $<

NAME = push_swap
CHECKER = checker

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling source files...⏳"
	@echo "Done ✅"
	@echo "Compiling libft...⏳"
	@$(MAKE) -C libft -s
	@echo "Done ✅"
	@echo "Linking...⏳"
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)
	@echo "Done ✅"

$(CHECKER): $(OBJS_B)
	@echo "Compiling source files...⏳"
	@echo "Done ✅"
	@echo "Compiling libft...⏳"
	@$(MAKE) -C libft -s
	@echo "Done ✅"
	@echo "Linking...⏳"
	@$(CC) $(CFLAGS) $(OBJS_B) libft/libft.a -o checker
	@echo "Done ✅"

bonus: $(CHECKER)

fclean: clean
	@echo "Clean all...⏳"
	@$(MAKE) fclean -C libft -s
	@$(RM) $(NAME)
	@$(RM) checker
	@echo "Done ✅"

clean:
	@echo "Clean .o files...⏳"
	@$(MAKE) clean -C libft -s
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_B)
	@echo "Done ✅"

re: fclean all

re_bonus: fclean bonus
