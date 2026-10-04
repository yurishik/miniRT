/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:53:42 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/04 18:06:45 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief レイと球体の交差判定を行い、最も手前の交点までの距離tを計算する
 * 
 * 球面の方程式とレイの直線方程式から2次方程式を立て、判別式を用いて衝突判定を行う。
 * レイの方向ベクトルが正規化済み (|ray.direction| = 1.0) であることを前提に、
 * 2次方程式の偶数公式 (b = 2h) を用いて割り算を排除し計算を最適化している。
 * 自己交差（シャドウアクネ等）を防止するため、EPSILON 以上の正の解のみを採用する。
 *
 * @param ray 判定対象のレイ
 * @param sp 判定対象の球体データ（中心座標、半径など）
 * @param hit 衝突情報を格納する構造体ポインタ
 * @return 衝突した場合TRUE、衝突しない（またはmax_tより遠い）場合はFALSE
 */
int	hit_sphere(t_ray ray, const t_sphere *sp, t_hit *hit)
{
	t_vec3	oc;
	double	h;
	double	d;
	double	sqrtd;
	double	t;

	oc = vec_sub(ray.origin, sp->center);
	h = vec_dot(oc, ray.direction);
	d = h * h - (vec_dot(oc, oc) - (sp->radius * sp->radius));
	if (d < 0.0)
		return (FALSE);
	sqrtd = sqrt(d);
	t = -h - sqrtd;
	if (t <= EPSILON)
	{
		t = -h + sqrtd;
		if (t <= EPSILON)
			return (FALSE);
	}
	hit->t = t;
	hit->point = vec_add(ray.origin, vec_mult(ray.direction, t));
	hit->normal = vec_normalize(vec_sub(hit->point, sp->center));
	return (TRUE);
}
