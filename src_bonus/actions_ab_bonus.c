/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_ab_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:59:42 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/17 10:19:37 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	ft_ss(t_stack **stack_a, t_stack **stack_b, bool pr)
{
	ft_sa(stack_a, 0);
	ft_sb(stack_b, 0);
	if (pr)
		write(1, "ss\n", 3);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b, bool pr)
{
	ft_ra(stack_a, 0);
	ft_rb(stack_b, 0);
	if (pr)
		write(1, "rr\n", 3);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b, bool pr)
{
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
	if (pr)
		write(1, "rrr\n", 4);
}
