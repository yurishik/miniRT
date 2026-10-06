#include "image.h"
#include <stdlib.h>

int	image_init(t_image *image, int width, int height)
{
	image->width = width;
	image->height = height;
	image->pixels = malloc(sizeof(int) * width * height);
	if (!image->pixels)
	{
		image->width = 0;
		image->height = 0;
		return (1);
	}
	return (0);
}

void	image_destroy(t_image *image)
{
	free(image->pixels);
	image->pixels = NULL;
	image->width = 0;
	image->height = 0;
}

void	image_set_pixel(t_image *image, int x, int y, int color)
{
	if (!image || !image->pixels)
		return ;
	if (x < 0 || y < 0 || x >= image->width || y >= image->height)
		return ;
	image->pixels[y * image->width + x] = color;
}
