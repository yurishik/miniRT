/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 18:29:41 by hisasano          #+#    #+#             */
/*   Updated: 2026/10/09 20:53:10 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "minirt.h"
#include <math.h>


int hit_plane(t_ray ray, const t_plane *plane, t_hit *hit)
{
    double  denom;
    double  t;
    t_vec3  diff;

    //　Rayの方向と平面の法線の内積
    denom = vec_dot(ray.direction, plane->normal);

    if (fabs(denom) < EPSILON)
        return (0);

    //　Rayの始点から平面の基準点へのベクトル
    diff = vec_sub(plane->point, ray.origin);

    //  Rayと平面の交点までのtを計算
    t = vec_dot(diff, plane->normal) / denom;

    if (t <= EPSILON)
        return (0);

    hit->t = t;

    // 交点の座標を計算
    hit->point = vec_add(ray.origin, vec_mult(ray.direction, t));

    // 交点の法線を設定
    hit->normal = plane->normal;

    // 法線がRayと同じ向きなら反転
    if (denom > 0)
        hit->normal = vec_negate(hit->normal);

    return (1);
}
