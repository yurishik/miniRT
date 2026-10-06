#ifndef RENDER_H
# define RENDER_H

# include "scene.h"
# include "image.h"

t_ray	create_camera_ray(int x, int y, const t_camera *camera);
int		hit_sphere(t_ray ray, const t_sphere *sphere, t_hit *hit);
int		find_nearest_hit(const t_scene *scene, t_ray ray, t_hit *hit);
t_vec3	compute_lighting(const t_scene *scene, const t_hit *hit);
t_vec3	ray_color(t_ray ray, const t_scene *scene);
int		color_to_int(t_vec3 color);
int		render(const t_scene *scene, t_image *image);

#endif
