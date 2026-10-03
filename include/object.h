/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:20:25 by hisasano          #+#    #+#             */
/*   Updated: 2026/10/02 17:09:34 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vec3.h"

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

typedef struct s_sphere
{
	t_vec3	center;
	double	radius;
}	t_sphere;
// sp 0,0,20 20 255,0,0
//    ↓       ↓   ↓
//  center diameter color

typedef struct s_plane
{
	t_vec3	point;
	t_vec3	normal;
}	t_plane;
// pl 0,0,0 0,1,0 255,0,225
//    ↓      ↓       ↓
//  point   normal   color

typedef struct s_cylinder
{
	t_vec3	center;
	t_vec3	axis;
	double	radius;
	double	height;
}	t_cylinder;
// cy 50,0,20 0,0,1 14.2 21.42 10,0,255
//    ↓        ↓      ↓    ↓      ↓
//  center    axis diameter height color

typedef enum e_object_type
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER
}	t_object_type;

typedef union u_shape
{
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
}	t_shape;

typedef struct s_object
{
	t_object_type	type;
	t_color			color;
	t_shape			shape;
	struct s_object	*next;
}	t_object;

#endif

//使い方↓
// object.type = OBJ_CYLINDER;

// object.shape.cylinder.center.x = 50;
// object.shape.cylinder.center.y = 0;
// object.shape.cylinder.center.z = 20;

// object.shape.cylinder.axis.x = 0;
// object.shape.cylinder.axis.y = 0;
// object.shape.cylinder.axis.z = 1;

// object.shape.cylinder.diameter = 14.2;
// object.shape.cylinder.height = 21.42;
