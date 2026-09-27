/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 10:07:11 by yurishik          #+#    #+#             */
/*   Updated: 2026/09/28 00:31:50 by hisasano         ###   ########.fr       */
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

# include "math.h"
# include "color.h"
# include "object.h"
# include "scene.h"

# define TRUE 		1
# define FALSE 		0
# define NO_ERROR 	0
# define HAS_ERROR 	1

# define ID_AMBIENT   "A"
# define ID_CAMERA    "C"
# define ID_LIGHT     "L"
# define ID_SPHERE    "sp"
# define ID_PLANE     "pl"
# define ID_CYLINDER  "cy"

# define MAX_COORD       100000.0
# define MIN_COORD      -100000.0
# define MAX_DIMENSION   100000.0
# define MIN_DIMENSION   0.0001
# define MIN_FOV         0
# define MAX_FOV         180
# define MIN_RATIO       0.0
# define MAX_RATIO       1.0
# define MIN_RGB	     0
# define MAX_RGB	     255
# define MIN_NORM_VEC   -1.0
# define MAX_NORM_VEC	 1.0

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
