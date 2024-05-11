/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:54:36 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/01 18:54:42 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*init(int ac, char **av)
{
	int		i;
	t_stack	*head;

	i = 1;
	head = NULL;
	while (i < ac)
	{
		if (ft_atol_check(av[i]) <= INT_MAX && ft_atol_check(av[i]) >= INT_MIN)
			allocate(av[i], &head);
		else
		{
			write(2, "Error\n", 6);
			ft_stack_clear(&head);
			exit(127);
		}
		i++;
	}
	return (head);
}

t_stack	*init_2_args(int ac, char **av)
{
	int		i;
	t_stack	*head;

	(void)ac;
	i = 0;
	head = NULL;
	while (av[i])
	{
		if (ft_atol_check(av[i]) <= INT_MAX && ft_atol_check(av[i]) >= INT_MIN)
			allocate(av[i], &head);
		else
		{
			write(2, "Error\n", 6);
			ft_stack_clear(&head);
			ft_free_args(av);
			exit(127);
		}
		i++;
	}
	return (head);
}

void	allocate(char *arg, t_stack **head)
{
	t_stack	*temp;
	int		num;

	num = ft_atoi(arg);
	if (*head == NULL)
		*head = ft_stack_new(num);
	else
	{
		temp = ft_stack_new(num);
		ft_stack_add_back(head, &temp);
	}
}

int	duplicated_check(t_stack *head)
{
	t_stack	*temp;

	while (head)
	{
		temp = head->next;
		while (temp)
		{
			if (head->content == temp->content)
			{
				write(2, "Error\n", 6);
				return (0);
			}
			temp = temp->next;
		}
		head = head->next;
	}
	return (1);
}
