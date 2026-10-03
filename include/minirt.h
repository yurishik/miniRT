/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 12:17:30 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/03 12:17:32 by yurishik         ###   ########.fr       */
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

# define WIDTH 800
# define HEIGHT 600

# define KEY_ESC 65307

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

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
typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	dir;
}	t_ray;

typedef struct s_ambient
{
	double	ratio;
	t_vec3	color;
}	t_ambient;

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	dir;
	double	viewport_width; // will be changed to fov
}	t_camera;

typedef struct s_light
{
	t_vec3	pos;
	double	brightness;
}	t_light;

typedef struct s_sphere
{
	t_vec3	center;
	double	radius;
	t_vec3	color;
}	t_sphere;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_ambient	ambient;
	t_camera	cam;
	t_sphere	sp;
	t_light		light;
}	t_vars;

#endif
