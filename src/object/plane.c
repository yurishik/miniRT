/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 18:29:41 by hisasano          #+#    #+#             */
/*   Updated: 2026/10/22 20:33:12 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include <math.h>

/**
 * @brief Find the intersection between a ray and a plane.
 *
 * Computes the intersection distance and stores the hit point and normal.
 * Returns no hit if the ray is parallel to the plane or the intersection
 * is too close or behind the ray origin. The normal faces the incoming ray.
 *
 * @param ray Ray to test for intersection.
 * @param plane Plane to intersect with the ray.
 * @param hit Structure used to store the intersection information.
 * @return 1 if an intersection is found, otherwise 0.
 */
int	hit_plane(t_ray ray, const t_plane *plane, t_hit *hit)
{
	double	denom;
	double	t;
	t_vec3	diff;

	denom = vec_dot(ray.direction, plane->normal);
	if (fabs(denom) < EPSILON)
		return (0);
	diff = vec_sub(plane->point, ray.origin);
	t = vec_dot(diff, plane->normal) / denom;
	if (t <= EPSILON)
		return (0);
	hit->t = t;
	hit->point = vec_add(ray.origin, vec_mult(ray.direction, t));
	hit->normal = plane->normal;
	if (denom > 0)
		hit->normal = vec_negate(hit->normal);
	return (1);
}
