/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 12:46:20 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/04 17:58:45 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minirt.h"

/**
 * @brief 文字列配列を表示する
 *
 */
void	print_str_array_for_debug(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		ft_putendl_fd(array[i], STDOUT_FILENO);
		i++;
	}
}

static void	print_count_line(const char *label, int count)
{
	ft_putstr_fd("  ", 1);
	ft_putstr_fd((char *)label, 1);
	ft_putstr_fd(" : ", 1);
	ft_putnbr_fd(count, 1);
	ft_putstr_fd("\n", 1);
}

/**
 * @brief t_element_countsの中身をいい感じに表示する
 * 
 */
void	print_element_counts_for_debug(const t_element_counts *counts)
{
	if (!counts)
	{
		ft_putstr_fd("element_counts: (NULL)\n", 1);
		return ;
	}
	ft_putstr_fd("============== ELEMENT COUNTS ==============\n", 1);
	print_count_line("Ambient (A)  ", counts->ambient_count);
	print_count_line("Camera  (C)  ", counts->camera_count);
	print_count_line("Light   (L)  ", counts->light_count);
	ft_putstr_fd("  ------------------------------------------\n", 1);
	print_count_line("Sphere  (sp) ", counts->sphere_count);
	print_count_line("Plane   (pl) ", counts->plane_count);
	print_count_line("Cylinder(cy) ", counts->cylinder_count);
	ft_putstr_fd("  ------------------------------------------\n", 1);
	print_count_line("Total Objects", counts->total_objects);
	ft_putstr_fd("============================================\n", 1);
}

void	print_vec3(const char *name, t_vec3 v)
{
	printf("    %s: (%.2f, %.2f, %.2f)\n", name, v.x, v.y, v.z);
}

static void	print_color(const char *name, t_color c)
{
	printf("    %s: (%.2f, %.2f, %.2f)\n", name, c.r, c.g, c.b);
}

static void	print_single_object(int idx, t_object *obj)
{
	printf("  [%d] ", idx);
	if (obj->type == OBJ_SPHERE)
	{
		printf("Type: SPHERE\n");
		print_vec3("center", obj->shape.sphere.center);
		printf("    radius: %.2f\n", obj->shape.sphere.radius);
	}
	else if (obj->type == OBJ_PLANE)
	{
		printf("Type: PLANE\n");
		print_vec3("point", obj->shape.plane.point);
		print_vec3("normal", obj->shape.plane.normal);
	}
	else if (obj->type == OBJ_CYLINDER)
	{
		printf("Type: CYLINDER\n");
		print_vec3("center", obj->shape.cylinder.center);
		print_vec3("axis", obj->shape.cylinder.axis);
		printf("    radius: %.2f\n", obj->shape.cylinder.radius);
		printf("    height: %.2f\n", obj->shape.cylinder.height);
	}
	else
		printf("Type: UNKNOWN\n");
	print_color("color", obj->color);
}

static	void	print_objects(t_object *objects)
{
	t_object	*curr;
	int			i;

	i = 0;
	curr = objects;
	printf("--- Objects ---\n");
	if (!curr)
	{
		printf("    (No objects)\n");
		return ;
	}
	while (curr)
	{
		print_single_object(i++, curr);
		curr = curr->next;
	}
}

void	print_scene_for_debug(t_scene *scene)
{
	if (!scene)
	{
		printf("[DEBUG] Scene is NULL\n");
		return ;
	}
	printf("================= SCENE DEBUG =================\n");
	printf("--- Ambient (A) ---\n");
	printf("    ratio: %.2f\n", scene->ambient.ratio);
	print_color("color", scene->ambient.color);
	printf("--- Camera (C) ---\n");
	print_vec3("position", scene->camera.position);
	print_vec3("direction", scene->camera.direction);
	printf("    fov: %.2f\n", scene->camera.fov);
	printf("--- Light (L) ---\n");
	print_vec3("position", scene->light.position);
	printf("    brightness: %.2f\n", scene->light.brightness);
	print_color("color", scene->light.color);
	print_objects(scene->objects);
	printf("===============================================\n");
}

void	debug_print_ray(const char *tag, const t_ray *ray)
{
	if (!ray)
	{
		printf("[%s] Ray: (NULL)\n", tag);
		return ;
	}
	printf("[%s] Ray:\n", tag);
	printf("  origin:    (%.3f, %.3f, %.3f)\n",
		ray->origin.x, ray->origin.y, ray->origin.z);
	printf("  direction: (%.3f, %.3f, %.3f)\n",
		ray->direction.x, ray->direction.y, ray->direction.z);
}

void	debug_print_sphere(const char *tag, const t_sphere *sp)
{
	if (!sp)
	{
		printf("[%s] Sphere: (NULL)\n", tag);
		return ;
	}
	printf("[%s] Sphere (Geometry):\n", tag);
	printf("  center: (%.3f, %.3f, %.3f)\n",
		sp->center.x, sp->center.y, sp->center.z);
	printf("  radius: %.3f (diameter: %.3f)\n",
		sp->radius, sp->radius * 2.0);
}

void	debug_print_hit(const char *tag, const t_hit *hit)
{
	if (!hit)
	{
		printf("[%s] Hit: (NULL)\n", tag);
		return ;
	}
	printf("[%s] Hit Record:\n", tag);
	printf("  t:      %.4f\n", hit->t);
	printf("  point:  (%.3f, %.3f, %.3f)\n",
		hit->point.x, hit->point.y, hit->point.z);
	printf("  normal: (%.3f, %.3f, %.3f)\n",
		hit->normal.x, hit->normal.y, hit->normal.z);
	printf("  color:  (%.3f, %.3f, %.3f)\n",
		hit->color.r, hit->color.g, hit->color.b);
}
