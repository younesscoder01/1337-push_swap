/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:57:01 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/10 11:36:51 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sb(t_stack **stack, bool pr)
{
	t_stack	*temp_head;
	t_stack	*temp_2;

	if (*stack == NULL)
		return ;
	temp_head = *stack;
	temp_2 = (*stack)->next;
	temp_head->next = temp_2->next;
	temp_2->next = temp_head;
	*stack = temp_2;
	if (pr)
		write(1, "sb\n", 3);
}

void	ft_rb(t_stack **stack, bool pr)
{
	t_stack	*temp_head;
	t_stack	*temp_2;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp_head = (*stack)->next;
	temp_2 = ft_stack_last(*stack);
	temp_2->next = *stack;
	(*stack)->next = NULL;
	*stack = temp_head;
	if (pr)
		write(1, "rb\n", 3);
}

void	ft_rrb(t_stack **stack, bool pr)
{
	t_stack	*temp_head;
	t_stack	*temp_2;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp_head = *stack;
	temp_2 = ft_stack_last(*stack);
	while (temp_head->next->next)
		temp_head = temp_head->next;
	temp_head->next = NULL;
	temp_2->next = *stack;
	*stack = temp_2;
	if (pr)
		write(1, "rrb\n", 4);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b, bool pr)
{
	t_stack	*temp;

	if (*stack_a == NULL)
		return ;
	if (*stack_b == NULL)
	{
		*stack_b = *stack_a;
		*stack_a = (*stack_a)->next;
		(*stack_b)->next = NULL;
	}
	else
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = *stack_b;
		*stack_b = temp;
	}
	if (pr)
		write(1, "pb\n", 3);
}
