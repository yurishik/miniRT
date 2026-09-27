/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 11:14:12 by yurishik          #+#    #+#             */
/*   Updated: 2026/09/27 11:58:40 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// utils.c
char	*get_next_line_trim(int fd);
void	free_str_array(char **arr);
void	print_char_array_for_debug(char **array);

#endif
