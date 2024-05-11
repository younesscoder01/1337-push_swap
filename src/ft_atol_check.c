/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:33:01 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/11 14:12:54 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static long	extract_sign(char **nump)
{
	int	sign;

	sign = 1;
	while ((**nump >= 9 && **nump <= 13) || **nump == 32)
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

int ft_strlen_0(const char *str)
{
	int i;
	int res;

	i = 0;
	while(str[i] == '0')
		i++;
	res = 0;
	while(str[i++] != '\0')
		res++;
	return (res);
	
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
