/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 11:14:12 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/05 22:12:00 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "scene.h"

typedef struct s_element_counts	t_element_counts;

// utils.c
int		ft_isspace(int c);
char	*get_next_line_trim(int fd);
void	free_str_array(char **arr);
double	ft_atof(const char *str);

// utils_for_debug.c
void	print_str_array_for_debug(char **array);
void	print_vec3(const char *name, t_vec3 v);
void	print_element_counts_for_debug(const t_element_counts *counts);
void	print_scene_for_debug(t_scene *scene);
void	debug_print_ray(const char *tag, const t_ray *ray);
void	debug_print_sphere(const char *tag, const t_sphere *sp);
void	debug_print_hit(const char *tag, const t_hit *hit);

// splitting.c
char	**ft_split_isspace(const char *str);
char	**comma_split_elements(const char *str, int num);

#endif
