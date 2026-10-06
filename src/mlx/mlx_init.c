#include "platform.h"
#include "mlx.h"

int	platform_init(t_platform *platform, int width, int height)
{
	platform->mlx = mlx_init();
	if (!platform->mlx)
		return (1);
	platform->window = mlx_new_window(platform->mlx, width, height, "miniRT");
	if (!platform->window)
		return (1);
	platform->image.ptr = mlx_new_image(platform->mlx, width, height);
	if (!platform->image.ptr)
		return (1);
	platform->image.addr = mlx_get_data_addr(platform->image.ptr,
			&platform->image.bits_per_pixel, &platform->image.line_length,
			&platform->image.endian);
	if (!platform->image.addr)
		return (1);
	return (0);
}
