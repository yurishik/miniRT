/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:03:53 by yurishik          #+#    #+#             */
/*   Updated: 2025/04/28 15:34:37 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	size_t			length;

	ch = (unsigned char)c;
	length = ft_strlen(s);
	if (ch == '\0')
		return ((char *)&s[length]);
	while (length > 0)
	{
		length--;
		if (s[length] == ch)
			return ((char *)&s[length]);
	}
	return (NULL);
}
