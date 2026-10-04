/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 12:17:30 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/04 21:07:45 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"
# include "parser.h"
# include "utils.h"
# include "calc_vector.h"
# include "mlx_utils.h"
# include "calc.h"
# include "scene.h"
# include "object.h"
# include "vec3.h"

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

# define EPSILON	1e-6
# define M_PI 		3.14159265358979323846

# define WIDTH 	800
# define HEIGHT 600

# define KEY_ESC 65307

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

// just for test

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_scene		scene; // 一旦なんとかするために追加
}	t_vars;

#endif
