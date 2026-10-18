/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_caps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 23:36:37 by hisasano          #+#    #+#             */
/*   Updated: 2026/10/18 17:46:41 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cyl.h"
#include "minirt.h"
#include "render.h"
#include <math.h>

static void	cyl_update_nearest(t_cy_hit *nearest, double t, t_cy_face face)
{
	if (t <= EPSILON)
		return ;
	if (nearest->t < 0.0 || t < nearest->t)
	{
		nearest->t = t;
		nearest->face = face;
	}
}

t_cy_hit	cyl_nearest(double t_side, double t_top, double t_bottom)
{
	t_cy_hit	nearest;

	nearest.t = -1.0;
	nearest.face = CY_SIDE;
	cyl_update_nearest(&nearest, t_side, CY_SIDE);
	cyl_update_nearest(&nearest, t_top, CY_TOP);
	cyl_update_nearest(&nearest, t_bottom, CY_BOTTOM);
	return (nearest);
}

double	cyl_cap(t_ray ray, const t_cylinder *cy, t_vec3 cap_center)
{
	double	denom;
	double	t;
	t_vec3	point;
	t_vec3	q;

	denom = vec_dot(ray.direction, cy->axis);
	if (fabs(denom) <= EPSILON)
		return (-1.0);
	t = vec_dot(vec_sub(cap_center, ray.origin), cy->axis) / denom;
	if (t <= EPSILON)
		return (-1.0);
	point = vec_add(ray.origin, vec_mult(ray.direction, t));
	q = vec_sub(point, cap_center);
	if (vec_dot(q, q) > cy->radius * cy->radius)
		return (-1.0);
	return (t);
}
