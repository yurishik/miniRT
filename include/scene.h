#ifndef SCENE_H
# define SCENE_H

# include "math.h"
# include "color.h"
# include "object.h"

typedef struct s_light
{
	t_vec3	position;
	double	brightness;
	t_color	color;
}	t_light;
// L -40,0,30   0.7   255,255,255
//      │        │         │
//      │        │         └──→ light.r/g/b
//      │        │
//      │        └────────────→ light.brightness
//      │
//      └─────────────────────→ light.position

typedef struct s_camera
{
	t_vec3	position;
	t_vec3	direction;
	double	fov;
}	t_camera;
// C -50,0,20   0,0,1   70
//      │         │       │
//      │         │       └──→ camera.fov
//      │         │
//      │         └──────────→ camera.direction
//      │
//      └────────────────────→ camera.position


typedef struct s_scene
{
	double		ambient_ratio;
	t_color		ambient_color;
	t_camera	camera;
	t_light		light;
	t_object	*objects;
}	t_scene;
// A 0.2 255,255,255
//   │    │
//   │    └──────────────→ ambient_r/g/b
//   │
//   └───────────────────→ ambient_ratio

#endif
