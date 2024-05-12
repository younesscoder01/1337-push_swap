/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:34:21 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/12 11:35:48 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	run(char *str, t_stack **head_a, t_stack **head_b)
{
	while (str)
	{
		run_commands(head_a, head_b, str);
		str = get_next_line(0);
	}
	if (a_is_sorted(*head_a) && !*head_b)
		write(1, "OK\n", 3);
	else
	{
		write(1, "KO\n", 3);
		exit(1);
	}
	ft_stack_clear(head_a);
}

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

int	main(int argc, char *argv[])
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
	str = get_next_line(0);
	run(str, &head_a, &head_b);
	return (0);
}
