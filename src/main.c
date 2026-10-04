/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 10:03:19 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/04 16:38:23 by yurishik         ###   ########.fr       */
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
int	validate_rt(const char *filename, t_scene *scene)
{
	char				**lines;
	t_element_counts	counts;

	lines = read_valid_lines(filename);
	if (!lines)
		return (print_error("Failed to read file"));
	if (validate_structure(lines, &counts) == HAS_ERROR
		|| validate_lines(lines, scene) == HAS_ERROR)
	{
		free_str_array(lines);
		return (HAS_ERROR);
	}
	free_str_array(lines);
	return (NO_ERROR);
}

static void	free_scene(t_scene *scene)
{
	t_object	*curr;
	t_object	*next;

	if (!scene)
		return ;
	curr = scene->objects;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	scene->objects = NULL;
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (check_args(argc, argv) == HAS_ERROR)
		return (1);
	ft_bzero(&vars.scene, sizeof(t_scene));
	if (validate_rt(argv[1], &vars.scene) == HAS_ERROR)
	{
		free_scene(&vars.scene);
		return (1);
	}
	print_scene_for_debug(&vars.scene);
	if (!init_mlx(&vars))
		return (1);
	render(&vars);
	start_mlx_loop(&vars);
	free_scene(&vars.scene);
	return (0);
}
