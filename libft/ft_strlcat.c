/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:35:01 by yurishik          #+#    #+#             */
/*   Updated: 2025/05/29 13:31:22 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	length_dst;
	size_t	length_src;
	size_t	i;
	size_t	imax;

	length_dst = ft_strlen(dst);
	length_src = ft_strlen(src);
	i = 0;
	if (size <= length_dst)
		return (size + length_src);
	if (size <= length_dst + length_src)
		imax = size - length_dst - 1;
	else
		imax = length_src;
	while (i < imax)
	{
		dst[length_dst + i] = src[i];
		i++;
	}
	dst[length_dst + i] = '\0';
	return (length_dst + length_src);
}
