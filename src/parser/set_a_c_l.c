/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_a_c_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 13:29:01 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/10 13:01:05 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_ambient(char **tokens, t_ambient *ambient)
{
	ambient->ratio = ft_atof(tokens[1]);
	set_color_from_str(tokens[2], &ambient->color);
}

/**
 * @brief カメラの情報からrightとupを計算して格納する
 *
 */
static void	calc_camera_right_up(t_camera *cam)
{
	t_vec3	world_up;

	cam->direction = vec_normalize(cam->direction);
	world_up = vec_new(0, 1, 0);
	cam->right = vec_cross(cam->direction, world_up);
	if (vec_length_squared(cam->right) < EPSILON)
	{
		world_up = vec_new(0, 0, 1);
		cam->right = vec_cross(world_up, cam->direction);
	}
	cam->right = vec_normalize(cam->right);
	cam->up = vec_normalize(vec_cross(cam->direction, cam->right));
}

void	set_camera(char **tokens, t_camera *camera)
{
	set_vec3_from_str(tokens[1], &camera->position);
	set_vec3_from_str(tokens[2], &camera->direction);
	camera->fov = ft_atof(tokens[3]);
	calc_camera_right_up(camera);
}

void	set_light(char **tokens, t_light *light)
{
	set_vec3_from_str(tokens[1], &light->position);
	light->brightness = ft_atof(tokens[2]);
	set_color_from_str(tokens[3], &light->color);
}
