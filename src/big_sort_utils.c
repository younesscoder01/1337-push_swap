/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:54:06 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/12 11:38:44 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*set_arr(t_stack *stack_a, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		arr[i++] = stack_a->content;
		stack_a = stack_a->next;
	}
	return (arr);
}

void	sort_arr(int *arr, int len)
{
	int	min;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = i;
		min = i;
		while (j < len)
		{
			if (arr[min] > arr[j])
				min = j;
			j++;
		}
		j = arr[min];
		arr[min] = arr[i];
		arr[i] = j;
		i++;
	}
}

void	give_a_index(t_stack *stack_a, int *arr, int len)
{
	int	i;

	while (stack_a)
	{
		i = 0;
		while (i < len)
		{
			if (arr[i] == stack_a->content)
				stack_a->index = i;
			i++;
		}
		stack_a = stack_a->next;
	}
}

t_stack	*still_in_range(t_stack *stack_a, int range)
{
	while (stack_a)
	{
		if (stack_a->index <= range)
			return (stack_a);
		stack_a = stack_a->next;
	}
	return (NULL);
}

void	set_above_med(t_stack *stack, int len)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (i <= len / 2)
			stack->above_med = true;
		else
			stack->above_med = false;
		stack = stack->next;
		i++;
	}
}
