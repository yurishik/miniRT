/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 20:14:23 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/25 11:41:40 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "object.h"

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

typedef struct s_camera
{
	t_vec3	position;
	t_vec3	direction;
	t_vec3	right;
	t_vec3	up;
	double	fov;
}	t_camera;

typedef struct s_ambient
{
	double	ratio;
	t_color	color;
}	t_ambient;

typedef struct s_light
{
	t_vec3	position;
	double	brightness;
	t_color	color;
}	t_light;

typedef struct s_hit
{
	double	t;
	t_vec3	point;
	t_vec3	normal;
	t_color	color;
}	t_hit;
// double  t;        Ray parameter at the intersection
// t_vec3  point;    Intersection point in 3D space
// t_vec3  normal;   Surface normal vector at the intersection
// t_color color;    Base color of the intersected object

typedef struct s_scene
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_object	*objects;
}	t_scene;

#endif
