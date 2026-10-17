#include "minirt.h"
#include "render.h"

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
