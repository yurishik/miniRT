#include "render.h"

static int	intersect_object(t_ray ray, const t_object *object, t_hit *hit)
{
	if (object->type == OBJ_SPHERE)
		return (hit_sphere(ray, &object->shape.sphere, hit));
	
	/* TODO: Plane intersection
	 * ray と plane の交差判定を行い、
	 * hit->t / hit->point / hit->normal を設定する。
	 */

	/* TODO: Cylinder intersection
	 * ray と有限円柱の交差判定を行い、
	 * 側面・上面・下面を含めて最も近い交点を設定する。
	 */
	return (0);
}

int	find_nearest_hit(const t_scene *scene, t_ray ray, t_hit *hit)
{
	t_object	*object;
	t_hit		candidate;
	double		closest;
	int			found;

	object = scene->objects;
	closest = 1.0e30;
	found = 0;
	while (object)
	{
		if (intersect_object(ray, object, &candidate)
			&& candidate.t < closest)
		{
			closest = candidate.t;
			*hit = candidate;
			hit->color = object->color;
			found = 1;
		}
		object = object->next;
	}
	return (found);
}
