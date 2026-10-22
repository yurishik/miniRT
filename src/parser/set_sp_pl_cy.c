/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sp_pl_cy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 13:29:57 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/22 20:30:16 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Create a sphere object and add it to the scene.
 *
 * Converts the parsed center, diameter, and color into sphere data.
 *
 * @param tokens Parsed sphere parameters from the scene file.
 * @param scene Scene to which the new sphere is added.
 * @return NO_ERROR on success, or an error code on allocation failure.
 */
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

/**
 * @brief Create a plane object and add it to the scene.
 *
 * Sets the plane's point, normalized normal vector, and color.
 *
 * @param tokens Parsed plane parameters from the scene file.
 * @param scene Scene to which the new plane is added.
 * @return NO_ERROR on success, or an error code on allocation failure.
 */
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
	obj->shape.plane.normal = vec_normalize(obj->shape.plane.normal);
	set_color_from_str(tokens[3], &obj->color);
	obj_add_back(&scene->objects, obj);
	return (NO_ERROR);
}

/**
 * @brief Create a cylinder object and add it to the scene.
 *
 * Sets the center, normalized axis, radius, height, and color.
 *
 * @param tokens Parsed cylinder parameters from the scene file.
 * @param scene Scene to which the new cylinder is added.
 * @return NO_ERROR on success, or an error code on allocation failure.
 */
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
	obj->shape.cylinder.axis = vec_normalize(obj->shape.cylinder.axis);
	set_color_from_str(tokens[5], &obj->color);
	obj_add_back(&scene->objects, obj);
	return (NO_ERROR);
}
