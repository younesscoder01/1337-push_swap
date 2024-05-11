/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:57:51 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/01 18:58:04 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_stack_new(int content)
{
	t_stack	*temp;

	temp = malloc(sizeof(t_stack));
	if (!temp)
		return (NULL);
	temp->content = content;
	temp->next = NULL;
	return (temp);
}

void	ft_stack_add_back(t_stack **stack, t_stack **new)
{
	t_stack	*temp;

	if (!stack || !new)
		return ;
	temp = ft_stack_last(*stack);
	if (*stack)
	{
		temp->next = *new;
	}
	else
		*stack = *new;
}

t_stack	*ft_stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	ft_stack_clear(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	temp = (*stack)->next;
	while (temp)
	{
		free(*stack);
		*stack = temp;
		temp = temp->next;
	}
	free(*stack);
	stack = NULL;
}

int	ft_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack != NULL)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
