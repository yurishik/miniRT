/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:13:00 by yurishik          #+#    #+#             */
/*   Updated: 2025/06/01 17:12:45 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
