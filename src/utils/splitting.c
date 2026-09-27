/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 13:19:13 by yurishik          #+#    #+#             */
/*   Updated: 2026/09/27 15:06:35 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static size_t	count_words(const char *str)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = FALSE;
	while (*str)
	{
		if (!ft_isspace(*str) && !in_word)
		{
			in_word = TRUE;
			count++;
		}
		else if (ft_isspace(*str))
			in_word = FALSE;
		str++;
	}
	return (count);
}

static char	*extract_word(const char *str, size_t *index)
{
	size_t	start;
	size_t	len;

	while (str[*index] && ft_isspace(str[*index]))
		(*index)++;
	start = *index;
	while (str[*index] && !ft_isspace(str[*index]))
		(*index)++;
	len = *index - start;
	return (ft_substr(str, start, len));
}

char	**ft_split_isspace(const char *str)
{
	char	**result;
	size_t	words;
	size_t	i;
	size_t	str_idx;

	if (!str)
		return (NULL);
	words = count_words(str);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	i = 0;
	str_idx = 0;
	while (i < words)
	{
		result[i] = extract_word(str, &str_idx);
		if (!result[i])
		{
			free_str_array(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

/**
 * @brief 文字列のなかに指定の文字が何回出てくるかを数える
 *
 * @param str 文字列
 * @param c 数えたい文字
 */
static int	count_char(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

/**
 * @brief 文字列をカンマ区切りで分割する
 *
 * @param str もとの文字列
 * @param num 分割個数
 * @return うまく行けばsplitされたもの、カンマの個数などが変ならNULLを返す
 */
char	**comma_split_elements(const char *str, int num)
{
	char	**split;
	int		count;

	if (!str || count_char(str, ',') != num - 1)
		return (NULL);
	split = ft_split(str, ',');
	if (!split)
		return (NULL);
	count = 0;
	while (split[count])
		count++;
	if (count != num)
	{
		free_str_array(split);
		return (NULL);
	}
	return (split);
}
