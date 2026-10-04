/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sp_pl_cy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 13:29:57 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/03 13:30:19 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	set_sphere(char **tokens, t_scene *scene)
{
	t_object	*obj;

	obj = (t_object *)malloc(sizeof(t_object));
	if (!obj)
		return (print_error("Memory allocation failed"));
	ft_bzero(obj, sizeof(t_object));
	obj->type = OBJ_SPHERE;
	set_vec3_from_str(tokens[1], &obj->shape.sphere.center);
	obj->shape.sphere.radius = ft_atof(tokens[2]) / 2.0;
	set_color_from_str(tokens[3], &obj->color);
	obj_add_back(&scene->objects, obj);
	return (NO_ERROR);
}

int	set_plane(char **tokens, t_scene *scene)
{
	t_object	*obj;

	obj = (t_object *)malloc(sizeof(t_object));
	if (!obj)
		return (print_error("Memory allocation failed"));
	ft_bzero(obj, sizeof(t_object));
	obj->type = OBJ_PLANE;
	set_vec3_from_str(tokens[1], &obj->shape.plane.point);
	set_vec3_from_str(tokens[2], &obj->shape.plane.normal);
	set_color_from_str(tokens[3], &obj->color);
	obj_add_back(&scene->objects, obj);
	return (NO_ERROR);
}

int	set_cylinder(char **tokens, t_scene *scene)
{
	t_object	*obj;

	obj = (t_object *)malloc(sizeof(t_object));
	if (!obj)
		return (print_error("Memory allocation failed"));
	ft_bzero(obj, sizeof(t_object));
	obj->type = OBJ_CYLINDER;
	set_vec3_from_str(tokens[1], &obj->shape.cylinder.center);
	set_vec3_from_str(tokens[2], &obj->shape.cylinder.axis);
	obj->shape.cylinder.radius = ft_atof(tokens[3]) / 2.0;
	obj->shape.cylinder.height = ft_atof(tokens[4]);
	set_color_from_str(tokens[5], &obj->color);
	obj_add_back(&scene->objects, obj);
	return (NO_ERROR);
}
