#include "app.h"
#include <stdlib.h>

static void	free_objects(t_object *object)
{
	t_object	*next;

	while (object)
	{
		next = object->next;
		free(object);
		object = next;
	}
}

void	app_cleanup(t_app *app)
{
	platform_destroy(&app->platform);
	image_destroy(&app->image);
	free_objects(app->scene.objects);
	app->scene.objects = NULL;
}
