/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sp_pl_cy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 14:38:45 by yurishik          #+#    #+#             */
/*   Updated: 2026/09/27 15:26:23 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Sphere: sp <x,y,z> <diameter> <R,G,B> (4 tokens)
 * diameter: > 0.0
 */
int	validate_sphere(char **tokens)
{
	double	diameter;

	if (count_tokens(tokens) != 4)
		return (print_error("Sphere: Invalid argument count (expected 4)"));
	if (!is_valid_vector_format(tokens[1]))
		return (print_error("Sphere: Invalid center coordinates"));
	if (!is_valid_double_str(tokens[2]))
		return (print_error("Sphere: Diameter must be a valid double"));
	if (!is_valid_rgb_format(tokens[3]))
		return (print_error("Sphere: Invalid RGB format"));
	diameter = ft_atof(tokens[2]);
	if (diameter <= 0.0)
		return (print_error("Sphere: Diameter must be greater than 0"));
	return (NO_ERROR);
}

/**
 * @brief Plane: pl <x,y,z> <nx,ny,nz> <R,G,B> (4 tokens)
 * nx,ny,nz: [-1.0, 1.0], not zero vector
 */
int	validate_plane(char **tokens)
{
	if (count_tokens(tokens) != 4)
		return (print_error("Plane: Invalid argument count (expected 4)"));
	if (!is_valid_vector_format(tokens[1]))
		return (print_error("Plane: Invalid point coordinates"));
	if (!is_valid_orientation_format(tokens[2]))
		return (print_error("Plane: Invalid normal vector"));
	if (!is_valid_rgb_format(tokens[3]))
		return (print_error("Plane: Invalid RGB format"));
	return (NO_ERROR);
}

/**
 * @brief Cylinder: cy <x,y,z> <nx,ny,nz> <diameter> <height> <R,G,B> (6 tokens)
 * nx,ny,nz: [-1.0, 1.0], not zero vector
 * diameter: > 0.0, height: > 0.0
 */
int	validate_cylinder(char **tokens)
{
	double	diameter;
	double	height;

	if (count_tokens(tokens) != 6)
		return (print_error("Cylinder: Invalid argument count (expected 6)"));
	if (!is_valid_vector_format(tokens[1]))
		return (print_error("Cylinder: Invalid center coordinates"));
	if (!is_valid_orientation_format(tokens[2]))
		return (print_error("Cylinder: Invalid axis normal vector"));
	if (!is_valid_double_str(tokens[3]) || !is_valid_double_str(tokens[4]))
		return (print_error("Cylinder: Invalid format"));
	if (!is_valid_rgb_format(tokens[5]))
		return (print_error("Cylinder: Invalid RGB format"));
	diameter = ft_atof(tokens[3]);
	height = ft_atof(tokens[4]);
	if (diameter <= 0.0 || height <= 0.0)
		return (print_error("Cylinder: Invalid value (must be positive)"));
	return (NO_ERROR);
}
