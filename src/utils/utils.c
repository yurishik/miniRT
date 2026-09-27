/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 11:12:51 by yurishik          #+#    #+#             */
/*   Updated: 2026/09/27 13:01:22 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief ある文字がスペースかどうか判定する
 *
 * @param c
 * @return TRUE/FALSE
 */
int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (TRUE);
	return (FALSE);
}

/**
 * @brief get_next_lineで取得したlineの末尾の\nを削除する
 *
 * @param fd
 * @return line \nを削除したline
 */
char	*get_next_line_trim(int fd)
{
	char	*line;
	size_t	len;

	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

/**
 * @brief 文字列の配列を free する
 *
 * @param arr freeしたい配列
 */
void	free_str_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
