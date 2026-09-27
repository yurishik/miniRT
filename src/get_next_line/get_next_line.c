/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:49:08 by yurishik          #+#    #+#             */
/*   Updated: 2025/07/03 18:00:58 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_newline(char *stash)
{
	if (!stash)
		return (0);
	while (*stash != '\0')
	{
		if (*stash == '\n')
			return (1);
		stash++;
	}
	return (0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_length;
	size_t	s2_length;
	char	*ptr;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	ptr = (char *)malloc((s1_length + s2_length + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, s1_length + 1);
	ft_strlcpy(ptr + s1_length, s2, s2_length + 1);
	return (ptr);
}

char	*find_newline(char **stash)
{
	char	*line;
	char	*newline_ptr;
	char	*new_stash;

	if (!stash || !*stash)
		return (NULL);
	newline_ptr = ft_strchr(*stash, '\n');
	if (!newline_ptr)
		return (NULL);
	line = ft_substr(*stash, 0, newline_ptr - *stash + 1);
	if (!line)
		return (NULL);
	new_stash = ft_strdup(newline_ptr + 1);
	free(*stash);
	*stash = new_stash;
	return (line);
}

char	*free_and_return(t_gnl *gnl)
{
	char	*line;

	if (gnl->bytes_read < 0)
	{
		free(gnl->stash);
		gnl->stash = NULL;
		return (NULL);
	}
	if (gnl->stash == NULL)
		return (NULL);
	if (has_newline(gnl->stash))
		return (find_newline(&gnl->stash));
	if (*gnl->stash != '\0')
	{
		line = ft_strdup(gnl->stash);
		free(gnl->stash);
		gnl->stash = NULL;
		return (line);
	}
	free(gnl->stash);
	gnl->stash = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_gnl	gnl;
	char			*new_stash;
	char			*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!has_newline(gnl.stash))
	{
		gnl.bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (gnl.bytes_read <= 0)
			break ;
		buffer[gnl.bytes_read] = '\0';
		new_stash = ft_strjoin(gnl.stash, buffer);
		if (!new_stash)
			break ;
		free(gnl.stash);
		gnl.stash = new_stash;
	}
	free(buffer);
	return (free_and_return(&gnl));
}
