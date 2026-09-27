/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 10:03:19 by yurishik          #+#    #+#             */
/*   Updated: 2026/09/27 12:58:51 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	char				**lines;
	t_element_counts	counts;

	if (check_args(argc, argv) == HAS_ERROR)
		return (1);
	lines = read_valid_lines(argv[1]);
	if (!lines)
		return (print_error("Failed to read file"));
	print_char_array_for_debug(lines);
	if (validate_structure(lines, &counts) == HAS_ERROR)
	{
		free_str_array(lines);
		return (1);
	}
	print_element_counts_for_debug(&counts);
	free_str_array(lines);
	return (0);
}
