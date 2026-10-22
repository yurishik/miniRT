/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 17:46:54 by hisasano          #+#    #+#             */
/*   Updated: 2026/10/22 20:39:07 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"

/**
 * @brief Calculate the outward surface normal of a cylinder.
 *
 * Returns the cylinder axis for the top cap and its opposite for the
 * bottom cap. For the curved side, removes the axial component of the
 * point offset from the center and normalizes the resulting vector.
 *
 * @param cy Cylinder containing the center and axis.
 * @param point Point on the cylinder surface.
 * @param face Cylinder face (top, bottom, or side).
 * @return The outward surface normal vector.
 */
t_vec3	cyl_normal(const t_cylinder *cy, t_vec3 point, t_cy_face face)
{
	t_vec3	q;
	t_vec3	normal;

	if (face == CY_TOP)
		return (cy->axis);
	if (face == CY_BOTTOM)
		return (vec_mult(cy->axis, -1.0));
	q = vec_sub(point, cy->center);
	normal = vec_sub(q, vec_mult(cy->axis, vec_dot(q, cy->axis)));
	return (vec_normalize(normal));
}
