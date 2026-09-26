/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:12:56 by yurishik          #+#    #+#             */
/*   Updated: 2025/05/29 14:00:42 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_length;

	i = 0;
	little_length = ft_strlen(little);
	if (little_length == 0)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[i] && i + little_length <= len)
	{
		if (big[i] == little[0])
		{
			if (!ft_strncmp((const char *)&big[i], little, little_length))
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
