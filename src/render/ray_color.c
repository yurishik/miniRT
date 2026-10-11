/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:29:36 by hisasano          #+#    #+#             */
/*   Updated: 2026/10/11 17:38:32 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_vec3	ray_color(t_ray ray, const t_scene *scene)
{
	t_hit	hit;

	if (!find_nearest_hit(scene, ray, &hit))
		return (vec_new(0.0, 0.0, 0.0));
	return (compute_lighting(scene, &hit));
}
