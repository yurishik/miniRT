/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:20:37 by yurishik          #+#    #+#             */
/*   Updated: 2025/06/01 16:09:45 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i = 1;
		n *= -1;
	}
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	int		digit;
	char	*result;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	digit = 0;
	digit = count_digits(n);
	result = (char *)malloc((digit + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[digit] = '\0';
	if (n < 0)
	{
		n *= -1;
		result[0] = '-';
	}
	while (digit > 0 && n != 0)
	{
		digit--;
		result[digit] = '0' + (n % 10);
		n /= 10;
	}
	return (result);
}
