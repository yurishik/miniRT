/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 19:40:55 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/04 16:36:37 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALC_H
# define CALC_H

typedef struct s_vec3	t_vec3;
typedef struct s_ray	t_ray;
typedef struct s_camera	t_camera;
typedef struct s_light	t_light;
typedef struct s_sphere	t_sphere;

// hit.c
int		hit_sphere(t_ray ray, const t_sphere *sp, t_hit *hit);

// ray.c
t_ray	create_camera_ray(int x, int y, const t_camera *cam);
t_vec3	ray_color(t_ray ray, const t_scene *scene);

#endif
