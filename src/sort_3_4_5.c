/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_4_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:01:28 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/10 20:25:01 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_3(t_stack **stack)
{
	t_stack	*big;

	big = find_max(*stack);
	if (*stack == big)
		ft_ra(stack, 1);
	else if ((*stack)->next == big)
		ft_rra(stack, 1);
	if ((*stack)->content > (*stack)->next->content)
		ft_sa(stack, 1);
}
void push_min(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_a)->content != find_min(*stack_a)->content)
	{
		if (find_min(*stack_a)->above_med)
			ft_ra(stack_a, 1);
		else
			ft_rra(stack_a, 1);
	}
	ft_pb(stack_a, stack_b, 1);
}

void sort_3_4_5(t_stack **stack_a, t_stack **stack_b)
{
	set_above_med(*stack_a, ft_stack_size(*stack_a));
	if (ft_stack_size(*stack_a) == 5)
		push_min(stack_a, stack_b);
	set_above_med(*stack_a, ft_stack_size(*stack_a));
	if (ft_stack_size(*stack_a) == 4)
		push_min(stack_a, stack_b);
	sort_3(stack_a);
	ft_pa(stack_b, stack_a, 1);
	ft_pa(stack_b, stack_a, 1);
}
