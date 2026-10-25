/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:20:25 by hisasano          #+#    #+#             */
/*   Updated: 2026/10/25 11:42:41 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vec3.h"

typedef struct s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

typedef struct s_sphere
{
	t_vec3			center;
	double			radius;
}					t_sphere;

typedef struct s_plane
{
	t_vec3			point;
	t_vec3			normal;
}					t_plane;

typedef enum e_cy_face
{
	CY_SIDE,
	CY_TOP,
	CY_BOTTOM
}					t_cy_face;

typedef struct s_cy_hit
{
	double			t;
	t_cy_face		face;
}					t_cy_hit;

typedef struct s_cy_quad
{
	t_vec3			w;
	t_vec3			d_perp;
	t_vec3			w_perp;
	double			a;
	double			b;
	double			c;
	double			disc;
}					t_cy_quad;

typedef struct s_cylinder
{
	t_vec3			center;
	t_vec3			axis;
	double			radius;
	double			height;
}					t_cylinder;

typedef enum e_object_type
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER
}					t_object_type;

typedef union u_shape
{
	t_sphere		sphere;
	t_plane			plane;
	t_cylinder		cylinder;
}					t_shape;

typedef struct s_object
{
	t_object_type	type;
	t_color			color;
	t_shape			shape;
	struct s_object	*next;
}					t_object;

t_vec3				color_to_vec(t_color color);
t_color				vec_to_color(t_vec3 vector);

#endif
