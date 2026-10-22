/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_caps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 23:36:37 by hisasano          #+#    #+#             */
/*   Updated: 2026/10/22 20:41:15 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cyl.h"
#include "minirt.h"
#include "render.h"
#include <math.h>

/**
 * @brief Update the nearest valid cylinder intersection.
 *
 * Ignores intersections at or behind EPSILON and keeps the closest hit.
 *
 * @param nearest Current nearest hit information to update.
 * @param t Intersection distance to check.
 * @param face Cylinder face associated with the intersection.
 */
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

/**
 * @brief Select the nearest valid intersection on a cylinder.
 *
 * Compares the side, top cap, and bottom cap intersection distances.
 *
 * @param t_side Intersection distance to the cylinder side.
 * @param t_top Intersection distance to the top cap.
 * @param t_bottom Intersection distance to the bottom cap.
 * @return The closest hit and its face, or a negative distance if none.
 */
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

/**
 * @brief Calculate the intersection of a ray with a cylinder end cap.
 *
 * Intersects the ray with the cap plane and checks whether the hit point
 * lies within the cap radius.
 *
 * @param ray Ray to test for intersection.
 * @param cy Cylinder containing the axis and radius.
 * @param cap_center Center position of the cap to test.
 * @return Intersection distance, or -1.0 if there is no valid hit.
 */
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
