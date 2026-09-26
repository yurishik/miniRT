/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:43:56 by yurishik          #+#    #+#             */
/*   Updated: 2025/06/08 17:20:37 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long	result;
	int		sign;
	int		digit;

	result = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while ('0' <= *nptr && *nptr <= '9')
	{
		digit = *nptr - '0';
		if (sign == 1 && (INT_MAX - digit) / 10 < result)
			return (INT_MAX);
		if (sign == -1 && ((long)INT_MAX + 1 - digit) / 10 < result)
			return (INT_MIN);
		result = result * 10 + digit;
		nptr++;
	}
	return (sign * (int)result);
}
