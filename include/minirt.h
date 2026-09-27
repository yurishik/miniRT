#ifndef MINIRT_H
# define MINIRT_H

typedef struct s_vec3 {
    double    x;
    double    y;
    double    z;
}    t_vec3;

typedef struct s_color
{
    int r;
    int g;
    int b;
}   t_color;

typedef struct s_ray
{
    t_vec3  origin;
    t_vec3  direction;
}   t_ray;

typedef struct s_light
{
	t_vec3	position;
	double	brightness;
	int		r;
	int		g;
	int		b;
}	t_light;


#endif