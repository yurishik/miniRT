/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 17:12:44 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/22 20:27:38 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Read and parse a scene description file.
 *
 * Validates the scene structure and each line, then populates the scene.
 * Frees the temporary line array after validation.
 *
 * @param scene Scene structure to populate with parsed data.
 * @param filename Path to the scene description file.
 * @return NO_ERROR on success, or HAS_ERROR if reading or validation fails.
 */
int	parse_scene(t_scene *scene, const char *filename)
{
	char				**lines;
	t_element_counts	counts;

	lines = read_valid_lines(filename);
	if (!lines)
		return (print_error("Failed to read file"));
	if (validate_structure(lines, &counts) == HAS_ERROR
		|| validate_lines(lines, scene) == HAS_ERROR)
	{
		free_str_array(lines);
		return (HAS_ERROR);
	}
	free_str_array(lines);
	return (NO_ERROR);
}
