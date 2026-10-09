/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 15:24:35 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/09 12:49:14 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"

/**
 * @brief 各ピクセルで計算して描画用のデータを作成する
 *
 * @param 描画用のデータの仮の構造体、一旦main.c内で固定値を設定している
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
