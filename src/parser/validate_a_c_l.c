/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_a_c_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 14:38:45 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/06 21:03:36 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief 文字列配列の行数を数える(tokenの数を数える)
 */
size_t	count_tokens(char **tokens)
{
	size_t	count;

	if (!tokens)
		return (0);
	count = 0;
	while (tokens[count])
		count++;
	return (count);
}

/**
 * @brief Anbientのバリデーションを行う
 */
int	validate_ambient(char **tokens)
{
	double	ratio;

	if (count_tokens(tokens) != 3)
		return (print_error("Ambient: Invalid argument count (expected 3)"));
	if (!is_valid_double_str(tokens[1]))
		return (print_error("Ambient: Ratio must be a valid double"));
	if (!is_valid_rgb_format(tokens[2]))
		return (print_error("Ambient: Invalid RGB format"));
	ratio = ft_atof(tokens[1]);
	if (ratio < 0.0 || ratio > 1.0)
		return (print_error("Ambient: Ratio out of range [0.0, 1.0]"));
	return (NO_ERROR);
}

/**
 * @brief Camera: C <x,y,z> <nx,ny,nz> <fov> (4 tokens)
 * nx,ny,nz: [-1.0, 1.0], not zero vector
 * fov: [0, 180] (but actually (0, 180))
 */
int	validate_camera(char **tokens)
{
	double	fov;

	if (count_tokens(tokens) != 4)
		return (print_error("Camera: Invalid argument count (expected 4)"));
	if (!is_valid_vector_format(tokens[1]))
		return (print_error("Camera: Invalid position coordinates"));
	if (!is_valid_orientation_format(tokens[2]))
		return (print_error("Camera: Invalid orientation vector"));
	if (!is_valid_int_str(tokens[3]))
		return (print_error("Camera: FOV must be a valid number"));
	fov = ft_atoi(tokens[3]);
	if (fov < 0 || fov > 180)
		return (print_error("Camera: FOV out of range [0, 180]"));
	if (fov == 0)
		return (print_error("Camera: FOV cannot be 0 (division by zero)"));
	if (fov == 180)
		return (print_error("Camera: FOV cannot be 180 (infinite viewport)"));
	return (NO_ERROR);
}

/**
 * @brief Light: L <x,y,z> <brightness> <R,G,B> (4 tokens)
 * brightness: [0.0, 1.0]
 */
int	validate_light(char **tokens)
{
	double	brightness;

	if (count_tokens(tokens) != 4)
		return (print_error("Light: Invalid argument count (expected 4)"));
	if (!is_valid_vector_format(tokens[1]))
		return (print_error("Light: Invalid light position"));
	if (!is_valid_double_str(tokens[2]))
		return (print_error("Light: Brightness must be a valid double"));
	if (!is_valid_rgb_format(tokens[3]))
		return (print_error("Light: Invalid RGB format"));
	brightness = ft_atof(tokens[2]);
	if (brightness < 0.0 || brightness > 1.0)
		return (print_error("Light: Brightness out of range [0.0, 1.0]"));
	return (NO_ERROR);
}
