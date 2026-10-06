/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 23:10:22 by hisasano          #+#    #+#             */
/*   Updated: 2026/10/05 22:03:07 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct s_image
{
	int		width;
	int		height;
	int		*pixels;
}	t_image;

int		image_init(t_image *image, int width, int height);
void	image_destroy(t_image *image);
void	image_set_pixel(t_image *image, int x, int y, int color);

#endif


// image_set_pixel
// (0,0) (1,0) (2,0) (3,0)
// (0,1) (1,1) (2,1) (3,1)

// メモリ

// pixels[0]
// pixels[1]
// pixels[2]
// pixels[3]
// pixels[4]
// pixels[5]
// pixels[6]  ← (2,1)
// pixels[7]
