/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 10:03:14 by yurishik          #+#    #+#             */
/*   Updated: 2026/09/27 12:53:55 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_element_counts	t_element_counts;

// check_args.c
int		valid_extension(const char *filename, const char *ext);
int		check_args(int argc, char **argv);

// error.c
int		print_error(const char *msg);

// validate_line.c
int		is_blank_line(const char *line);
int		is_allowed_char(char c);
int		is_valid_chars_line(const char *line);

// read_file.c
char	**read_valid_lines(const char *path);

// validate_structure.c
int		validate_structure(char **lines, t_element_counts *counts);

#endif
