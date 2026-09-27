/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 10:03:14 by yurishik          #+#    #+#             */
/*   Updated: 2026/09/27 10:59:11 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define NO_ERROR 0
# define HAS_ERROR 1

// check_args.c
int	valid_extension(const char *filename, const char *ext);
int	check_args(int argc, char **argv);

// error.c
int	print_error(const char *msg);

#endif
