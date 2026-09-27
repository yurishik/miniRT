/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 20:07:16 by yurishik          #+#    #+#             */
/*   Updated: 2026/09/27 20:28:22 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief ベクトルの長さの２乗を返す
 *
 */
double	vec_length_squared(t_vec3 v)
{
	double	result;

	result = v.x * v.x + v.y * v.y + v.z * v.z;
	return (result);
}

/**
 * @brief ベクトルの長さを返す
 * 
 */
double	vec_length(t_vec3 v)
{
	return (sqrt(vec_length_squared(v)));
}

/**
 * @brief 正規化されたベクトルを返す
 * 
 */
t_vec3	vec_normalize(t_vec3 v)
{
	double	length;

	length = vec_length(v);
	if (length < EPSILON)
		return (vec_new(0, 0, 0));
	v.x /= length;
	v.y /= length;
	v.z /= length;
	return (v);
}
