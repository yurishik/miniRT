/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 15:24:35 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/25 11:18:36 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"

/**
 * @brief Calculate each pixel to generate rendering data.
 *
 * @param Temporary structure for rendering data;
 * currently initialized with fixed values in main.c.
 */
int	render(const t_scene *scene, t_image *image)
{
	t_ray	ray;
	t_vec3	color;
	int		x;
	int		y;

	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			ray = create_camera_ray(x, y, &scene->camera);
			color = ray_color(ray, scene);
			image_set_pixel(image, x, y, color_to_int(color));
			x++;
		}
		y++;
	}
	return (0);
}

// render
//  ↓
// t_scene
//  ↓
// t_image
