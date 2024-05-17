/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:36:02 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/17 10:14:57 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../src_gnl/get_next_line.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

/*stack_init_bonus*/
t_stack				*ft_stack_new(int content);
void				ft_stack_add_back(t_stack **stack, t_stack **new);
t_stack				*ft_stack_last(t_stack *stack);
void				ft_stack_clear(t_stack **stack);
int					ft_stack_size(t_stack *stack);

/*utils_init_bonus*/
t_stack				*init_2_args(int ac, char **av);
void				allocate(char *arg, t_stack **head);
int					duplicated_check(t_stack *head);

/*ft_atol_check_bonus*/
long				ft_atol_check(const char *nptr);
int					all_space(char *str);

/*actions_a_bonus*/
void				ft_sa(t_stack **stack, bool pr);
void				ft_ra(t_stack **stack, bool pr);
void				ft_rra(t_stack **stack, bool pr);
void				ft_pa(t_stack **stack_b, t_stack **stack_a, bool pr);

/*actions_b_bonus*/
void				ft_sb(t_stack **stack, bool pr);
void				ft_rb(t_stack **stack, bool pr);
void				ft_rrb(t_stack **stack, bool pr);
void				ft_pb(t_stack **stack_a, t_stack **stack_b, bool pr);

/*actions_ab_bonus*/
void				ft_ss(t_stack **stack_a, t_stack **stack_b, bool pr);
void				ft_rr(t_stack **stack_a, t_stack **stack_b, bool pr);
void				ft_rrr(t_stack **stack_a, t_stack **stack_b, bool pr);

/*utils_2.0_bonus*/
int				run_commands(t_stack **stack_a, t_stack **stack_b,
						char *str);
void				ft_free_args(char **arr);
int					a_is_sorted(t_stack *head_a);
#endif