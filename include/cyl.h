/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 17:33:37 by hisasano          #+#    #+#             */
/*   Updated: 2026/10/18 17:33:44 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYL_H
# define CYL_H

# include "scene.h"

double		cyl_side(t_ray ray, const t_cylinder *cy);
double		cyl_cap(t_ray ray, const t_cylinder *cy, t_vec3 cap_center);
t_cy_hit	cyl_nearest(double side, double top, double bottom);
t_vec3		cyl_normal(const t_cylinder *cy, t_vec3 point, t_cy_face face);

#endif
