/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.0_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:02:25 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/12 11:34:16 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

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

void	err(void)
{
	write(2, "Error\n", 6);
	exit(127);
}

void	run_commands(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		ft_sa(stack_a, 0);
	else if (!ft_strncmp(str, "rrr\n", 4))
		ft_rrr(stack_a, stack_b, 0);
	else if (!ft_strncmp(str, "rra\n", 4))
		ft_rra(stack_a, 0);
	else if (!ft_strncmp(str, "rrb\n", 4))
		ft_rrb(stack_b, 0);
	else if (!ft_strncmp(str, "rr\n", 3))
		ft_rr(stack_a, stack_b, 0);
	else if (!ft_strncmp(str, "ss\n", 3))
		ft_ss(stack_a, stack_b, 0);
	else if (!ft_strncmp(str, "rb\n", 3))
		ft_rb(stack_b, 0);
	else if (!ft_strncmp(str, "ra\n", 3))
		ft_ra(stack_a, 0);
	else if (!ft_strncmp(str, "sb\n", 3))
		ft_sb(stack_b, 0);
	else if (!ft_strncmp(str, "pa\n", 3))
		ft_pa(stack_b, stack_a, 0);
	else if (!ft_strncmp(str, "pb\n", 3))
		ft_pb(stack_a, stack_b, 0);
	else
		err();
}
