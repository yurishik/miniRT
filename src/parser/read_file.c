/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 11:00:26 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/22 19:36:18 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Do nothing (callback for ft_lstclear)
 *
 */
static void	do_nothing(void *content)
{
	(void)content;
}

/**
 * @brief Append a line to the linked list
 *
 * @param line_list Pointer to the head of the linked list
 * @return TRUE on success, FALSE on failure
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
 * @brief Convert a linked list to an array
 *
 * @param line_list Pointer to the head of the linked list
 * @return Array of strings converted from the list
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
	ft_lstclear(line_list, do_nothing);
	return (lines);
}

/**
 * @brief Drain the file and free data after a read error
 *
 * @param fd
 * @param line_list Head pointer of the list of lines read so far
 * @param line Most recently read line
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
 * @brief Read lines, remove trailing \n and blank lines, and return an array
 *
 * @param filepath
 * @return Array of nonblank lines without trailing \n
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
