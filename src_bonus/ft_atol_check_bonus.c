/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_check_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:33:01 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/12 11:32:25 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

static long	extract_sign(char **nump)
{
	int	sign;

	sign = 1;
	while (**nump == 32)
		(*nump)++;
	if (**nump == '-' || **nump == '+')
	{
		if (**nump == '-')
			sign *= -1;
		(*nump)++;
		if (**nump == '\0')
			return (LONG_MAX);
	}
	return (sign);
}

int	ft_strlen_0(const char *str)
{
	int	i;
	int	res;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	res = 0;
	while (str[i++] != '\0')
		res++;
	return (res);
}

int	all_space(char *str)
{
	int	len;
	int	i;
	int	j;

	len = ft_strlen(str);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			j++;
		i++;
	}
	if (len == j)
		return (1);
	return (0);
}

long	ft_atol_check(const char *nptr)
{
	char	*nump;
	long	result;
	long	sign;

	if (ft_strlen_0(nptr) >= 12)
		return (LONG_MAX);
	nump = (char *)nptr;
	result = 0;
	if (all_space(nump))
		return (LONG_MAX);
	sign = extract_sign(&nump);
	if (sign == LONG_MAX)
		return (LONG_MAX);
	while (*nump != '\0')
	{
		if (*nump >= '0' && *nump <= '9')
			result = result * 10 + (*nump - 48);
		else
			return (LONG_MAX);
		nump++;
	}
	return (result * sign);
}
