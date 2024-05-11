/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:02:25 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/10 09:52:37 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_free_args(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	a_is_sorted(t_stack *head_a)
{
	if (!head_a)
		return (1);
	while (head_a->next)
	{
		if (head_a->content > head_a->next->content)
			return (0);
		head_a = head_a->next;
	}
	return (1);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*temp;
	int		max;

	max = stack->content;
	temp = stack;
	while (stack)
	{
		if (stack->content > max)
		{
			max = stack->content;
			temp = stack;
		}
		stack = stack->next;
	}
	return (temp);
}

t_stack	*find_min(t_stack *stack_a)
{
	t_stack	*temp;
	int		min;

	min = stack_a->content;
	temp = stack_a;
	while (stack_a)
	{
		if (stack_a->content < min)
		{
			min = stack_a->content;
			temp = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (temp);
}
