/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_basic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 19:40:05 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/22 20:07:58 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Create a new vector with the given x, y, and z values
 *
 */
t_vec3	vec_new(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

/**
 * @brief Return a vector pointing in the opposite direction
 *
 */
t_vec3	vec_negate(t_vec3 v)
{
	v.x *= -1;
	v.y *= -1;
	v.z *= -1;
	return (v);
}

/**
 * @brief Clamp each vector component to the specified range
 *
 * @param v Vector to clamp
 * @param min Lower bound
 * @param max Upper bound
 * @return New vector with components clamped to the range
 */
t_vec3	vec_clamp(t_vec3 v, double min, double max)
{
	t_vec3	res;

	res.x = v.x;
	if (res.x < min)
		res.x = min;
	else if (res.x > max)
		res.x = max;
	res.y = v.y;
	if (res.y < min)
		res.y = min;
	else if (res.y > max)
		res.y = max;
	res.z = v.z;
	if (res.z < min)
		res.z = min;
	else if (res.z > max)
		res.z = max;
	return (res);
}
