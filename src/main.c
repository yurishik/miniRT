/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 10:03:19 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/01 14:20:35 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief .rtファイルのバリデーションを行う
 *
 * @param filename ファイル名
 * @param counts それぞれの要素の個数を保持する構造体
 * @return HAS_ERROR/NO_ERROR
 */
int	validate_rt(const char *filename, t_element_counts *counts)
{
	char	**lines;

	lines = read_valid_lines(filename);
	if (!lines)
		return (print_error("Failed to read file"));
	print_str_array_for_debug(lines);
	if (validate_structure(lines, counts) == HAS_ERROR
		|| validate_lines(lines) == HAS_ERROR)
		return (free_str_array(lines), HAS_ERROR);
	print_element_counts_for_debug(counts);
	free_str_array(lines);
	return (NO_ERROR);
}

/**
 * @brief 実験用: 固定値の設定
 *
 */
static void	setup_vars(t_vars *vars)
{
	vars->ambient.ratio = 0.1;
	vars->ambient.color = (t_vec3){0.0, 1.0, 0.0};
	vars->cam.pos = (t_vec3){0.0, 0.0, -5.0};
	vars->cam.pos = (t_vec3){0.0, 0.0, 1.0};
	vars->cam.viewport_width = 2.0;
	vars->sp.center = (t_vec3){0.0, 0.0, 5.0};
	vars->sp.radius = 2.0;
	vars->sp.color = (t_vec3){1.0, 1.0, 1.0};
	vars->light.pos = (t_vec3){5.0, 5.0, 0.0};
	vars->light.brightness = 1.0;
}

int	main(int argc, char **argv)
{
	t_vars				vars;
	t_element_counts	counts;

	if (check_args(argc, argv) == HAS_ERROR)
		return (1);
	if (validate_rt(argv[1], &counts) == HAS_ERROR)
		return (1);
	setup_vars(&vars);
	if (!init_mlx(&vars))
		return (1);
	render(&vars);
	start_mlx_loop(&vars);
	return (0);
}
