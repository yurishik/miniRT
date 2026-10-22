/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:53:42 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/22 19:51:55 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#include "render.h"
#include <math.h>

/**
 * @brief Check ray-sphere intersection and calculate the nearest hit distance t.
 *
 * Derive a quadratic equation from the sphere and ray equations, then use
 * its discriminant to determine whether an intersection occurs.
 * Assuming the ray direction is normalized (|ray.direction| = 1.0),
 * use the half-b form (b = 2h) to avoid division and optimize calculations.
 * Accept only positive solutions greater than EPSILON to prevent
 * self-intersections (such as shadow acne).
 * Reverse the normal vector when viewing the sphere from the inside.
 *
 * @param ray Ray to test for intersection.
 * @param sp Sphere data, including its center and radius.
 * @param hit Pointer to the structure storing intersection information.
 * @return TRUE if hit; FALSE if no hit (or farther than max_t).
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
		t = -h + sqrtd;
	if (t <= EPSILON)
		return (FALSE);
	hit->t = t;
	hit->point = vec_add(ray.origin, vec_mult(ray.direction, t));
	hit->normal = vec_normalize(vec_sub(hit->point, sp->center));
	if (vec_dot(ray.direction, hit->normal) > 0)
	{
		hit->normal = vec_mult(hit->normal, -1.0);
	}
	return (TRUE);
}
