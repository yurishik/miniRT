/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 10:07:11 by yurishik          #+#    #+#             */
/*   Updated: 2026/09/27 12:53:25 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# include "../libft/libft.h"
# include "get_next_line.h"
# include "parser.h"
# include "utils.h"

# define TRUE 1
# define FALSE 0
# define NO_ERROR 0
# define HAS_ERROR 1

# define ID_AMBIENT   "A"
# define ID_CAMERA    "C"
# define ID_LIGHT     "L"
# define ID_SPHERE    "sp"
# define ID_PLANE     "pl"
# define ID_CYLINDER  "cy"

typedef struct s_element_counts
{
	int	ambient_count;
	int	camera_count;
	int	light_count;
	int	sphere_count;
	int	plane_count;
	int	cylinder_count;
	int	total_objects;
}	t_element_counts;

#endif
