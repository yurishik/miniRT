/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 22:48:14 by hisasano          #+#    #+#             */
/*   Updated: 2026/10/05 21:49:56 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

t_vec3	vec_new(double x, double y, double z);
t_vec3	vec_negate(t_vec3 v);
t_vec3	vec_clamp(t_vec3 v, double min, double max);
t_vec3	vec_mult(t_vec3 v, double k);
t_vec3	vec_div(t_vec3 v, double k);
t_vec3	vec_add(t_vec3 v1, t_vec3 v2);
t_vec3	vec_sub(t_vec3 v1, t_vec3 v2);
t_vec3	vec_mult_vec(t_vec3 v1, t_vec3 v2);
double	vec_dot(t_vec3 v1, t_vec3 v2);
t_vec3	vec_cross(t_vec3 v1, t_vec3 v2);
double	vec_length_squared(t_vec3 v);
double	vec_length(t_vec3 v);
t_vec3	vec_normalize(t_vec3 v);

#endif
