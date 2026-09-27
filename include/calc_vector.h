/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_vector.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 19:40:55 by yurishik          #+#    #+#             */
/*   Updated: 2026/09/27 19:44:49 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALC_VECTOR_H
# define CALC_VECTOR_H

typedef struct s_vec3	t_vec3;

// vec_basic.c
t_vec3	vec_new(double x, double y, double z);
t_vec3	vec_negate(t_vec3 v);

// vec_scolar.c
t_vec3	vec_mult(t_vec3 v, double k);
t_vec3	vec_div(t_vec3 v, double k);

// vec_vec.c
t_vec3	vec_add(t_vec3 v1, t_vec3 v2);
t_vec3	vec_sub(t_vec3 v1, t_vec3 v2);
t_vec3	vec_mult_vec(t_vec3 v1, t_vec3 v2);
double	vec_dot(t_vec3 v1, t_vec3 v2);
t_vec3	vec_cross(t_vec3 v1, t_vec3 v2);

// vec_length.c
double	vec_length_squared(t_vec3 v);
double	vec_length(t_vec3 v);
t_vec3	vec_normalize(t_vec3 v);

#endif
