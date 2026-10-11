/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 20:13:40 by yurishik          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/10/10 20:55:59 by hisasano         ###   ########.fr       */
=======
/*   Updated: 2026/10/11 16:58:54 by yurishik         ###   ########.fr       */
>>>>>>> origin/dev_yurishik
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "image.h"
# include "scene.h"

t_ray	create_camera_ray(int x, int y, const t_camera *camera);
int		hit_sphere(t_ray ray, const t_sphere *sphere, t_hit *hit);
int		hit_plane(t_ray ray, const t_plane *plane, t_hit *hit);
<<<<<<< HEAD
int		hit_cylinder(t_ray ray, const t_cylinder *cy, t_hit *hit);
=======
>>>>>>> origin/dev_yurishik
int		find_nearest_hit(const t_scene *scene, t_ray ray, t_hit *hit);
t_vec3	compute_lighting(const t_scene *scene, const t_hit *hit);
t_vec3	ray_color(t_ray ray, const t_scene *scene);
int		color_to_int(t_vec3 color);
int		render(const t_scene *scene, t_image *image);

#endif
