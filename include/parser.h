/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 10:03:14 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/06 20:13:26 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "scene.h"
# include "object.h"

# include <stddef.h>

typedef struct s_element_counts		t_element_counts;

// check_args.c
int		valid_extension(const char *filename, const char *ext);
int		check_args(int argc, char **argv);

// error.c
int		print_error(const char *msg);

// validate_chars.c
int		is_blank_line(const char *line);
int		is_allowed_char(char c);
int		is_valid_chars_line(const char *line);

// read_file.c
char	**read_valid_lines(const char *path);

// validate_structure.c
int		validate_structure(char **lines, t_element_counts *counts);

// validate_lines.c
int		validate_lines(char **lines, t_scene *scene);

// validate_format.c
int		is_valid_double_str(const char *str);
int		is_valid_int_str(const char *str);
int		is_valid_vector_format(const char *str);
int		is_valid_rgb_format(const char *str);
int		is_valid_orientation_format(const char *str);

// validate_a_c_l.c
size_t	count_tokens(char **tokens);
int		validate_ambient(char **tokens);
int		validate_camera(char **tokens);
int		validate_light(char **tokens);

// validate_sp_pl_cy.c
int		validate_sphere(char **tokens);
int		validate_plane(char **tokens);
int		validate_cylinder(char **tokens);

// set_utils.c
void	obj_add_back(t_object **head, t_object *new_obj);
void	set_vec3_from_str(char *str, t_vec3 *vec);
void	set_color_from_str(char *str, t_color *color);

// set_a_c_l.c
void	set_ambient(char **tokens, t_ambient *ambient);
void	set_camera(char **tokens, t_camera *camera);
void	set_light(char **tokens, t_light *light);

// set_sp_pl_cy.c
int		set_sphere(char **tokens, t_scene *scene);
int		set_plane(char **tokens, t_scene *scene);
int		set_cylinder(char **tokens, t_scene *scene);

//
int		parse_scene(t_scene *scene, const char *filename);

#endif
