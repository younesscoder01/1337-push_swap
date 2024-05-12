/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:46:05 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/12 11:41:12 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static char	*join_str(char **s1)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 1;
	str = ft_calloc(1, 1);
	tmp = str;
	while (s1[i])
	{
		str = ft_strjoin(str, s1[i]);
		free(tmp);
		tmp = str;
		str = ft_strjoin(str, " ");
		free(tmp);
		tmp = str;
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;
	char	*str;

	head_a = NULL;
	head_b = NULL;
	if (argc == 1)
		exit(127);
	if (argc == 2 && !argv[1][0])
		return (write(2, "Error\n", 6), 127);
	if (argc >= 2)
	{
		str = join_str(argv);
		argv = ft_split(str, ' ');
		free(str);
		head_a = init_2_args(argc, argv);
		ft_free_args(argv);
	}
	if (!head_a)
		return (write(2, "Error\n", 6), 127);
	if (!duplicated_check(head_a))
		return (ft_stack_clear(&head_a), (0));
	if (!a_is_sorted(head_a))
		ft_sort(&head_a, &head_b);
	return (ft_stack_clear(&head_a), 0);
}
