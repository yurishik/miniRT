/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_scalar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 19:49:08 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/22 20:09:46 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Return a vector multiplied by a scalar
 *
 */
t_vec3	vec_mult(t_vec3 v, double k)
{
	v.x *= k;
	v.y *= k;
	v.z *= k;
	return (v);
}

/**
 * @brief Return a vector divided by a scalar
 *
 */
t_vec3	vec_div(t_vec3 v, double k)
{
	if (-EPSILON < k && k < EPSILON)
		return (vec_new(0, 0, 0));
	v.x /= k;
	v.y /= k;
	v.z /= k;
	return (v);
}
