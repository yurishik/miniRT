#include "render.h"

static t_vec3	calc_ambient_color(t_color obj_color,
		const t_ambient *ambient)
{
	t_vec3	c_obj;
	t_vec3	c_amb;
	t_vec3	color;

	c_obj = color_to_vec(obj_color);
	c_amb = color_to_vec(ambient->color);
	color = vec_mult_vec(c_obj, c_amb);
	return (vec_mult(color, ambient->ratio));
}

static t_vec3	calc_diffuse_color(const t_hit *hit,
		const t_light *light)
{
	t_vec3	light_dir;
	t_vec3	c_obj;
	t_vec3	c_light;
	double	diff;

	light_dir = vec_normalize(vec_sub(light->position, hit->point));
	diff = vec_dot(hit->normal, light_dir);
	if (diff < 0.0)
		diff = 0.0;
	c_obj = color_to_vec(hit->color);
	c_light = color_to_vec(light->color);
	return (vec_mult_vec(c_obj,
			vec_mult(c_light, diff * light->brightness)));
}

t_vec3	compute_lighting(const t_scene *scene, const t_hit *hit)
{
	t_vec3	ambient_color;
	t_vec3	diffuse_color;

	ambient_color = calc_ambient_color(hit->color, &scene->ambient);
	/* TODO: Hard Shadow
	 * hit->point から light.position へ shadow ray を飛ばす。
	 * light までの間に別objectとの交点があれば影と判断し、
	 * diffuse_color を加算しない。
	 *
	 * find_nearest_hit() を再利用する想定。
	 */
	diffuse_color = calc_diffuse_color(hit, &scene->light);
	return (vec_clamp(vec_add(ambient_color, diffuse_color), 0.0, 1.0));
}
