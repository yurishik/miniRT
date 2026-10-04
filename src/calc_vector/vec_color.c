/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:17:39 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/04 15:17:40 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	color_to_vec(t_color c)
{
	return (vec_new(c.r / 255.0, c.g / 255.0, c.b / 255.0));
}

t_color	vec_to_color(t_vec3 v)
{
	t_color	c;

	v = vec_clamp(v, 0.0, 1.0);
	c.r = v.x * 255.0;
	c.g = v.y * 255.0;
	c.b = v.z * 255.0;
	return (c);
}
