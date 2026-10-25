/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 17:11:30 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/25 11:40:49 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "platform.h"
#include "mlx.h"

/**
 * @brief Create image data for screen rendering based on so_long
 *
 */
static void	mlx_set_pixel(t_mlx_image *image, int x, int y, int color)
{
	char	*destination;

	destination = image->addr + y * image->line_length
		+ x * (image->bits_per_pixel / 8);
	*(unsigned int *)destination = (unsigned int)color;
}

void	platform_present(t_platform *platform, const t_image *image)
{
	int	x;
	int	y;

	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			mlx_set_pixel(&platform->image, x, y,
				image->pixels[y * image->width + x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(platform->mlx, platform->window,
		platform->image.ptr, 0, 0);
}

// void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
// 	*(unsigned int *)dst = color;
// }
