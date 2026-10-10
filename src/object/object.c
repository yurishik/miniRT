/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:49:56 by hisasano          #+#    #+#             */
/*   Updated: 2026/10/09 18:44:38 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "minirt.h"
#include <math.h>

static int hit_object(t_ray ray, const t_object *obj, t_hit *hit)
{
    if (obj->type == OBJ_SPHERE)
        return (hit_sphere(ray, &obj->shape.sphere, hit));
    if (obj->type == OBJ_PLANE)
        return (hit_plane(ray, &obj->shape.plane, hit));

	/* TODO: Cylinder intersection
	 * ray と有限円柱の交差判定を行い、
	 * 側面・上面・下面を含めて最も近い交点を設定する。
	 */
	return (0);
}

int	find_nearest_hit(const t_scene *scene, t_ray ray, t_hit *hit)
{
    const t_object *obj;
    t_hit temp;
    double  closest;
    int found;

    obj = scene->objects;
    closest = INFINITY;
    found = 0;
    while(obj)
    {
        if (hit_object(ray, obj, &temp)
            && temp.t > EPSILON && temp.t < closest)
        {
            closest = temp.t;
            *hit = temp;
            hit->color = obj->color;
            found = 1;
        }
        obj = obj->next;
    }
    return (found);
}
