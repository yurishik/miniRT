/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_structure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 12:12:59 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/22 19:47:49 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Check whether an identifier matches exactly
 * 
 * @param str Input string
 * @param id Identifier to match
 * @return TRUE on an exact match, otherwise FALSE
 */
static int	is_id_match(const char *str, const char *id)
{
	size_t	id_len;

	id_len = ft_strlen(id);
	if (ft_strncmp(str, id, id_len) != 0)
		return (FALSE);
	if (ft_isspace(str[id_len]))
		return (TRUE);
	return (FALSE);
}

/**
 * @brief Skip leading whitespace and find the line identifier
 * 
 * @param line
 * @return Matching identifier
 */
static const char	*find_matching_id(const char *line)
{
	static const char	*valid_ids[] = {
		ID_AMBIENT, ID_CAMERA, ID_LIGHT,
		ID_SPHERE, ID_PLANE, ID_CYLINDER,
		NULL
	};
	int					i;

	while (ft_isspace(*line))
		line++;
	if (*line == '\0')
		return (NULL);
	i = 0;
	while (valid_ids[i])
	{
		if (is_id_match(line, valid_ids[i]))
			return (valid_ids[i]);
		i++;
	}
	return (NULL);
}

/**
 * @brief Increment the count for the given identifier
 * 
 * @param id Identifier
 * @param counts Element count structure
 */
static void	increment_count(const char *id, t_element_counts *counts)
{
	if (ft_strcmp(id, ID_AMBIENT) == 0)
		counts->ambient_count++;
	else if (ft_strcmp(id, ID_CAMERA) == 0)
		counts->camera_count++;
	else if (ft_strcmp(id, ID_LIGHT) == 0)
		counts->light_count++;
	else if (ft_strcmp(id, ID_SPHERE) == 0)
		counts->sphere_count++;
	else if (ft_strcmp(id, ID_PLANE) == 0)
		counts->plane_count++;
	else if (ft_strcmp(id, ID_CYLINDER) == 0)
		counts->cylinder_count++;
}

/**
 * @brief Count each element and total objects (TODO remove if unnecessary)
 * 
 * @param lines Array of strings
 * @param counts Structure holding element counts
 * @return HAS_ERROR/NO_ERROR
 */
static int	count_all_elements(char **lines, t_element_counts *counts)
{
	int			i;
	const char	*id;

	i = 0;
	while (lines[i])
	{
		id = find_matching_id(lines[i]);
		if (!id)
			return (print_error("Invalid identifier"));
		increment_count(id, counts);
		i++;
	}
	counts->total_objects = counts->sphere_count
		+ counts->plane_count
		+ counts->cylinder_count;
	return (NO_ERROR);
}

/**
 * @brief Verify that exactly one A, C, and L element exists
 * 
 * @param lines Array of strings
 * @param counts Structure holding element counts
 * @return HAS_ERROR/NO_ERROR
 */
int	validate_structure(char **lines, t_element_counts *counts)
{
	if (!lines || !lines[0])
		return (print_error("File is empty"));
	ft_bzero(counts, sizeof(t_element_counts));
	if (count_all_elements(lines, counts) == HAS_ERROR)
		return (HAS_ERROR);
	if (counts->ambient_count != 1)
		return (print_error("Invalid number of A"));
	if (counts->camera_count != 1)
		return (print_error("Invalid number of C"));
	if (counts->light_count != 1)
		return (print_error("Invalid number of L"));
	return (NO_ERROR);
}
