/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:58:37 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/12 11:41:00 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	set_range(int size)
{
	if (size <= 400)
		return (15);
	return (30);
}

void	send_ab(t_stack **stack_a, t_stack **stack_b, int range)
{
	int	i;

	i = 0;
	while (*stack_a)
	{
		set_above_med(*stack_a, ft_stack_size(*stack_a));
		if ((*stack_a)->index <= i)
		{
			ft_pb(stack_a, stack_b, 1);
			ft_rb(stack_b, 1);
			i++;
		}
		else if ((*stack_a)->index <= range + i)
		{
			ft_pb(stack_a, stack_b, 1);
			i++;
		}
		else if (still_in_range(*stack_a, range + i) && (*stack_a)->above_med)
			ft_ra(stack_a, 1);
		else
			ft_rra(stack_a, 1);
	}
}

void	send_ba(t_stack **stack_b, t_stack **stack_a)
{
	while (*stack_b)
	{
		set_above_med(*stack_b, ft_stack_size(*stack_b));
		while (find_max(*stack_b) != *stack_b)
		{
			if (find_max(*stack_b)->above_med)
				ft_rb(stack_b, 1);
			else
				ft_rrb(stack_b, 1);
		}
		ft_pa(stack_b, stack_a, 1);
	}
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	*arr;
	int	range;

	if (ft_stack_size(*stack_a) <= 5)
		return (sort_3_4_5(stack_a, stack_b));
	if (ft_stack_size(*stack_a) == 2)
	{
		ft_sa(stack_a, 1);
		exit(0);
	}
	arr = set_arr(*stack_a, ft_stack_size(*stack_a));
	range = set_range(ft_stack_size(*stack_a));
	sort_arr(arr, ft_stack_size(*stack_a));
	give_a_index(*stack_a, arr, ft_stack_size(*stack_a));
	send_ab(stack_a, stack_b, range);
	send_ba(stack_b, stack_a);
	free(arr);
}
