/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 17:46:17 by hisasano          #+#    #+#             */
/*   Updated: 2026/10/22 20:34:54 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include "cyl.h"
#include <math.h>

/**
 * @brief Find the nearest intersection between a ray and a cylinder.
 *
 * Tests the cylinder side and both end caps, then selects the closest
 * valid intersection. Stores the hit distance, point, and surface normal.
 *
 * @param ray Ray to test for intersection.
 * @param cy Cylinder to intersect with the ray.
 * @param hit Structure used to store the intersection information.
 * @return 1 if an intersection is found, otherwise 0.
 */
int	hit_cylinder(t_ray ray, const t_cylinder *cy, t_hit *hit)
{
	t_vec3		top_center;
	t_vec3		bottom_center;
	t_cy_hit	nearest;
	double		t_side;
	double		t_top;

	t_side = cyl_side(ray, cy);
	top_center = vec_add(cy->center, vec_mult(cy->axis, cy->height / 2.0));
	bottom_center = vec_sub(cy->center, vec_mult(cy->axis, cy->height / 2.0));
	t_top = cyl_cap(ray, cy, top_center);
	nearest = cyl_nearest(t_side, t_top, cyl_cap(ray, cy,
				bottom_center));
	if (nearest.t < 0.0)
		return (0);
	hit->t = nearest.t;
	hit->point = vec_add(ray.origin, vec_mult(ray.direction, nearest.t));
	hit->normal = cyl_normal(cy, hit->point, nearest.face);
	return (1);
}
