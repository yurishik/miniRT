/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 14:14:23 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/04 15:56:23 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief identifierごとに適切なバリデーションの関数に飛ばす
 * 
 * @param トークン化された1行
 * @return HAS_ERROR/NO_ERROR
 */
static int	validate_identifier(char **tokens)
{
	if (ft_strcmp(tokens[0], ID_AMBIENT) == 0)
		return (validate_ambient(tokens));
	else if (ft_strcmp(tokens[0], ID_CAMERA) == 0)
		return (validate_camera(tokens));
	else if (ft_strcmp(tokens[0], ID_LIGHT) == 0)
		return (validate_light(tokens));
	else if (ft_strcmp(tokens[0], ID_SPHERE) == 0)
		return (validate_sphere(tokens));
	else if (ft_strcmp(tokens[0], ID_PLANE) == 0)
		return (validate_plane(tokens));
	else if (ft_strcmp(tokens[0], ID_CYLINDER) == 0)
		return (validate_cylinder(tokens));
	return (print_error("Unknown identifier found"));
}

/**
 * @brief identifierごとに適切なsceneへの代入関数に飛ばす
 * 
 * @param トークン化された1行
 * @param t_scene構造体
 * @return HAS_ERROR/NO_ERROR
 */
static int	set_element_to_scene(char **tokens, t_scene *scene)
{
	if (ft_strcmp(tokens[0], ID_AMBIENT) == 0)
		set_ambient(tokens, &scene->ambient);
	else if (ft_strcmp(tokens[0], ID_CAMERA) == 0)
		set_camera(tokens, &scene->camera);
	else if (ft_strcmp(tokens[0], ID_LIGHT) == 0)
		set_light(tokens, &scene->light);
	else if (ft_strcmp(tokens[0], ID_SPHERE) == 0)
		return (set_sphere(tokens, scene));
	else if (ft_strcmp(tokens[0], ID_PLANE) == 0)
		return (set_plane(tokens, scene));
	else if (ft_strcmp(tokens[0], ID_CYLINDER) == 0)
		return (set_cylinder(tokens, scene));
	return (NO_ERROR);
}

/**
 * @brief トークン化して、識別子ごとに適切なvalidationを実行する
 * 
 * @param line 1行
 * @param t_scene構造体
 * @return HAS_ERROR/NO_ERROR
 */
static int	process_single_line(char *line, t_scene *scene)
{
	char	**tokens;
	int		status;

	tokens = ft_split_isspace(line);
	if (!tokens)
		return (print_error("Memory allocation failed"));
	if (!tokens[0])
	{
		free_str_array(tokens);
		return (NO_ERROR);
	}
	status = validate_identifier(tokens);
	if (status == HAS_ERROR)
	{
		free_str_array(tokens);
		return (HAS_ERROR);
	}
	status = set_element_to_scene(tokens, scene);
	free_str_array(tokens);
	return (status);
}

/**
 * @brief 全行をループして1行ずつトークン化し、バリデーションを行う、エラーがあったらそこで終了
 * 
 * @param 全行の配列
 * @param t_scene構造体
 * @return HAS_ERROR/NO_ERROR
 */
int	validate_lines(char **lines, t_scene *scene)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (process_single_line(lines[i], scene) == HAS_ERROR)
			return (HAS_ERROR);
		i++;
	}
	return (NO_ERROR);
}
