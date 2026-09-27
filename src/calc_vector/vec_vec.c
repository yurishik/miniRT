/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 19:51:22 by yurishik          #+#    #+#             */
/*   Updated: 2026/09/27 20:06:54 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief ベクトルの足し算を行う
 *
 */
t_vec3	vec_add(t_vec3 v1, t_vec3 v2){
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

/**
 * @brief ベクトルの引き算を行う
 *
 */
t_vec3	vec_sub(t_vec3 v1, t_vec3 v2){
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

/**
 * @brief ベクトルの内積を求める
 *
 */
double	vec_dot(t_vec3 v1, t_vec3 v2){
	double	result;

	result = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (result);
}

/**
 * @brief ベクトルの外積を求める
 *
 */
t_vec3	vec_cross(t_vec3 v1, t_vec3 v2){
	t_vec3	v;

	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v1.z * v2.x - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.x;
	return (v);
}

/**
 * @brief ベクトルのアダマール積を求める（要素同士を掛け算して新たなベクトルを作成する）
 *
 */
t_vec3	vec_mult_vec(t_vec3 v1, t_vec3 v2){
	v1.x *= v2.x;
	v1.y *= v2.y;
	v1.z *= v2.z;
	return (v1);
}
