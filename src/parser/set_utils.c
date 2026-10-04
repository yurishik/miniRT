/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 13:32:06 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/04 16:05:37 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief libftのft_lstadd_backみたいなののt_objectバージョン
 * 
 */
void	obj_add_back(t_object **head, t_object *new_obj)
{
	t_object	*curr;

	if (!head || !new_obj)
		return ;
	if (!*head)
	{
		*head = new_obj;
		return ;
	}
	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = new_obj;
}

void	set_vec3_from_str(char *str, t_vec3 *vec)
{
	char	**components;

	components = ft_split(str, ',');
	if (!components)
		return ;
	vec->x = ft_atof(components[0]);
	vec->y = ft_atof(components[1]);
	vec->z = ft_atof(components[2]);
	free_str_array(components);
}

void	set_color_from_str(char *str, t_color *color)
{
	char	**rgb;

	rgb = ft_split(str, ',');
	if (!rgb)
		return ;
	color->r = ft_atof(rgb[0]);
	color->g = ft_atof(rgb[1]);
	color->b = ft_atof(rgb[2]);
	free_str_array(rgb);
}
