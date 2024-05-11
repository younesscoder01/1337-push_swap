/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:59:13 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/10 11:37:54 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sa(t_stack **stack, bool pr)
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
		write(1, "sa\n", 3);
}

void	ft_ra(t_stack **stack, bool pr)
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
		write(1, "ra\n", 3);
}

void	ft_rra(t_stack **stack, bool pr)
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
		write(1, "rra\n", 4);
}

void	ft_pa(t_stack **stack_b, t_stack **stack_a, bool pr)
{
	t_stack	*temp;

	if (*stack_b == NULL)
		return ;
	if (*stack_a == NULL)
	{
		*stack_a = *stack_b;
		*stack_b = (*stack_b)->next;
		(*stack_a)->next = NULL;
	}
	else
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = *stack_a;
		*stack_a = temp;
	}
	if (pr)
		write(1, "pa\n", 3);
}
