#include "render.h"

t_vec3	ray_color(t_ray ray, const t_scene *scene)
{
	t_hit	hit;
    /* TODO:[hiro] 将来的に条件分岐　sphere　plane　cylinder*/
	// if (!find_nearest_hit(scene, ray, &hit))
	if (!hit_sphere(ray, &scene->objects->shape.sphere, &hit))
		return (vec_new(0.0, 0.0, 0.0));
	hit.color = scene->objects->color;
	return (compute_lighting(scene, &hit));
}
