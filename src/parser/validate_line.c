/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 11:20:13 by yurishik          #+#    #+#             */
/*   Updated: 2026/09/27 11:20:53 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief 空行チェック
 *
 * @param line 
 * @return 空行ならTRUE, そうでないならFALSE
 */
int	is_blank_line(const char *line)
{
	size_t	i;

	if (!line)
		return (TRUE);
	i = 0;
	while (line[i])
	{
		if (line[i] != '\n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/**
 * @brief ある文字がホワイトリスト内かチェック
 *
 * @param c
 * @return ホワイトリスト内ならTRUE, そうでないならFALSE
 */
int	is_allowed_char(char c)
{
	if (ft_strchr("ACLsplcy0123456789+-. ,\n", c))
		return (TRUE);
	return (FALSE);
}

/**
 * @brief ある行全体がホワイトリスト内かチェック
 *
 * @param line
 * @return 行全体がホワイトリスト内ならTRUE, そうでないならFALSE
 */
int	is_valid_chars_line(const char *line)
{
	size_t	i;

	if (!line)
		return (FALSE);
	i = 0;
	while (line[i])
	{
		if (!is_allowed_char(line[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
