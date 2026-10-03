#ifndef APP_H
# define APP_H

# include "scene.h"
# include "image.h"
# include "platform.h"

typedef struct s_app
{
	t_scene	scene;
	t_image		image;
	t_platform	platform;
}	t_app;

int		app_run(const char *filename);
void	app_cleanup(t_app *app);

#endif