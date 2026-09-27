/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 12:46:20 by yurishik          #+#    #+#             */
/*   Updated: 2026/09/27 14:18:45 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief 文字列配列を表示する
 *
 */
void	print_str_array_for_debug(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		ft_putendl_fd(array[i], STDOUT_FILENO);
		i++;
	}
}

static void	print_count_line(const char *label, int count)
{
	ft_putstr_fd("  ", 1);
	ft_putstr_fd((char *)label, 1);
	ft_putstr_fd(" : ", 1);
	ft_putnbr_fd(count, 1);
	ft_putstr_fd("\n", 1);
}

/**
 * @brief t_element_countsの中身をいい感じに表示する
 * 
 */
void	print_element_counts_for_debug(const t_element_counts *counts)
{
	if (!counts)
	{
		ft_putstr_fd("element_counts: (NULL)\n", 1);
		return ;
	}
	ft_putstr_fd("============== ELEMENT COUNTS ==============\n", 1);
	print_count_line("Ambient (A)  ", counts->ambient_count);
	print_count_line("Camera  (C)  ", counts->camera_count);
	print_count_line("Light   (L)  ", counts->light_count);
	ft_putstr_fd("  ------------------------------------------\n", 1);
	print_count_line("Sphere  (sp) ", counts->sphere_count);
	print_count_line("Plane   (pl) ", counts->plane_count);
	print_count_line("Cylinder(cy) ", counts->cylinder_count);
	ft_putstr_fd("  ------------------------------------------\n", 1);
	print_count_line("Total Objects", counts->total_objects);
	ft_putstr_fd("============================================\n", 1);
}
