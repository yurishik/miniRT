/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_side.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 17:47:11 by hisasano          #+#    #+#             */
/*   Updated: 2026/10/18 17:47:18 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cyl.h"
#include "minirt.h"
#include "render.h"
#include <math.h>

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
