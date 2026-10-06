/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 20:14:23 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/06 20:14:27 by yurishik         ###   ########.fr       */
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
// The starting position of the ray：　origin;
// direction vector：origin　→ direction

typedef struct s_camera
{
	t_vec3	position;
	t_vec3	direction;
	double	fov;
}	t_camera;
// C -50,0,20   0,0,1   70
//      │         │       │
//      │         │       └──→ camera.fov
//      │         │
//      │         └──────────→ camera.direction
//      │
//      └────────────────────→ camera.position

typedef struct s_ambient
{
	double	ratio;
	t_color	color;
}	t_ambient;
// A 0.2 255,255,255
//   │    │
//   │    └──────────────→ ambient_r/g/b
//   │
//   └───────────────────→ ambient_ratio

typedef struct s_light
{
	t_vec3	position;
	double	brightness;
	t_color	color;
}	t_light;
// L -40,0,30   0.7   255,255,255
//      │        │         │
//      │        │         └──→ light.r/g/b
//      │        │
//      │        └────────────→ light.brightness
//      │
//      └─────────────────────→ light.position

typedef struct s_hit
{
	double	t;
	t_vec3	point;
	t_vec3	normal;
	t_color	color;
}	t_hit;

typedef struct s_scene
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_object	*objects;
}	t_scene;

#endif
