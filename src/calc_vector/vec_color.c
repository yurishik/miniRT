/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:17:39 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/22 20:22:07 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Convert an RGB color to a normalized vector.
 *
 * Converts each color component from the range [0, 255] to [0.0, 1.0].
 *
 * @param c RGB color to convert.
 * @return A vector containing the normalized RGB components.
 */
t_vec3	color_to_vec(t_color c)
{
	return (vec_new(c.r / 255.0, c.g / 255.0, c.b / 255.0));
}

/**
 * @brief Convert a normalized vector to an RGB color.
 *
 * Clamps each component to [0.0, 1.0], then scales it to [0, 255].
 *
 * @param v Vector containing normalized RGB components.
 * @return The converted RGB color.
 */
t_color	vec_to_color(t_vec3 v)
{
	t_color	c;

	v = vec_clamp(v, 0.0, 1.0);
	c.r = v.x * 255.0;
	c.g = v.y * 255.0;
	c.b = v.z * 255.0;
	return (c);
}
