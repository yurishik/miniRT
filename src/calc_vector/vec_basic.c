/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_basic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 19:40:05 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/04 15:52:10 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief x,y,zの値を渡して新しくベクトルを作成する
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
 * @brief 向きが反対のベクトルを返す
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
 * @brief ベクトルの各成分を指定した最小値・最大値の範囲内に収める（クランプ処理）
 *
 * @param v 対象のベクトル
 * @param min 下限値
 * @param max 上限値
 * @return 範囲内に制限された新しいベクトル
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
