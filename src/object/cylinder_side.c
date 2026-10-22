/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_side.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 17:47:11 by hisasano          #+#    #+#             */
/*   Updated: 2026/10/22 20:37:23 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cyl.h"
#include "minirt.h"
#include "render.h"
#include <math.h>

/**
 * @brief Calculate the quadratic coefficients for the cylinder side.
 *
 * Projects the ray origin offset and direction onto the plane perpendicular
 * to the cylinder axis, then computes the coefficients and discriminant.
 *
 * @param ray Ray to test against the cylinder.
 * @param cy Cylinder containing the axis and radius.
 * @param q Structure used to store the quadratic equation data.
 */
static void	cyl_quadratic(t_ray ray, const t_cylinder *cy, t_cy_quad *q)
{
	q->w = vec_sub(ray.origin, cy->center);
	q->d_perp = vec_sub(ray.direction, vec_mult(cy->axis, vec_dot(ray.direction,
					cy->axis)));
	q->w_perp = vec_sub(q->w, vec_mult(cy->axis, vec_dot(q->w, cy->axis)));
	q->a = vec_dot(q->d_perp, q->d_perp);
	q->b = 2.0 * vec_dot(q->w_perp, q->d_perp);
	q->c = vec_dot(q->w_perp, q->w_perp) - cy->radius * cy->radius;
	q->disc = q->b * q->b - 4.0 * q->a * q->c;
}

/**
 * @brief Check whether a ray parameter hits the finite cylinder side.
 *
 * Rejects intersections behind or too close to the ray origin and points
 * outside the cylinder's height along its axis.
 *
 * @param ray Ray being tested.
 * @param cy Cylinder whose side is being tested.
 * @param w Vector from the cylinder center to the ray origin.
 * @param t Ray parameter for the candidate intersection.
 * @return 1 if the intersection is valid, otherwise 0.
 */
static int	cyl_side_root(t_ray ray, const t_cylinder *cy, t_vec3 w, double t)
{
	double	h;

	if (t <= EPSILON)
		return (0);
	h = vec_dot(w, cy->axis) + t * vec_dot(ray.direction, cy->axis);
	if (h < -cy->height / 2.0)
		return (0);
	if (h > cy->height / 2.0)
		return (0);
	return (1);
}

/**
 * @brief Find the nearest valid ray intersection with a cylinder side.
 *
 * Solves the quadratic equation for the infinite cylinder and checks
 * whether either intersection lies within the finite cylinder's height.
 *
 * @param ray Ray to test for intersection.
 * @param cy Cylinder to intersect with the ray.
 * @return The nearest valid ray parameter, or -1.0 if there is no hit.
 */
double	cyl_side(t_ray ray, const t_cylinder *cy)
{
	t_cy_quad	q;
	double		t1;
	double		t2;

	cyl_quadratic(ray, cy, &q);
	if (q.a <= EPSILON || q.disc < 0.0)
		return (-1.0);
	t1 = (-q.b - sqrt(q.disc)) / (2.0 * q.a);
	t2 = (-q.b + sqrt(q.disc)) / (2.0 * q.a);
	if (cyl_side_root(ray, cy, q.w, t1))
		return (t1);
	if (cyl_side_root(ray, cy, q.w, t2))
		return (t2);
	return (-1.0);
}
