/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:06:50 by yurishik          #+#    #+#             */
/*   Updated: 2025/07/01 17:44:44 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	s_length;
	char	*ptr;
	size_t	i;

	i = 0;
	s_length = ft_strlen(s);
	ptr = (char *)malloc((s_length + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < s_length)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
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
