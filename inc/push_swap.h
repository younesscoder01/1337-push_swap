/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:41:21 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/10 20:12:14 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				index;
	bool			above_med;
	struct s_stack	*next;
}					t_stack;

/*stack_init*/
t_stack				*ft_stack_new(int content);
t_stack				*ft_stack_last(t_stack *stack);
void				ft_stack_add_back(t_stack **stack, t_stack **new);
void				ft_stack_clear(t_stack **stack);
int					ft_stack_size(t_stack *stack);
void				ft_sort(t_stack **stack_a, t_stack **stack_b);

/*utils_2.0*/
void				ft_free_args(char **arr);
int					a_is_sorted(t_stack *head_a);
t_stack				*find_max(t_stack *stack);
t_stack				*find_min(t_stack *stack_a);

/*utils_init*/
t_stack				*init(int ac, char **av);
t_stack				*init_2_args(int ac, char **av);
void				allocate(char *arg, t_stack **head);
int					duplicated_check(t_stack *head);

/*ft_atol_check*/
long				ft_atol_check(const char *nptr);

/*action_a*/
void				ft_ra(t_stack **stack, bool pr);
void				ft_sa(t_stack **stack, bool pr);
void				ft_rra(t_stack **stack, bool pr);
void				ft_pa(t_stack **stack_b, t_stack **stack_a, bool pr);

/*action_b*/
void				ft_sb(t_stack **stack, bool pr);
void				ft_rb(t_stack **stack, bool pr);
void				ft_rrb(t_stack **stack, bool pr);
void				ft_pb(t_stack **stack_a, t_stack **stack_b, bool pr);

/*action_ab*/
void				ft_ss(t_stack **stack_a, t_stack **stack_b, bool pr);
void				ft_rr(t_stack **stack_a, t_stack **stack_b, bool pr);
void				ft_rrr(t_stack **stack_a, t_stack **stack_b, bool pr);

/*big_sort*/
void				ft_sort(t_stack **stack_a, t_stack **stack_b);

/*big_sort_utils*/
int *set_arr(t_stack *stack_a, int size);
void sort_arr(int *arr, int len);
void give_a_index(t_stack *stack_a, int *arr, int len);
t_stack *still_in_range(t_stack *stack_a, int range);
void set_above_med(t_stack *stack, int len);

void sort_3_4_5(t_stack **stack_a, t_stack **stack_b);
void				sort_3(t_stack **stack);

#endif
