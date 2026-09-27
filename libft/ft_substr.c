/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:23:16 by yurishik          #+#    #+#             */
/*   Updated: 2025/04/29 10:23:57 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_length;
	size_t	substr_length;
	char	*ptr;

	if (s == NULL)
		return (NULL);
	s_length = ft_strlen(s);
	if (len == 0 || s_length <= start)
		return (ft_strdup(""));
	if (s_length - start < len)
		substr_length = s_length - start;
	else
		substr_length = len;
	ptr = (char *)malloc((substr_length + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s + start, substr_length + 1);
	return (ptr);
}
