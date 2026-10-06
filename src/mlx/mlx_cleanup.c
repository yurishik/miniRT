#include "platform.h"
#include "mlx.h"
#include <stdlib.h>

void	platform_destroy(t_platform *platform)
{
	if (!platform)
		return ;
	if (platform->mlx && platform->image.ptr)
		mlx_destroy_image(platform->mlx, platform->image.ptr);
	if (platform->mlx && platform->window)
		mlx_destroy_window(platform->mlx, platform->window);
#ifdef __linux__
	if (platform->mlx)
	{
		mlx_destroy_display(platform->mlx);
		free(platform->mlx);
	}
#endif
	platform->image.ptr = NULL;
	platform->image.addr = NULL;
	platform->window = NULL;
	platform->mlx = NULL;
}
