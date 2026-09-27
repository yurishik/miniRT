/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:26:26 by yurishik          #+#    #+#             */
/*   Updated: 2025/05/29 14:41:08 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charinset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	trim_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && is_charinset(s1[i], set))
	{
		i++;
	}
	return (i);
}

static int	trim_end(char const *s1, char const *set, size_t length)
{
	while (length > 0 && is_charinset(s1[length - 1], set))
	{
		length--;
	}
	return (length);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	length;
	char	*ptr;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	if (*s1 == '\0' || set == NULL || *set == '\0')
		return (ft_strdup(s1));
	length = ft_strlen(s1);
	length = trim_end(s1, set, length);
	i = trim_start(s1, set);
	if (length < i)
		length = i;
	ptr = (char *)malloc((length - i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1 + i, length - i + 1);
	return (ptr);
}
