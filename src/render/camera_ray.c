/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 17:00:34 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/22 19:15:20 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "minirt.h"
#include <math.h>

t_ray	create_camera_ray(int x, int y, const t_camera *cam)
{
	t_ray	ray;
	double	viewport_width;
	double	viewport_height;
	double	screen_x;
	double	screen_y;

	viewport_width = 2.0 * tan((cam->fov * M_PI / 180.0) / 2.0);
	viewport_height = viewport_width * ((double)HEIGHT / WIDTH);
	screen_x = (((double)x / WIDTH) - 0.5) * viewport_width;
	screen_y = (0.5 - ((double)y / HEIGHT)) * viewport_height;
	ray.origin = cam->position;
	ray.direction = vec_normalize(
			vec_add(
				vec_add(cam->direction,
					vec_mult(cam->right, screen_x)
					),
				vec_mult(cam->up, screen_y)
				)
			);
	return (ray);
}

/**
 * @brief Generate a ray from the camera through pixel (x, y).
 * 
 * Map 2D pixel coordinates (x, y) to a viewport in 3D space,
 * accounting for the aspect ratio. Construct a ray from the camera
 * position (cam->position) with a normalized direction vector.
 * (Currently assumes the camera faces the positive Z axis (0, 0, 1).)
 *
 * @param x Horizontal pixel coordinate (0 to WIDTH - 1)
 * @param y Vertical pixel coordinate (0 to HEIGHT - 1)
 * @param cam Camera data (position, direction, viewport width, etc.)
 * @return Generated ray (origin and normalized direction vector)
 */
