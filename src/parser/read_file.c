/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 11:00:26 by yurishik          #+#    #+#             */
/*   Updated: 2026/09/27 11:53:56 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief 行を連結リストに追加する
 *
 * @param line_list linked listの先頭ポインタ
 * @return 特にエラーがなければTRUE, なにか発生したらFALSE
 */
static int	append_line(t_list **line_list, char *line)
{
	t_list	*new_node;

	new_node = ft_lstnew(line);
	if (!new_node)
		return (FALSE);
	ft_lstadd_back(line_list, new_node);
	return (TRUE);
}

/**
 * @brief 連結リスト→配列に変換する
 *
 * @param line_list linked listの先頭ポインタ
 * @return char** 配列に変換したもの
 */
static char	**convert_list_to_array(t_list **line_list)
{
	char	**lines;
	t_list	*cur;
	int		count;
	int		i;

	count = ft_lstsize(*line_list);
	lines = NULL;
	if (count >= 3)
		lines = (char **)malloc(sizeof(char *) * (count + 1));
	if (!lines)
	{
		ft_lstclear(line_list, free);
		return (NULL);
	}
	cur = *line_list;
	i = 0;
	while (cur)
	{
		lines[i++] = (char *)cur->content;
		cur = cur->next;
	}
	lines[i] = NULL;
	ft_lstclear(line_list, NULL);
	return (lines);
}

/**
 * @brief 読み込み途中のを開放する(ために一旦ファイル末尾まで読み込ませる)
 *
 * @param fd
 * @param line_list ここまで読み込んできた分がlinked listに入れてあり、その先頭ポインタ
 * @param line 直前に読み込んだ1行
 * @return NULL
 */
static char	**clean_read_error(int fd, t_list **line_list, char *line)
{
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
	}
	close(fd);
	ft_lstclear(line_list, free);
	return (NULL);
}

/**
 * @brief 1行ずつ読み込み行末の\nや空行のみを削除し、char**の配列に入れて返す
 *
 * @param filepath
 * @return 空白行がなくなったchar**の配列、行末の\nは削除されている
 */
char	**read_valid_lines(const char *filepath)
{
	int		fd;
	char	*line;
	t_list	*line_list;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line_list = NULL;
	while (1)
	{
		line = get_next_line_trim(fd);
		if (!line)
			break ;
		if (!is_blank_line(line))
		{
			if (!is_valid_chars_line(line) || !append_line(&line_list, line))
				return (clean_read_error(fd, &line_list, line));
		}
		else
			free(line);
	}
	close(fd);
	return (convert_list_to_array(&line_list));
}
