/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_scolar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 19:49:08 by yurishik          #+#    #+#             */
/*   Updated: 2026/09/27 20:25:22 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief あるベクトルを定数倍したベクトルを返す
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
 * @brief あるベクトルを定数で除算したベクトルを返す
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

