/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 23:10:22 by hisasano          #+#    #+#             */
/*   Updated: 2026/10/25 11:42:27 by yurishik         ###   ########.fr       */
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
