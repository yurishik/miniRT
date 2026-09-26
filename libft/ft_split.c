/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:45:54 by yurishik          #+#    #+#             */
/*   Updated: 2025/06/03 09:41:52 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s != '\0')
	{
		if (*s == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc((n + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < n)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int	set_word(char **result, char const *s, int word_length, int i)
{
	result[i] = ft_strndup(s - word_length, word_length);
	if (!result[i])
	{
		while (i > 0)
		{
			i--;
			free(result[i]);
		}
		free(result);
		return (0);
	}
	return (1);
}

static int	get_next_word(char const **s, char c, char const **start)
{
	int	word_len;

	word_len = 0;
	while (**s != '\0' && **s == c)
		(*s)++;
	*start = *s;
	while (**s != '\0' && **s != c)
	{
		word_len++;
		(*s)++;
	}
	return (word_len);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	int			word_count;
	int			word_len;
	char const	*start;
	int			i;

	word_count = count_words(s, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	word_len = 0;
	i = 0;
	while (i < word_count)
	{
		word_len = get_next_word(&s, c, &start);
		if (word_len == 0)
			break ;
		if (!set_word(result, start + word_len, word_len, i))
			return (NULL);
		i++;
	}
	result[word_count] = NULL;
	return (result);
}
