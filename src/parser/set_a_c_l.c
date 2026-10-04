/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_a_c_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 13:29:01 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/03 13:30:24 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_ambient(char **tokens, t_ambient *ambient)
{
	ambient->ratio = ft_atof(tokens[1]);
	set_color_from_str(tokens[2], &ambient->color);
}

void	set_camera(char **tokens, t_camera *camera)
{
	set_vec3_from_str(tokens[1], &camera->position);
	set_vec3_from_str(tokens[2], &camera->direction);
	camera->fov = ft_atof(tokens[3]);
}

void	set_light(char **tokens, t_light *light)
{
	set_vec3_from_str(tokens[1], &light->position);
	light->brightness = ft_atof(tokens[2]);
	set_color_from_str(tokens[3], &light->color);
}
