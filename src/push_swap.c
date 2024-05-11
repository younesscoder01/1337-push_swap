/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:46:05 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/11 14:23:01 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


void p_satack(t_stack *s)
{
	while (s)
	{
		printf("content => %i\n", s->content);
		printf("ab_med => %i\n", s->above_med);
		printf("index => %i\n\n", s->index);
		s = s->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc == 1)
		exit(127);
	if (argc == 2 && !argv[1][0])
		return (write(2, "Error\n", 6), 127);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		head_a = init_2_args(argc, argv);
		ft_free_args(argv);
	}
	else
		head_a = init(argc, argv);
	if (!duplicated_check(head_a))
		return (ft_stack_clear(&head_a), (0));
	if (!a_is_sorted(head_a))
		ft_sort(&head_a, &head_b);
	ft_stack_clear(&head_a);
	return (0);
}
